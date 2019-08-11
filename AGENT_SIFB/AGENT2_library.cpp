//
// AGENT2_library
// ==============
// Library of custom routines for the function block type AGENT2. 
//
// Note that the 4DIAC type definition section only allows one custom header entry so this file 
// can be linked in at compile time by referencing it in the Compiler Info section 
// as: #include AGENT2_library.cpp.
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

using std::cout;
using std::string;
using std::to_string;

bool isInitialised = false;
int sock = 0;
long int port = 0;

//
// createConnection()
// ==================
// Creates a connection to the server agent that this SIFB function block
// is working with.
//
// serverAddress  IPv4 or IPv6 server address (e.g. "127.0.0.1").
// thisPort       Socket number that is to be connected to on the remote server.
// returns        True if the connection can be established.   
//
bool createConnection(string serverAddress, long int thisPort) {
	bool isConnected = false;
	//struct sockaddr_in address;
	//struct sockaddr_in server_addr;
	struct sockaddr_in address, server_addr;
			
	cout << "in createConnection() " << serverAddress << " " << to_string(thisPort) << "\n";
	
	if ((sock = socket(AF_INET, SOCK_STREAM, 0 )) < 0) {
		perror("Cannot create socket"); 
   } else {
		perror("Created socket");
		
		// Connect to the server
		memset((char *) &address, 0, sizeof(address));
		server_addr.sin_family = AF_INET;
		server_addr.sin_port = htons(thisPort);

		// Convert IPv4 network address in the format ddd.ddd.ddd.ddd from text to binary form. Use
		// AF_INET6 instead of AF_INET if this is an IPv6 address. Note that the second parameter of the
		// inet_pton() function requires a character pointer to a string constant. The next line converts
		// the serverAddress parameter to a pointer.  
		
		const char *ptr_serverAddress = serverAddress.c_str();
		
		if (inet_pton(AF_INET, ptr_serverAddress, &server_addr.sin_addr) <= 0) {
			perror("Invalid address or address not supported\n");
		} else {
			if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
				perror("Connection failed\n");
			} else {
				perror("Connected\n");
				isConnected = true;
			}
		}
	}
	return isConnected;
}

//
// sendPacket()
// ============
// Sends a packet of data to the remote agent that was previously
// connected to using createConnection()
//
// msg  String to be sent to the server. Since the connection was opened as a Stream, there
//      no maximum size for this data packet.
//
void sendPacket(string msg) {
	if (isInitialised) {
		//send(sock, msg, strlen(msg), 0);
		send(sock, msg.c_str(), msg.length(), 0);
	} else {
		perror("Cannot send data packet in sendPacket(): no connection is open\n");	
	}	
}
