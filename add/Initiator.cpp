#include<systemc>
#include<tlm>
#include<tlm_utils/simple_initiator_socket.h>
#include<tlm_utils/simple_target_socket.h>
#include "Adder.h"

using namespace std;
using namespace sc_core;
using namespace tlm;

struct Initiator:sc_module {
  tlm_utils:: simple_initiator_socket <Initiator> socket;
  
  SC_CTOR (Initiator) {
     SC_METHOD (process) ;
     }
     
  void process () {
     tlm_generic_payload trans;
     
     sc_time delay = SC_ZERO_TIME;
     
    int data[2] = {7, 5};  // a = 7, b = 5

        trans.set_command(TLM_WRITE_COMMAND);
        trans.set_address(0);
        trans.set_data_ptr(reinterpret_cast<unsigned char*>(data));
        trans.set_data_length(sizeof(data));
        trans.set_streaming_width(sizeof(data));
        trans.set_byte_enable_ptr(0);
        trans.set_dmi_allowed(false);
        trans.set_response_status(TLM_INCOMPLETE_RESPONSE);

        cout << "Initiator: Sending a = " << data[0] << ", b = " << data[1] << endl;
     
     socket -> b_transport (trans, delay);
     
     }
 };     
       

