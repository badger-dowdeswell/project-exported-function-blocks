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

#ifndef _T_SENSOR_H_
#define _T_SENSOR_H_

#include <basicfb.h>
#include <forte_real.h>
#include <forte_int.h>

class FORTE_T_SENSOR: public CBasicFB{
  DECLARE_FIRMWARE_FB(FORTE_T_SENSOR)

private:
  static const CStringDictionary::TStringId scm_anDataInputNames[];
  static const CStringDictionary::TStringId scm_anDataInputTypeIds[];
  CIEC_REAL &HI() {
    return *static_cast<CIEC_REAL*>(getDI(0));
  };

  CIEC_REAL &LO() {
    return *static_cast<CIEC_REAL*>(getDI(1));
  };

  static const CStringDictionary::TStringId scm_anDataOutputNames[];
  static const CStringDictionary::TStringId scm_anDataOutputTypeIds[];
  CIEC_REAL &TEMP() {
    return *static_cast<CIEC_REAL*>(getDO(0));
  };

  static const TEventID scm_nEventINITID = 0;
  static const TEventID scm_nEventREQID = 1;
  static const TForteInt16 scm_anEIWithIndexes[];
  static const TDataIOID scm_anEIWith[];
  static const CStringDictionary::TStringId scm_anEventInputNames[];

  static const TEventID scm_nEventINITOID = 0;
  static const TEventID scm_nEventREQOID = 1;
  static const TForteInt16 scm_anEOWithIndexes[];
  static const TDataIOID scm_anEOWith[];
  static const CStringDictionary::TStringId scm_anEventOutputNames[];

  static const CStringDictionary::TStringId scm_anInternalsNames[];
  static const CStringDictionary::TStringId scm_anInternalsTypeIds[];
  CIEC_INT &temperatureDirection() {
    return *static_cast<CIEC_INT*>(getVarInternal(0));
  };

  static const SFBInterfaceSpec scm_stFBInterfaceSpec;


  static const SInternalVarsInformation scm_stInternalVars;

   FORTE_BASIC_FB_DATA_ARRAY(2, 2, 1, 1, 0);

virtual void setInitialValues();
  void alg_initialize(void);
  void alg_sample(void);
  static const TForteInt16 scm_nStateSTART = 0;
  static const TForteInt16 scm_nStateInit = 1;
  static const TForteInt16 scm_nStateSAMPLE = 2;
  static const TForteInt16 scm_nStateInitialized = 3;

  void enterStateSTART(void);
  void enterStateInit(void);
  void enterStateSAMPLE(void);
  void enterStateInitialized(void);

  virtual void executeEvent(int pa_nEIID);

public:
  FORTE_T_SENSOR(CStringDictionary::TStringId pa_nInstanceNameId, CResource *pa_poSrcRes) : 
       CBasicFB(pa_poSrcRes, &scm_stFBInterfaceSpec, pa_nInstanceNameId,
           &scm_stInternalVars, m_anFBConnData, m_anFBVarsData){
  };

  virtual ~FORTE_T_SENSOR(){};

};

#endif //close the ifdef sequence from the beginning of the file

