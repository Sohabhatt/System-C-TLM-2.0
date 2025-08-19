#include<systemc>
#include<tlm>
#include<tlm_utils/simple_target_socket.h>
#include "AdderPayload.cpp"
using namespace std;
using namespace sc_core;
using namespace tlm;

struct Target: sc_module {
  tlm_utils::simple_target_socket <Target> socket;
  
  SC_CTOR(Target) {
   socket.register_b_transport(this, &Target::b_transport);
   }
   
  void b_transport(tlm_generic_payload& trans, sc_time& delay) {
       AdderPayload* payload = reinterpret_cast<AdderPayload*> (trans.get_data_ptr());
       
          int a = payload->a;
          int b = payload->b;
          payload->sum = a + b;
     
          
       cout << "Target received = sum: " << payload->sum << endl; 
       trans.set_response_status(TLM_OK_RESPONSE);
       delay+= sc_time(5, SC_NS);
       
       }
   };    
    
