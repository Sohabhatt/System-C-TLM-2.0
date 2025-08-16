#include<systemc>
#include<tlm>
#include<tlm_utils/simple_initiator_socket.h>
#include "fa.h"

using namespace std;
using namespace tlm;
using namespace sc_core;

struct Initiator : sc_module {
  tlm_utils::simple_initiator_socket <Initiator> socket;
  
  SC_CTOR(Initiator) {
     SC_METHOD (process) ;
      }
  
  void process () {
     tlm_generic_payload trans;
     sc_time delay = SC_ZERO_TIME;
     
     bool data[5];
     data [0] = 1;
     data [1] = 0;
     data[2] = 1;
     
     trans.set_command(TLM_WRITE_COMMAND);
     trans.set_address(0);
     trans.set_data_ptr(reinterpret_cast<unsigned char* > (data));
     trans.set_data_length(sizeof(data));
         
     cout << " Sending a: " << data [0] << "Sending b: " << data [1] << " Sending cin " << data[2] << endl;
     
     socket -> b_transport(trans, delay);
     }
 };     
      
       
