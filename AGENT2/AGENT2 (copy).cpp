/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: AGENT2
 *** Description: Template for a simple Basic Function Block Type
 *** Version: 
 ***     1.0: 2018-12-05/badger - null - 
 *************************************************************************/

#include "AGENT2.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "AGENT2_gen.cpp"
#endif

#include "AGENT2_library.cpp"

DEFINE_FIRMWARE_FB(FORTE_AGENT2, g_nStringIdAGENT2)

const CStringDictionary::TStringId FORTE_AGENT2::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId FORTE_AGENT2::scm_anDataInputTypeIds[] = {g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_AGENT2::scm_anDataOutputNames[] = {g_nStringIdDATA};

const CStringDictionary::TStringId FORTE_AGENT2::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FORTE_AGENT2::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_AGENT2::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_AGENT2::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_AGENT2::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_AGENT2::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_AGENT2::scm_anEventOutputNames[] = {g_nStringIdREQO};

const SFBInterfaceSpec FORTE_AGENT2::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

//
// FORTE_AGENT2::alg_hasData()
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~
void FORTE_AGENT2::alg_hasData(void){

	//char *msg = "\n"; //"alg_hasData() has data IN()= \r\n";
	string msg = to_string(IN()) + "\n";	
		
	cout << "alg_hasData : " << to_string(IN()) << "\n";
		
	if (!isInitialised) {
		port = 62500;
		isInitialised = createConnection("127.0.0.1", port);
	}	
	
	if (isInitialised) { 
		// Connected so send the data
		//send(sock, msg, strlen(msg), 0);
		//send(sock, msg2.c_str(), msg2.length(), 0);
		sendPacket(msg);
		perror("sent data\n");
	}

	// Ensure the data passes through the SIFB transparently
	DATA() = IN();
}

//
//
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


