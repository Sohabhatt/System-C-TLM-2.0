#include<systemc>
#include<tlm>
#include<tlm_utils/simple_target_socket.h>
#include "counter.h"

struct Target: sc_module {
  tlm_utils::simple_target_socket <Target> socket;
  
  SC_CTOR(Target) {
   socket.register_b_transport(this, &Target::b_transport);
   }
   
  void b_transport(tlm_generic_payload& trans, sc_time& delay) {
       int* data = reinterpret_cast<int*> (trans.get_data_ptr());
       
         int count = data[0];
         int result = count + 1;
          data[1] = result;
          
       cout << "Target received = count: " << data[1] << endl; 
       }
   };    
    
