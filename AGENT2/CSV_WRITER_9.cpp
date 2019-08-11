/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: CSV_WRITER_9
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     1.0: 2012-06-16/Alois Zoitl - ACIN - 
 *************************************************************************/

#include "CSV_WRITER_9.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "CSV_WRITER_9_gen.cpp"
#endif

DEFINE_FIRMWARE_FB(FORTE_CSV_WRITER_9, g_nStringIdCSV_WRITER_9)

const CStringDictionary::TStringId FORTE_CSV_WRITER_9::scm_anDataInputNames[] = {g_nStringIdQI, g_nStringIdFILE_NAME, g_nStringIdSD_1, g_nStringIdSD_2, g_nStringIdSD_3, g_nStringIdSD_4, g_nStringIdSD_5, g_nStringIdSD_6, g_nStringIdSD_7, g_nStringIdSD_8, g_nStringIdSD_9};

const CStringDictionary::TStringId FORTE_CSV_WRITER_9::scm_anDataInputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING, g_nStringIdANY, g_nStringIdANY, g_nStringIdANY, g_nStringIdANY, g_nStringIdANY, g_nStringIdANY, g_nStringIdANY, g_nStringIdANY, g_nStringIdANY};

const CStringDictionary::TStringId FORTE_CSV_WRITER_9::scm_anDataOutputNames[] = {g_nStringIdQO, g_nStringIdSTATUS};

const CStringDictionary::TStringId FORTE_CSV_WRITER_9::scm_anDataOutputTypeIds[] = {g_nStringIdBOOL, g_nStringIdSTRING};

const TForteInt16 FORTE_CSV_WRITER_9::scm_anEIWithIndexes[] = {0, 3};
const TDataIOID FORTE_CSV_WRITER_9::scm_anEIWith[] = {0, 1, 255, 0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 255};
const CStringDictionary::TStringId FORTE_CSV_WRITER_9::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_CSV_WRITER_9::scm_anEOWith[] = {0, 1, 255, 0, 1, 255};
const TForteInt16 FORTE_CSV_WRITER_9::scm_anEOWithIndexes[] = {0, 3, -1};
const CStringDictionary::TStringId FORTE_CSV_WRITER_9::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdCNF};

const SFBInterfaceSpec FORTE_CSV_WRITER_9::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  11,  scm_anDataInputNames, scm_anDataInputTypeIds,
  2,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};


void FORTE_CSV_WRITER_9::executeEvent(int pa_nEIID){
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



