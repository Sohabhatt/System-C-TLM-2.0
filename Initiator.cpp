#include<systemc>
#include<tlm>
#include "adder.h"

using namespace sc_core;
using namespace tlm;

struct Initiator: sc_module {
   tlm_initiator_socket<> socket;
   
   SC_CTOR (Initiator) {
     SC_METHOD (process);
     }
     
   void process () {
      AdderPayload* Adder = new AdderPayload{3,4,0};
      tlm_generic_payload trans;
      sc_time delay = SC_ZERO_TIME;
      
      trans.set_data_ptr(reinterpret_cast<unsigned char*> (Adder));
      trans.set_data_length(sizeof(AdderPayload));
      trans.set_command(TLM_WRITE_COMMAND);
      
      socket-> b_transport(trans, delay);
      
      std:: cout << " Sum: "<<Adder -> sum <<std::endl;
      
      delete Adder;
    }  
    
};    
