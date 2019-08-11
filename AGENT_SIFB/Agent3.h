/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: Agent3
 *** Description: Listener/exerciser diagnostic function block
 *** Version: 
 ***     1.0: 2018-12-19/badger - null - 
 *************************************************************************/

#ifndef _AGENT3_H_
#define _AGENT3_H_

#include <basicfb.h>
#include <forte_lint.h>
#include <forte_string.h>
#include <forte_lreal.h>

class FORTE_Agent3: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_Agent3)

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
  CIEC_LREAL &DIAG_VALUE() {
    return *static_cast<CIEC_LREAL*>(getDO(0));
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

   FORTE_BASIC_FB_DATA_ARRAY(1, 2, 1, 0, 0);
  void alg_initialize(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateInit = 1;
  static const TForteInt16 scm_nStateInitialized = 2;

  void enterStateSTART(void);
  void enterStateInit(void);
  void enterStateInitialized(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_Agent3(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_Agent3(){};

};

#endif //close the ifdef sequence from the beginning of the file

