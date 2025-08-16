#include<systemc>
#include<tlm>
#include<tlm_utils/simple_initiator_socket.h>
#include "counter.h"

struct Initiator: sc_module {
  tlm_utils::simple_initiator_socket <Initiator> socket;
  
  SC_CTOR(Initiator) {
     SC_THREAD (process);
     }
     
  void process () {
    tlm_generic_payload trans;
    sc_time delay = sc_time(5, SC_NS);   
    
    int data[2];
    data[0] = 5;
    
    trans.set_command(TLM_WRITE_COMMAND);
    trans.set_address(0);
    trans.set_data_ptr(reinterpret_cast <unsigned char*> (data));
    trans.set_data_length(sizeof(data));
    
    cout <<" Initiator: Sending count = "<< data[0] <<endl;
    socket->b_transport(trans, delay);
    
    cout <<" Initiator: Received count = "<< data[1] <<endl;
    }
 };   
