#include<systemc>
#include "Initiator.cpp"
#include "Target.cpp"

int sc_main (int argc, char* argv[]) {
   Initiator Initiator ("Initiator");
   Target Target ("Target");
   
   Initiator.socket.bind(Target.socket);
   
   sc_start();
   
   return 0;
   
 }  
