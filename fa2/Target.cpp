#include<systemc>
#include<tlm>
#include<tlm_utils/simple_target_socket.h>
#include "FulladderPayload.cpp"

using namespace std;
using namespace tlm;
using namespace sc_core;


struct Target : sc_module {
 tlm_utils::simple_target_socket <Target> socket;
 
 SC_CTOR (Target) {
   socket.register_b_transport (this, &Target::b_transport) ;
    }
 
 void b_transport(tlm_generic_payload& trans, sc_time& delay) {
   FulladderPayload* payload = reinterpret_cast<FulladderPayload*> (trans.get_data_ptr());
   
   int a = payload -> a;
   int b = payload -> b;
   int c = payload -> c;
   payload -> sum = a ^ b ^ c;
   payload -> carry = (a & b) || (b & c) || (c & a);
   
   cout << "Received : Sum " << payload -> sum << endl;
   cout << "Received : Carry " << payload -> carry << endl;
   
   }
};     
 
