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

#include "AGENT_LISTENER.h"
#ifdef FORTE_ENABLE_GENERATED_SOURCE_CPP
#include "AGENT_LISTENER_gen.cpp"
#endif
#include  "AGENT_LISTENER_Library.cpp"

DEFINE_FIRMWARE_FB(FORTE_AGENT_LISTENER, g_nStringIdAGENT_LISTENER)

const CStringDictionary::TStringId FORTE_AGENT_LISTENER::scm_anDataInputNames[] = {g_nStringIdPORT, g_nStringIdADDRESS};

const CStringDictionary::TStringId FORTE_AGENT_LISTENER::scm_anDataInputTypeIds[] = {g_nStringIdLINT, g_nStringIdSTRING};

const CStringDictionary::TStringId FORTE_AGENT_LISTENER::scm_anDataOutputNames[] = {g_nStringIdDIAG_VALUE};

const CStringDictionary::TStringId FORTE_AGENT_LISTENER::scm_anDataOutputTypeIds[] = {g_nStringIdREAL};

const TForteInt16 FORTE_AGENT_LISTENER::scm_anEIWithIndexes[] = {0};
const TDataIOID FORTE_AGENT_LISTENER::scm_anEIWith[] = {0, 1, 255};
const CStringDictionary::TStringId FORTE_AGENT_LISTENER::scm_anEventInputNames[] = {g_nStringIdINIT};

const TDataIOID FORTE_AGENT_LISTENER::scm_anEOWith[] = {0, 255};
const TForteInt16 FORTE_AGENT_LISTENER::scm_anEOWithIndexes[] = {0, -1};
const CStringDictionary::TStringId FORTE_AGENT_LISTENER::scm_anEventOutputNames[] = {g_nStringIdREQO};

const SFBInterfaceSpec FORTE_AGENT_LISTENER::scm_stFBInterfaceSpec = {
  1,  scm_anEventInputNames,  scm_anEIWith,  scm_anEIWithIndexes,
  1,  scm_anEventOutputNames,  scm_anEOWith, scm_anEOWithIndexes,  2,  scm_anDataInputNames, scm_anDataInputTypeIds,
  1,  scm_anDataOutputNames, scm_anDataOutputTypeIds,
  0, 0
};

void alg_initialize(void){
		
}

//
// executeEvent()
// ==============
void FORTE_AGENT_LISTENER::executeEvent(int pa_nEIID){
	long int port;
	struct sockaddr_in address;
	int addrlen = sizeof(address);
	char buffer[1024] = "{0}";
	int charsRead = 0;
	string packet = "";
		
	if (!isListening) {
		// Open up a connection that this function block agent can listen
		// on for incoming messages from the diagnostic agent.
		char listenerAddress[32] = {0};
		ADDRESS().toString(listenerAddress, 32);

		// FORTE strings have leading and terminating single-quote characters in them
		// so remove them from the IP address.
		for(int ptr = 1; ptr <= 32; ptr++) {
			listenerAddress[ptr - 1] = listenerAddress[ptr];
			if ((ptr > 1 ) && (listenerAddress[ptr] == '\'')) {
				listenerAddress[ptr - 1] = '\0';
				break;
			}
		}	
		
		cout << "listenerAddress [" << listenerAddress << "] PORT=" << to_string(PORT()) << "\n";
		port = PORT();
		isListening = createListener(listenerAddress, port);
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
			}
		} else {
			// A session has been established so talk with the server via this socket.
			charsRead = read(new_Socket, buffer, 1024);
			if (charsRead > 0) {
				// Remove the cr/lf pair on the end of the string by terminating the string correctly
				// with a null character.
			   buffer[charsRead - 1] = '\0';				
				cout << "charsRead = [" << to_string(charsRead) << "]\n"; 
				printf("[%s]\n", buffer);
				// Set the function blocks output data value.
				DIAG_VALUE() = atof(buffer);
				cout << "DIAG_VALUE() = " << to_string(DIAG_VALUE()) << "\n";
				// Trigger an output event for this data.
				sendOutputEvent(scm_nEventREQOID);
				sendPacket2(new_Socket, "ACK\n");
			} else {
				//cout << "charsRead = [" << to_string(charsRead) << "]\n";
			}
		}		

		//cout << "out of block\n";	
					
	//	if ((new_Socket = accept(serverSocket, (struct sockaddr *)&address, (socklen_t *)&addrlen)) == -1) {
	//		cout << "Error on accept()\n";
	//	} else {
	//		cout << "new_Socket=" << to_string(new_Socket) << "\n";
		//	cout << "accept\n";
		//	int flags = fcntl(new_Socket, F_GETFL, 0);
		//	fcntl(new_Socket, F_SETFL, flags | SOCK_NONBLOCK);
	//	}
	}
	
	
	//if (DIAG_VALUE() == 0) {
	//	DIAG_VALUE() = TForteFloat(123.4500);
	//} else {
	//	DIAG_VALUE() = DIAG_VALUE() + TForteFloat(1.0000);
	//}	
	
	// sendOutputEvent(scm_nEventREQOID);
}



