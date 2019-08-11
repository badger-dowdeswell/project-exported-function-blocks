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

#include "AGENT_SEND.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "AGENT_SEND_gen.cpp"
#endif

#include "AGENT_SEND_Library.cpp"

DEFINE_FIRMWARE_FB(FORTE_AGENT_SEND, g_nStringIdAGENT_SEND)

const CStringDictionary::TStringId FORTE_AGENT_SEND::scm_anDataInputNames[] = {g_nStringIdADDRESS, g_nStringIdPORT, g_nStringIdINST_ID, g_nStringIdDATA_TYPE, g_nStringIdDATA_INT, g_nStringIdDATA_LINT, g_nStringIdDATA_REAL, g_nStringIdDATA_LREAL, g_nStringIdDATA_STRING, g_nStringIdDATA_WSTRING, g_nStringIdDATA_BOOL};

const CStringDictionary::TStringId FORTE_AGENT_SEND::scm_anDataInputTypeIds[] = {g_nStringIdSTRING, g_nStringIdLINT, g_nStringIdINT, g_nStringIdINT, g_nStringIdINT, g_nStringIdLINT, g_nStringIdREAL, g_nStringIdLREAL, g_nStringIdSTRING, g_nStringIdWSTRING, g_nStringIdBOOL};

const TForteInt16 FORTE_AGENT_SEND::scm_anEIWithIndexes[] = {0, 5};
const TDataIOID FORTE_AGENT_SEND::scm_anEIWith[] = {0, 1, 3, 2, 255, 4, 5, 7, 8, 10, 6, 9, 255};
const CStringDictionary::TStringId FORTE_AGENT_SEND::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TForteInt16 FORTE_AGENT_SEND::scm_anEOWithIndexes[] = {-1, -1};
const CStringDictionary::TStringId FORTE_AGENT_SEND::scm_anEventOutputNames[] = {g_nStringIdINITO};

const SFBInterfaceSpec FORTE_AGENT_SEND::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  0, 0,  11,  scm_anDataInputNames, scm_anDataInputTypeIds,
  0,  0, 0,
  0, 0
};

AgentTCPclient client;

void FORTE_AGENT_SEND::executeEvent(int pa_nEIID){
	int AGENT_SEND_instance = 0;

   switch(pa_nEIID){
    case scm_nEventINITID:
    	if (!isInitialised) {
    		// Connect to the remote diagnostic server.
    		listenerPort = PORT();
    		AGENT_SEND_instance = INST_ID();
    		char serverAddress[32] = {0};
    		ADDRESS().toString(serverAddress, 32);
    		// FORTE strings have leading and terminating single-quote characters in them
			// so remove them from the IP address.
			for(int ptr = 1; ptr <= 32; ptr++) {
				serverAddress[ptr - 1] = serverAddress[ptr];
				if ((ptr > 1 ) && (serverAddress[ptr] == '\'')) {
					serverAddress[ptr - 1] = '\0';
					break;
				}
			}
			if (client.createServerConnection(serverAddress, listenerPort)) {
				isInitialised = true;
				sendOutputEvent(scm_nEventINITOID);
			} else {
				cout << "AGENT_SEND " << " cannot connect to the diagnostic server at " << serverAddress << " via listenerPort " << listenerPort
				     << ". " << client.getLastErrorMessage() << "\n";
			}
    	}
 		break;

    case scm_nEventREQID:
    	AGENT_SEND_instance = INST_ID();
    	string dataValue = to_string(DATA_REAL());
    	long unsigned int dataLen = dataValue.length();
    	string diagnosticData = "*" + to_string(AGENT_SEND_instance) + "|" + to_string(dataLen) + "|" + to_string(DATA_REAL());
    	cout << "AGENT_SEND_" << AGENT_SEND_instance << " DATA_REAL = " << diagnosticData << "\n";
    	if (isInitialised) {
    		client.sendPacket(diagnosticData);
    	}
      break;
  }
}