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

#ifndef _CSV_WRITER_9_H_
#define _CSV_WRITER_9_H_

#include <funcbloc.h>
#include <forte_bool.h>
#include <forte_string.h>
#include <forte_any.h>

#ERROR type contains variables of type ANY. Please check the usage of these variables as we can not gurantee correct usage on export!


class FORTE_CSV_WRITER_9: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_CSV_WRITER_9)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_BOOL &QI() {
    return *static_cast<CIEC_BOOL*>(getDI(0));
  };

  CIEC_STRING &FILE_NAME() {
    return *static_cast<CIEC_STRING*>(getDI(1));
  };

  CIEC_ANY &SD_1() {
    return *static_cast<CIEC_ANY*>(getDI(2));
  };

  CIEC_ANY &SD_2() {
    return *static_cast<CIEC_ANY*>(getDI(3));
  };

  CIEC_ANY &SD_3() {
    return *static_cast<CIEC_ANY*>(getDI(4));
  };

  CIEC_ANY &SD_4() {
    return *static_cast<CIEC_ANY*>(getDI(5));
  };

  CIEC_ANY &SD_5() {
    return *static_cast<CIEC_ANY*>(getDI(6));
  };

  CIEC_ANY &SD_6() {
    return *static_cast<CIEC_ANY*>(getDI(7));
  };

  CIEC_ANY &SD_7() {
    return *static_cast<CIEC_ANY*>(getDI(8));
  };

  CIEC_ANY &SD_8() {
    return *static_cast<CIEC_ANY*>(getDI(9));
  };

  CIEC_ANY &SD_9() {
    return *static_cast<CIEC_ANY*>(getDI(10));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_BOOL &QO() {
    return *static_cast<CIEC_BOOL*>(getDO(0));
  };

  CIEC_STRING &STATUS() {
    return *static_cast<CIEC_STRING*>(getDO(1));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventCNFID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(2, 11, 2, 0);

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_CSV_WRITER_9){
  };

  virtual ~FORTE_CSV_WRITER_9(){};

};

#endif //close the ifdef sequence from the beginning of the file

