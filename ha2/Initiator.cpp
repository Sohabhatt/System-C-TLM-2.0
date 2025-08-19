#include<systemc>
#include<tlm>
#include<tlm_utils/simple_initiator_socket.h>
#include "HalfadderPayload.cpp"

using namespace std;
using namespace tlm;
using namespace sc_core;

struct Initiator: sc_module {
  tlm_utils::simple_initiator_socket<Initiator>socket;
  
  SC_CTOR (Initiator) {
    SC_THREAD (process) ;
    }
    
 void process () {
   int testcase [4][2] = {
     {0,0},
     {0,1},
     {1,0},
     {1,1}, };
     
   for(int i = 0; i < 4; i++) {
     tlm_generic_payload trans;
     sc_time delay = SC_ZERO_TIME;
     HalfadderPayload* payload = new HalfadderPayload; 
           
     payload-> a = testcase[i][0];
     payload-> b = testcase[i][1];
     payload-> sum = 0;
     payload->carry = 0;
     
     trans.set_command(TLM_WRITE_COMMAND);
     trans.set_address(0);
     trans.set_data_ptr(reinterpret_cast <unsigned char*> (payload));
     trans.set_data_length(sizeof(payload));
     trans.set_streaming_width(sizeof(payload));
     trans.set_byte_enable_ptr(0);
     trans.set_dmi_allowed(false);
     trans.set_response_status(TLM_INCOMPLETE_RESPONSE);
     
     cout << "Initiator: Sending a : " <<payload->a << "Initiator: Sending b : " << payload->b <<endl;
     
     socket->b_transport(trans, delay);
     
     if(trans.is_response_error()) {
       cout << "Initiator: Transaction Error" << trans.get_response_string() << ", Sum: " <<payload->sum << ", Carry: " <<payload->carry << endl;
       }
     else {
      cout << "Initiator: Transaction Done" << trans.get_response_string() << ", Sum: " << payload-> sum <<  ", Carry: " <<payload->carry << endl;      
        }
       }
      }
    };    
        
        
