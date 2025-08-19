#include<systemc>
#include<tlm>
#include<tlm_utils/simple_target_socket.h>
#include "counter.h"

using namespace std;
using namespace sc_core;
using namespace tlm;

struct Target : sc_module {
  tlm_utils :: simple_target_socket <Target> socket;
  int counter_value;
  
  SC_CTOR(Target) {
   socket.register_b_transport (this, &Target::b_transport);
   }
   
  void b_transport(tlm_generic_payload& trans, sc_time& delay) {
   counter* payload = reinterpret_cast<counter*> (trans.get_data_ptr());
   
   cout << "[Target] Received - Reset: " << payload->reset << ", Clock: " << payload->clock << ", Count: " << payload->count << endl;
   
  if (payload->reset == 1) {
            counter_value = 0;
            cout << "[Target] Counter reset to 0." << endl;
        } else if (payload->clock == 1) {
            counter_value++;
            cout << "[Target] Counter incremented to: " << counter_value << endl;
        } else {
            cout << "[Target] Clock is low. Counter unchanged: " << counter_value << endl;
        }

        payload->result = counter_value;
   trans.set_response_status(tlm::TLM_OK_RESPONSE);
 delay += sc_time(1, SC_NS);
   }
 };   
