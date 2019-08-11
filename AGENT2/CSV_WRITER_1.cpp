/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: CSV_WRITER_1
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     1.0: 2012-06-16/Alois Zoitl - ACIN - 
 *************************************************************************/

#include "CSV_WRITER_1.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "CSV_WRITER_1_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_CSV_WRITER_1, g_nStringIdCSV_WRITER_1)

const CStringDictionary::TStringId FORTE_CSV_WRITER_1::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdFILE_NAME, g_nStringIdSD_1};

const CStringDictionary::TStringId FORTE_CSV_WRITER_1::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdANY};

const CStringDictionary::TStringId FORTE_CSV_WRITER_1::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdSTATUS};

const CStringDictionary::TStringId FORTE_CSV_WRITER_1::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING};

const TForteInt16 FORTE_CSV_WRITER_1::scm_anEIWithIndexes[] = {0, 3};
const TDataIOID FORTE_CSV_WRITER_1::scm_anEIWith[] = {0, 1, 255, 0, 2, 255};
const CStringDictionary::TStringId FORTE_CSV_WRITER_1::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_CSV_WRITER_1::scm_anEOWith[] = {0, 1, 255, 0, 1, 255};
const TForteInt16 FORTE_CSV_WRITER_1::scm_anEOWithIndexes[] = {0, 3, -1};
const CStringDictionary::TStringId FORTE_CSV_WRITER_1::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_CSV_WRITER_1::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_CSV_WRITER_1::executeEvent(int pa_nEIID){
  switch(pa_nEIID){
    case scm_nEventINITID:
#error add code for INIT event!
/*
  do not forget to send output event, calling e.g.
      sendOutputEvent(scm_nEventCNFID);
*/
      break;
    case scm_nEventREQID:
#error add code for REQ event!
/*
  do not forget to send output event, calling e.g.
      sendOutputEvent(scm_nEventCNFID);
*/
      break;
  }
}



