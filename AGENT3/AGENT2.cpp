/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: AGENT2
 *** Description: Diagnostic Agent Service Interface Function Block.
 *** Version: 
 ***     1.0: 2018-12-05/badger - null - 
 *************************************************************************/

#include "AGENT2.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "AGENT2_gen.cpp"
#endif
#include "AGENT2_library.cpp"

DEFINE_FIRMWARE_FB(FORTE_AGENT2, g_nStringIdAGENT2)

const CStringDictionary::TStringId FORTE_AGENT2::scm_anDataInputNames[] = {g_nStringIdIN, g_nStringIdPORT, g_nStringIdADDRESS};

const CStringDictionary::TStringId FORTE_AGENT2::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdLINT, g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_AGENT2::scm_anDataOutputNames[] = {g_nStringIdDATA, g_nStringIdOUTSTRING};

const CStringDictionary::TStringId FORTE_AGENT2::scm_anDataOutputTypeIds[] = {g_nStringIdREAL, g_nStringIdSTRING};

const TForteInt16 FORTE_AGENT2::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_AGENT2::scm_anEIWith[] = {0, 1, 2, 255};
const CStringDictionary::TStringId FORTE_AGENT2::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_AGENT2::scm_anEOWith[] = {0, 255, 1, 255};
const TForteInt16 FORTE_AGENT2::scm_anEOWithIndexes[] = {0, 2};
const CStringDictionary::TStringId FORTE_AGENT2::scm_anEventOutputNames[] = {g_nStringIdREQO};

const SFBInterfaceSpec FORTE_AGENT2::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_AGENT2::alg_hasData(void){


	//char *msg = "\n"; //"alg_hasData() has data IN()= \r\n";
	string msg = to_string(IN()) + "\n";	
		
	cout << "alg_hasData : " << to_string(IN()) << "\n";
	
	if (!isInitialised) {
		port = PORT();
		const char * ptr_address = "127.0.0.1";
				
		char hostAddress[32] = {0};
		ADDRESS().toString(hostAddress, 32);
		
		// temporary fix...
		for(int ptr = 1; ptr <= 9; ptr++) {
			hostAddress[ptr - 1] = hostAddress[ptr];
		}
		hostAddress[9] = '\0';
		cout << "check string [" << hostAddress << "] [" << hostAddress[0]  << "]\n";
		// temporary fix ...
					
		isInitialised = createConnection(ptr_address, port);
	}	
	
	if (isInitialised) { 
		// Connected so send the data
		sendPacket(msg);
		perror("sent data\n");
	}

	// Ensure the data passes through the SIFB transparently
	DATA() = IN();
}


void FORTE_AGENT2::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_AGENT2::enterStatehasData(void){
  m_nECCState = scm_nStatehasData;
  alg_hasData();
  sendOutputEvent( scm_nEventREQOID);
}

void FORTE_AGENT2::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventREQID == pa_nEIID)
          enterStatehasData();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStatehasData:
        if(1)
          enterStateSTART();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 1.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


