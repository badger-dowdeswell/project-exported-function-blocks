/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: AGENT3
 *** Description: Listener/exerciser diagnostic function block
 *** Version: 
 ***     1.0: 2018-12-19/badger - null - 
 *************************************************************************/

#include "AGENT3.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "AGENT3_gen.cpp"
#endif
#include "AGENT3_library.cpp"

DEFINE_FIRMWARE_FB(FORTE_AGENT3, g_nStringIdAGENT3)

const CStringDictionary::TStringId FORTE_AGENT3::scm_anDataInputNames[] = {g_nStringIdPORT, g_nStringIdADDRESS};

const CStringDictionary::TStringId FORTE_AGENT3::scm_anDataInputTypeIds[] = {g_nStringIdLINT, g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_AGENT3::scm_anDataOutputNames[] = {g_nStringIdDIAG_VALUE};

const CStringDictionary::TStringId FORTE_AGENT3::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FORTE_AGENT3::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_AGENT3::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_AGENT3::scm_anEventInputNames[] = {g_nStringIdINIT};

const TDataIOID FORTE_AGENT3::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_AGENT3::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_AGENT3::scm_anEventOutputNames[] = {g_nStringIdREQO};

const SFBInterfaceSpec FORTE_AGENT3::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void FORTE_AGENT3::alg_initialize(void){

cout << "Initialise" << "\n";

}


void FORTE_AGENT3::enterStateSTART(void){

	cout << "StateStart\n";
  m_nECCState = scm_nStateSTART;
}

void FORTE_AGENT3::enterStateInit(void){
  m_nECCState = scm_nStateInit;
  alg_initialize();
}

void FORTE_AGENT3::enterStateInitialized(void){
  m_nECCState = scm_nStateInitialized;
}

void FORTE_AGENT3::executeEvent(int pa_nEIID){
	cout << scm_nEventINITID << " " << pa_nEIID << "\n";

  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(scm_nEventINITID == pa_nEIID)
          enterStateInit();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInit:
        if(1)
          enterStateInitialized();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInitialized:
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 2.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


