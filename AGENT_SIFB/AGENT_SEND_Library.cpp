//
// AGENT_SEND_Library
// ==================
// Library of custom routines for the function block type AGENT_SEND.
//
// Note that the 4DIAC type definition section only allows one custom header entry so this file
// can be linked in at compile time by referencing it in the Compiler Info section
// as: #include AGENT_SEND_Library.cpp.
//
// Using a library like this for all custom-written code makes it a lot easier to re-export
// the function block out of 4DIAC is significant changes to the function block type definition
// are required.
//
// Version history
// ===============
// 09.01.2019 BRD Original version based on re-writing the AGENT2 function block.
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
int clientSocket = 0;

long int listenerPort = 0;
string lastErrorMessage = "";

class AgentTCPclient {

	public:
		bool testMethod(string msg) {
			cout << msg;
			return true;
		}

		//
		// createServerConnection()
		// ========================
		// Creates a connection to the server that this SIFB function block
		// instance will send diagnostic information to:
		//
		// serverAddress  IPv4 or IPv6 server address (e.g. "127.0.0.1").
		//
		// port           Listener port number that is to be connected to on the remote server.
		//                This accepts incoming connections and then hands the session over
		//						to a unique session socket.
		//
		// returns        True if the connection to the server can be established.
		//
		bool createServerConnection(string serverAddress, long int port) {
			bool isConnected = false;
			//struct sockaddr_in address;
			//struct sockaddr_in server_addr;
			struct sockaddr_in address, server_addr;

			cout << "in createServerConnection() " << serverAddress << " " << to_string(port) << "\n";

			lastErrorMessage = "";
			if ((clientSocket = socket(AF_INET, SOCK_STREAM, 0 )) < 0) {
				lastErrorMessage = "Cannot create socket";
   		} else {
				// Connect to the server
				memset((char *) &address, 0, sizeof(address));
				server_addr.sin_family = AF_INET;
				server_addr.sin_port = htons(port);

				// Convert an IPv4 network address in the format ddd.ddd.ddd.ddd from text to binary form. Use
				// AF_INET6 instead of AF_INET if this is an IPv6 address. Note that the second parameter of the
				// inet_pton() function requires a character pointer to a string constant. The next line converts
				// the serverAddress parameter to a pointer.
				const char *ptr_serverAddress = serverAddress.c_str();

				if (inet_pton(AF_INET, ptr_serverAddress, &server_addr.sin_addr) <= 0) {
					lastErrorMessage = "Invalid address or address not supported";
				} else {
					if (connect(clientSocket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
						lastErrorMessage = "Connection failed";
					} else {
						isConnected = true;
					}
				}
			}
			return isConnected;
		}

		//
		// getLastErrorMessage()
		// =====================
		// Returns the last error message logged by one of
		// the functions in this class.
		//
		string getLastErrorMessage() {
			return lastErrorMessage;
		}

		//
		// sendPacket()
		// ============
		// Sends a packet of data to the remote server that was previously
		// connected to using createServerConnection():
		//
		// msg     String to be sent to the server. Since the connection was opened as a stream, there
		//   		  no maximum size for this data packet.
		//
		// returns True if the message was sent successfully.
		//
		bool sendPacket(string msg) {
			if (isInitialised) {
				send(clientSocket, msg.c_str(), msg.length(), 0);
				return true;
			} else {
				lastErrorMessage = "Cannot send data packet using sendPacket(): no connection is open.";
				return false;
			}
		}
};

