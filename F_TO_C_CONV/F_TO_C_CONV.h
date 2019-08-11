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

#ifndef _F_TO_C_CONV_H_
#define _F_TO_C_CONV_H_

#include <simplefb.h>
#include <forte_bool.h>
#include <forte_real.h>

class FORTE_F_TO_C_CONV: public CSimpleFB{
  DECLARE_FIRMWARE_FB(FORTE_F_TO_C_CONV)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &IN() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_REAL &OUT() {
    return *static_cast<CIEC_REAL*>(getDO(0));
  };

  CIEC_BOOL &ERROR() {
    return *static_cast<CIEC_BOOL*>(getDO(1));
  };

  static const TEventID scm_nEventREQID = 0;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventCNFID = 0;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;

   FORTE_FB_DATA_ARRAY(1, 1, 2, 0);

virtual void setInitialValues();
  void alg_REQ(void);

public:
  FORTE_F_TO_C_CONV(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CSimpleFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
              0, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_F_TO_C_CONV(){};

};

#endif //close the ifdef sequence from the beginning of the file

