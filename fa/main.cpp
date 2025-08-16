#include<systemc>
#include<tlm>
#include "Initiator.cpp"
#include "Target.cpp"

int sc_main(int argc, char* argv[]) {
  Initiator initiator ("initiator");
  Target target ("target");
  
  initiator.socket.bind(target.socket);
  sc_start();
  return 0;
 } 
