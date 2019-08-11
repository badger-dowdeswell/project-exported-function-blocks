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

#ifndef _AGENT2_H_
#define _AGENT2_H_

#include <basicfb.h>
#include <forte_real.h>

class FORTE_AGENT2: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_AGENT2)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &IN() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_REAL &DATA() {
    return *static_cast<CIEC_REAL*>(getDO(0));
  };

  static const TEventID scm_nEventREQID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventREQOID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_BASIC_FB_DATA_ARRAY(1, 1, 1, 0, 0);
  void alg_hasData(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStatehasData = 1;

  void enterStateSTART(void);
  void enterStatehasData(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_AGENT2(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_AGENT2(){};

};

#endif //close the ifdef sequence from the beginning of the file

