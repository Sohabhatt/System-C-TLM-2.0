#include<systemc>
#include<tlm>
#include<tlm_utils/simple_initiator_socket.h>
#include<tlm_utils/simple_target_socket.h>
#include "AdderPayload.cpp"
#include "Initiator.cpp"
#include "Target.cpp"

using namespace tlm;
using namespace std;
using namespace sc_core;

int sc_main (int argc, char* argv[] ) {
   Initiator initiator ("initiator");
   Target target ("target");
     
   initiator.socket.bind(target.socket);
   sc_start();
   return 0;
   }
