/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: AGENT_SEND
 *** Description: Sends diagnostic data to the remote agent
 *** Version: 
 ***     1.0: 2019-01-09/badger - null - 
 *************************************************************************/

#ifndef _AGENT_SEND_H_
#define _AGENT_SEND_H_

#include <funcbloc.h>
#include <forte_lint.h>
#include <forte_bool.h>
#include <forte_real.h>
#include <forte_string.h>
#include <forte_int.h>
#include <forte_wstring.h>
#include <forte_lreal.h>

class FORTE_AGENT_SEND: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_AGENT_SEND)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_STRING &ADDRESS() {
    return *static_cast<CIEC_STRING*>(getDI(0));
  };

  CIEC_LINT &PORT() {
    return *static_cast<CIEC_LINT*>(getDI(1));
  };

  CIEC_INT &INST_ID() {
    return *static_cast<CIEC_INT*>(getDI(2));
  };

  CIEC_INT &DATA_TYPE() {
    return *static_cast<CIEC_INT*>(getDI(3));
  };

  CIEC_INT &DATA_INT() {
    return *static_cast<CIEC_INT*>(getDI(4));
  };

  CIEC_LINT &DATA_LINT() {
    return *static_cast<CIEC_LINT*>(getDI(5));
  };

  CIEC_REAL &DATA_REAL() {
    return *static_cast<CIEC_REAL*>(getDI(6));
  };

  CIEC_LREAL &DATA_LREAL() {
    return *static_cast<CIEC_LREAL*>(getDI(7));
  };

  CIEC_STRING &DATA_STRING() {
    return *static_cast<CIEC_STRING*>(getDI(8));
  };

  CIEC_WSTRING &DATA_WSTRING() {
    return *static_cast<CIEC_WSTRING*>(getDI(9));
  };

  CIEC_BOOL &DATA_BOOL() {
    return *static_cast<CIEC_BOOL*>(getDI(10));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(1, 11, 0, 0);

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_AGENT_SEND){
  };

  virtual ~FORTE_AGENT_SEND(){};

};

#endif //close the ifdef sequence from the beginning of the file

