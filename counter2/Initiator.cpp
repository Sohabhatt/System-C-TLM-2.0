#include<systemc>
#include<tlm>
#include<tlm_utils/simple_initiator_socket.h>
#include "counter.h"

using namespace std;
using namespace sc_core;
using namespace tlm;

struct Initiator : sc_module {
  tlm_utils :: simple_initiator_socket <Initiator> socket;
  
  SC_CTOR (Initiator) {
    SC_THREAD(process) ;
    }
    
 void process() {
   int testcase [5][3] = { 
   {1, 1, 0},
   {0, 1, 0},
   {0, 1, 0},
   {0, 1, 0},
   {0, 1, 0},
   }; 
   
   for (int i = 0; i < 5; i++) {
   
     counter* payload = new counter;
     tlm_generic_payload trans;
     sc_time delay = SC_ZERO_TIME;
     payload->reset = testcase [i][0];
     payload->clock = testcase[i][1];
     payload->count = testcase[i][2];
     payload->result = 0;
     
     trans.set_command(TLM_WRITE_COMMAND);
     trans.set_address(0);
     trans.set_data_ptr(reinterpret_cast<unsigned char*>(payload));
     trans.set_data_length(sizeof(counter));
     trans.set_streaming_width(sizeof(counter));
     trans.set_byte_enable_ptr(0);
     trans.set_dmi_allowed(false);
     trans.set_response_status(TLM_INCOMPLETE_RESPONSE);
     
     cout << "Initiator: Sending reset: " << payload->reset << ", Initiator: Sending clock: " << payload->clock << ", Initiator: Sending count: " <<payload->count <<endl;
     
     socket->b_transport(trans, delay);
     
      if (trans.is_response_error()) {
                cout << "Initiator: Transaction Error - " << trans.get_response_string() << "Result: " <<payload->result << endl;
            } else {
                cout << "Initiator: Transaction OK - Result = " << trans.get_response_string() << "Result: "<< payload->result << endl;
            }
             wait(10, SC_NS);
    }
  }
};      
      
     
   
      
