/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: F_TO_C_CONV
 *** Description: Template for a Simple Function Block Type
 *** Version: 
 ***     1.0: 2018-12-03/badger - null - 
 *************************************************************************/

#include "F_TO_C_CONV.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "F_TO_C_CONV_gen.cpp"
#endif

#include <iostream>
#include <string>

DEFINE_FIRMWARE_FB(FORTE_F_TO_C_CONV, g_nStringIdF_TO_C_CONV)

const CStringDictionary::TStringId FORTE_F_TO_C_CONV::scm_anDataInputNames[] = {g_nStringIdIN};

const CStringDictionary::TStringId FORTE_F_TO_C_CONV::scm_anDataInputTypeIds[] = {g_nStringIdREAL};

const CStringDictionary::TStringId FORTE_F_TO_C_CONV::scm_anDataOutputNames[] = {g_nStringIdOUT, g_nStringIdERROR};

const CStringDictionary::TStringId FORTE_F_TO_C_CONV::scm_anDataOutputTypeIds[] = {g_nStringIdREAL, g_nStringIdBOOL};

const TForteInt16 FORTE_F_TO_C_CONV::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_F_TO_C_CONV::scm_anEIWith[] = {0, 255};
const CStringDictionary::TStringId FORTE_F_TO_C_CONV::scm_anEventInputNames[] = {g_nStringIdREQ};

const TDataIOID FORTE_F_TO_C_CONV::scm_anEOWith[] = {0, 1, 255};
const TForteInt16 FORTE_F_TO_C_CONV::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_F_TO_C_CONV::scm_anEventOutputNames[] = {g_nStringIdCNF};

const SFBInterfaceSpec FORTE_F_TO_C_CONV::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  1,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_F_TO_C_CONV::setInitialValues(){
  std::cout << "setInitialValues()\n";
  IN() = 0.00;
  OUT() = 0.00;
  ERROR() = false;
  // this is a check comment
  IN() = 0.00;
}

void FORTE_F_TO_C_CONV::alg_REQ(void){
	//std::cout << "alg_REQ\n";
	ERROR() = false;
	OUT() = ((IN()-32))*5/9;
        // std::cout << "OUT() = " << std::to_string(OUT()) << "\n";
	if((((OUT() < -273)))){
		ERROR() = true;
	};
        IN() = IN() + 1;	
}



