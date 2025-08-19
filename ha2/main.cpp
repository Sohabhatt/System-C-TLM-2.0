#include<systemc>
#include<tlm>
#include "Initiator.cpp"
#include "Target.cpp"
#include "HalfadderPayload.cpp"
#include<tlm_utils/simple_initiator_socket.h>
#include<tlm_utils/simple_target_socket.h>

using namespace std;
using namespace tlm;
using namespace sc_core;

int sc_main (int argc, char* argv []) {
 Initiator initiator ("initiator");
 Target target ("target");
 initiator.socket.bind(target.socket);
 sc_start();
 return 0;
} 

