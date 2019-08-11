/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: AGENT_LISTENER
 *** Description: Agent Listener Service Interface Function Block
 *** Version: 
 ***     1.0: 2018-12-20/badger - null - null
 *************************************************************************/

#ifndef _AGENT_LISTENER_H_
#define _AGENT_LISTENER_H_

#include <funcbloc.h>
#include <forte_lint.h>
#include <forte_real.h>
#include <forte_string.h>

class FORTE_AGENT_LISTENER: public CFunctionBlock{
  DECLARE_FIRMWARE_FB(FORTE_AGENT_LISTENER)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_LINT &PORT() {
    return *static_cast<CIEC_LINT*>(getDI(0));
  };

  CIEC_STRING &ADDRESS() {
    return *static_cast<CIEC_STRING*>(getDI(1));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_REAL &DIAG_VALUE() {
    return *static_cast<CIEC_REAL*>(getDO(0));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventREQOID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(1, 2, 1, 0);

  void executeEvent(int pa_nEIID);

public:
  FUNCTION_BLOCK_CTOR(FORTE_AGENT_LISTENER){
  };

  virtual ~FORTE_AGENT_LISTENER(){};

};

#endif //close the ifdef sequence from the beginning of the file

