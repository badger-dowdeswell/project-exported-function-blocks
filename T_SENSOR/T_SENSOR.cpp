/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: T_SENSOR
 *** Description: Temperature sensor
 *** Version: 
 ***     1.0: 2018-12-07/badger - AUT SERL EMSOFT - Original version
 *************************************************************************/

#include "T_SENSOR.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "T_SENSOR_gen.cpp"
#endif
#include "diags.h"

DEFINE_FIRMWARE_FB(FORTE_T_SENSOR, g_nStringIdT_SENSOR)

const CStringDictionary::TStringId FORTE_T_SENSOR::scm_anDataInputNames[] = {g_nStringIdHI, g_nStringIdLO};

const CStringDictionary::TStringId FORTE_T_SENSOR::scm_anDataInputTypeIds[] = {g_nStringIdREAL, g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_T_SENSOR::scm_anDataOutputNames[] = {g_nStringIdTEMP};

const CStringDictionary::TStringId FORTE_T_SENSOR::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FORTE_T_SENSOR::scm_anEIWithIndexes[] = {0, 3};
const TDataIOID FORTE_T_SENSOR::scm_anEIWith[] = {0, 1, 255, 0, 1, 255};
const CStringDictionary::TStringId FORTE_T_SENSOR::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_T_SENSOR::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_T_SENSOR::scm_anEOWithIndexes[] = {-1, 0, -1};
const CStringDictionary::TStringId FORTE_T_SENSOR::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdREQO};

const CStringDictionary::TStringId FORTE_T_SENSOR::scm_anInternalsNames[] = {g_nStringIdtemperatureDirection};

const CStringDictionary::TStringId FORTE_T_SENSOR::scm_anInternalsTypeIds[] = {g_nStringIdINT};

const SFBInterfaceSpec FORTE_T_SENSOR::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


const SInternalVarsInformation FORTE_T_SENSOR::scm_stInternalVars = {1, scm_anInternalsNames, scm_anInternalsTypeIds};


void FORTE_T_SENSOR::setInitialValues(){
  HI() = 100;
  LO() = 20;
  temperatureDirection() = 1;
}

void FORTE_T_SENSOR::alg_initialize(void){

std::cout << "initialize\n";

srand(  (unsigned int)   time(NULL)   );

temperatureDirection() = 1;
srand(  (unsigned int)   TForteInt8(time(NULL))   );

if  (HI() > 0) {
	TEMP() = HI() / 2;
} else {
    if  (LO() > 0) {
			TEMP() = LO();
	 } else { 
        	TEMP() = 0;          
 	}
}


}

void FORTE_T_SENSOR::alg_sample(void){

float tempDifference = 0;

std::cout << "sample\n";

tempDifference = (static_cast<TForteFloat>(rand())/static_cast<TForteFloat>(RAND_MAX) ) * 10;  
std::cout << "temperature difference =" << std::to_string(tempDifference) << "\n";

tempDifference = tempDifference * temperatureDirection();
temperatureDirection() = -temperatureDirection();

TEMP() = TEMP() + tempDifference;
if (TEMP() > HI() ) {
	TEMP() = HI() - tempDifference;
    temperatureDirection() = -1;
} else if (TEMP() < LO() ) {
	TEMP() = LO();
    temperatureDirection() = 1;
}


}


void FORTE_T_SENSOR::enterStateSTART(void){
  m_nECCState = scm_nStateSTART;
}

void FORTE_T_SENSOR::enterStateInit(void){
  m_nECCState = scm_nStateInit;
  alg_initialize();
  sendOutputEvent( scm_nEventINITOID);
}

void FORTE_T_SENSOR::enterStateSAMPLE(void){
  m_nECCState = scm_nStateSAMPLE;
  alg_sample();
  sendOutputEvent( scm_nEventREQOID);
}

void FORTE_T_SENSOR::enterStateInitialized(void){
  m_nECCState = scm_nStateInitialized;
}

void FORTE_T_SENSOR::executeEvent(int pa_nEIID){
  bool bTransitionCleared;
  do{
    bTransitionCleared = true;
    switch(m_nECCState){
      case scm_nStateSTART:
        if(1)
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
      case scm_nStateSAMPLE:
        if(1)
          enterStateInitialized();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      case scm_nStateInitialized:
        if(scm_nEventREQID == pa_nEIID)
          enterStateSAMPLE();
        else
          bTransitionCleared  = false; //no transition cleared
        break;
      default:
      DEVLOG_ERROR("The state is not in the valid range! The state value is: %d. The max value can be: 3.", m_nECCState.operator TForteUInt16 ());
        m_nECCState = 0; //0 is always the initial state
        break;
    }
    pa_nEIID = cg_nInvalidEventID;  // we have to clear the event after the first check in order to ensure correct behavior
  }while(bTransitionCleared);
}


