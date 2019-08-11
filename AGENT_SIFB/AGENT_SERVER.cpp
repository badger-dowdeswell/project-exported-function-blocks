/*************************************************************************
 *** FORTE Library Element
 ***
 *** This file was generated using the 4DIAC FORTE Export Filter V1.0.x!
 ***
 *** Name: AGENT_SERVER
 *** Description: Service Interface Function Block Type
 *** Version: 
 ***     1.0: 2019-01-10/badger - null - 
 *************************************************************************/

#include "AGENT_SERVER.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "AGENT_SERVER_gen.cpp"
#endif

#include  "AGENT_SERVER_Library.cpp"

DEFINE_FIRMWARE_FB(FORTE_AGENT_SERVER, g_nStringIdAGENT_SERVER)

const CStringDictionary::TStringId FORTE_AGENT_SERVER::scm_anDataInputNames[] = {g_nStringIdADDRESS, g_nStringIdPORT, g_nStringIdDATA_TYPE};

const CStringDictionary::TStringId FORTE_AGENT_SERVER::scm_anDataInputTypeIds[] = {g_nStringIdSTRING, g_nStringIdLINT, g_nStringIdINT};

const CStringDictionary::TStringId FORTE_AGENT_SERVER::scm_anDataOutputNames[] = {g_nStringIdDATA_INT, g_nStringIdDATA_LINT, g_nStringIdDATA_REAL, g_nStringIdDATA_LREAL, g_nStringIdDATA_STRING, g_nStringIdDATA_WSTRING, g_nStringIdDATA_BOOL};

const CStringDictionary::TStringId FORTE_AGENT_SERVER::scm_anDataOutputTypeIds[] = {g_nStringIdINT, g_nStringIdLINT, g_nStringIdREAL, g_nStringIdLREAL, g_nStringIdSTRING, g_nStringIdWSTRING, g_nStringIdBOOL};

const TForteInt16 FORTE_AGENT_SERVER::scm_anEIWithIndexes[] = {0, -1};
const TDataIOID FORTE_AGENT_SERVER::scm_anEIWith[] = {0, 1, 2, 255};
const CStringDictionary::TStringId FORTE_AGENT_SERVER::scm_anEventInputNames[] = {g_nStringIdINIT, g_nStringIdREQ};

const TDataIOID FORTE_AGENT_SERVER::scm_anEOWith[] = {0, 1, 2, 3, 4, 5, 6, 255};
const TForteInt16 FORTE_AGENT_SERVER::scm_anEOWithIndexes[] = {-1, 0, -1};
const CStringDictionary::TStringId FORTE_AGENT_SERVER::scm_anEventOutputNames[] = {g_nStringIdINITO, g_nStringIdREQO};

const SFBInterfaceSpec FORTE_AGENT_SERVER::scm_stFBInterfaceSpec = {
  2,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  2,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  3,  scm_anDataInputNames, scm_anDataInputTypeIds,
  7,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

//
// executeEvent()
// ==============
// This routine is called each time the FORTE runtime triggers an input event for
// this function block instance. 
//
void FORTE_AGENT_SERVER::executeEvent(int pa_nEIID){
	long int port;
	struct sockaddr_in address;
	int addrlen = sizeof(address);
	char buffer[1024] = "{0}";
	int charsRead = 0;
	string packet = "";
		
	if (!isListening) {
		// The function block has to be initialised by triggering an INIT
		// input event, usually via the START function block. Before any
		// diagnostic test information can be exchanged, this server 
		// function block has to open up a connection that it can listen
		// on for incoming messages from the remote diagnostic agent. 
		char listenerAddress[32] = {0};
		ADDRESS().toString(listenerAddress, 32);

		// Get the remote diagnostic server address from the ADDRESS input
		// parameter. This allows each AGENT_SERVER instance to listen on
		// a unique address that was specified by the remote diagnostic
		// agent when the test was configured. Note that  FORTE strings have 
		// leading and terminating single-quote characters in them that must
		// be removed to create a valid IP address.
		for(int ptr = 1; ptr <= 32; ptr++) {
			listenerAddress[ptr - 1] = listenerAddress[ptr];
			if ((ptr > 1 ) && (listenerAddress[ptr] == '\'')) {
				listenerAddress[ptr - 1] = '\0';
				break;
			}
		}
		
		// The port that we are going to listen on for incoming connections is
		// also specified in an input parameter.	
		port = PORT();
		
		cout << "listenerAddress [" << listenerAddress << "] PORT=" << to_string(PORT()) << "\n";
		
		if (createListener(listenerAddress, port)) {
			// Opened this local server successfully. Emit an INITO  event to signal that it is 
			// now ok for all AGENT_SEND function blocks within this test configuration can to 
			// connect to the diagnostic server prior to the start of the diagnostic session.
			sendOutputEvent(scm_nEventINITOID);
			isListening = true;
		}
	}		
			
	if (isListening) {		
		if (!isConnected) {
			// No client has connected yet so try to accept any connections waiting in
			// the queue.		
			new_Socket = accept(serverSocket, NULL, NULL);
			if (new_Socket != -1) {
				// A client has connected. Set the socket to be non-blocking.
				int flags = fcntl(new_Socket, F_GETFL, 0);
				fcntl(new_Socket, F_SETFL, flags | SOCK_NONBLOCK);
				cout << "someone connected\n";
				cout << "listening to socket " << to_string(new_Socket) << "\n";
				isConnected = true;
				
				// RA_BRD
				// ======
				// Opened this local server successfully. Emit an INITO  event to signal that it is 
				// now ok for all AGENT_SEND function blocks within this test configuration can now
				// connect to the diagnostic server prior to the start of the diagnostic session.
				// sendOutputEvent(scm_nEventINITOID);
			}
		} else {
			// A session has been established so talk with the server via this socket.
			charsRead = read(new_Socket, buffer, 1024);
			if (charsRead > 0) {
				// Remove the cr/lf pair on the end of the string by terminating the string correctly
				// with a null character.
			   buffer[charsRead - 1] = '\0';				
				cout << "AGENT_SERVER charsRead = [" << to_string(charsRead) << "]\n"; 
				printf("[%s]\n", buffer);
				// Set the function blocks output data value.
				DATA_REAL() = atof(buffer);
				cout << "AGENT_SERVER output DATA_REAL() = " << to_string(DATA_REAL()) << "\n";
				// Trigger an output event for this data to feed the value into
				// the function block being tested.
				sendOutputEvent(scm_nEventREQOID);
				// Acknowledge the data request back to the server.
				sendPacket2(new_Socket, "ACK\n");
			} else {
				//cout << "charsRead = [" << to_string(charsRead) << "]\n";
			}
		}
		// RA_BRD
		// ======
		// Need to think abou handling timeouts for active sessions. Experiment with trying to 
		// reconnect to a new socket (or re-used the existing one after closing it?)
	}			
}

   // RA_BRD Dead code....
   // ====================
		//cout << "out of block\n";	
					
	//	if ((new_Socket = accept(serverSocket, (struct sockaddr *)&address, (socklen_t *)&addrlen)) == -1) {
	//		cout << "Error on accept()\n";
	//	} else {
	//		cout << "new_Socket=" << to_string(new_Socket) << "\n";
		//	cout << "accept\n";
		//	int flags = fcntl(new_Socket, F_GETFL, 0);
		//	fcntl(new_Socket, F_SETFL, flags | SOCK_NONBLOCK);
	//	}
	
	//if (DIAG_VALUE() == 0) {
	//	DIAG_VALUE() = TForteFloat(123.4500);
	//} else {
	//	DIAG_VALUE() = DIAG_VALUE() + TForteFloat(1.0000);
	//}	
	
	// sendOutputEvent(scm_nEventREQOID);





