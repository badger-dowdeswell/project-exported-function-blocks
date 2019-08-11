//
// AGENT TCP LIBRARY
// =================
// Library of TCP network functions to support communications
// between the FORTE function block Service Interface Function
// blocks and the fault diagnostic system.
//
// Badger Dowdeswell - 2019
//
// Revision History
// ================
// 06.08.2019 BRD Original version.
//
#include <arpa/inet.h>
#include <sys/socket.h>
#include <errno.h>
#include <unistd.h>

class AgentTCP {

	public:
		bool testMethod(string msg) {
			cout << msg;
		}	
};