//
// AGENT SERVER LIBRARY
// ====================
// Library of custom routines for the AGENT_SERVER diagnostic Service Interface Function Block. 
//
// Note that the 4DIAC type definition section only allows one custom header entry so this file 
// can be linked in at compile time by referencing it in the Compiler Info section 
// as: #include "AGENT_LISTENER_library.cpp"
//
// Version history
// ===============
// 17.12.2018 BRD Original version.
//
// Module-level declarations
// =========================
#include <iostream>
#include <stdio.h>	
#include <string.h> 
#include <stdlib.h> 
#include <arpa/inet.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>
#include <string>
#include <fcntl.h>

using std::cout;
using std::string;
using std::to_string;

bool isListening = false;
bool isConnected = false;
int listenerSocket = 0;
int serverSocket = 0;
int new_Socket = 0;

//
// createListener()
// ================
// Creates a listener that opens a connection to the agent that this SIFB function block
// is working with.
//
// serverAddress  IPv4 or IPv6 server address (e.g. 127.0.0.1) that this server operates 
//                on as a listener/server.
// thisPort       Socket number that has been opened to the remote client to connect to.
// returns        True if the connection has been opened successfully.eee   
//
bool createListener(string serverAddress, long int thisPort) {
	bool isConnected = false;
	struct sockaddr_in address;
	int addrlen = sizeof(address);
	int opt = 1;
					
	cout << "in createListener() " << serverAddress << " " << to_string(thisPort) << "\n";
	
	if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0 )) == 0) {
		perror("Cannot create server socket.\n"); 	
	} else {
		perror("Created server socket.\n");
		// Connect the socket to the port.
		if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
		               &opt, sizeof(opt))) {
			perror("Error returned from setsockopt(). Cannot set server socket options.\n"); 
		} else {
			address.sin_family = AF_INET;
		   address.sin_addr.s_addr = INADDR_ANY;
			address.sin_port = htons(thisPort);
		
			// Set the socket to be non-blocking. Retrieve the initial settings specified with setsockopt()
			// and then reset the correct bit fsetNonBlocking(serverSocket);
			int flags = fcntl(serverSocket, F_GETFL, 0);
		//	flags = 0;
			fcntl(serverSocket, F_SETFL, flags | SOCK_NONBLOCK);
		
		   // Bind the socket to the port.
		   if (bind(serverSocket, (struct sockaddr *)&address, sizeof(address)) < 0) {
				perror("Cannot bind socket to the port.\n");
			} else {
				// Start listening on that port.
		   	if (listen(serverSocket, 3) < 0) {
		   		perror("Error returned from listen(). Cannot start listening on that port.\n");
		   	} else {	
					perror("Listening on port.\n");
					isConnected = true;  
		   	}	  
			}	
		}
	}
	return isConnected;
}		             

//
// sendPacket2()
// =============
// Sends a packet of data to the remote agent that was previously
// connected to using createConnection()
//
// msg  String to be sent to the server. Since the connection was opened as a Stream, there
//      no maximum size for this data packet.
//
void sendPacket2(int sendSocket, string msg) {
	if (isListening) {
		//send(sock, msg, strlen(msg), 0);
		send(sendSocket, msg.c_str(), msg.length(), 0);
	} else {
		perror("Cannot send data packet in sendPacket2(): no connection is open\n");	
	}	
}
