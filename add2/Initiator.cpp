#include<systemc>
#include<tlm>
#include<tlm_utils/simple_initiator_socket.h>
/*#include<tlm_utils/simple_target_socket.h> */
#include "AdderPayload.cpp"

using namespace std;
using namespace sc_core;
using namespace tlm;

struct Initiator:sc_module {
  tlm_utils:: simple_initiator_socket <Initiator> socket;
  
  SC_CTOR (Initiator) {
     SC_THREAD (process) ;
     }
     
  void process () {
         
   int testcase [4][2] = { 
     {3,2},
     {4,6},
     {15,20},
     {56,35},
     };
  for(int i = 0; i < 4; i++) {
   AdderPayload* payload = new AdderPayload; 
      tlm_generic_payload trans;     
     sc_time delay = SC_ZERO_TIME;
        payload->a = testcase[i][0];
        payload->b = testcase[i][1];
        payload->sum = 0;
        
        trans.set_command(TLM_WRITE_COMMAND);
        trans.set_address(0);
        trans.set_data_ptr(reinterpret_cast<unsigned char*>(payload));
        trans.set_data_length(sizeof(AdderPayload));
        trans.set_streaming_width(sizeof(AdderPayload));
        trans.set_byte_enable_ptr(0);
        trans.set_dmi_allowed(false);
        trans.set_response_status(TLM_INCOMPLETE_RESPONSE);

        cout << "Initiator: Sending a = " << payload->a << ", b = " << payload->b << endl;
     
     socket -> b_transport (trans, delay);
     
     if(trans.is_response_error()) {
         cout << "Initiator: Transaction Error " << trans.get_response_string() << ", Sum : " << payload->sum <<endl;
      } else { 
         cout <<"Initiator: Transaction OK " << trans.get_response_string() << ", Sum: " << payload-> sum << endl;   
       }
     }
   }  
 };     
       

