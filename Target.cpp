#include<systemc>
#include<tlm>
#include <tlm_utils/simple_target_socket.h>
#include "adder.h"

using namespace sc_core;
using namespace tlm;

struct Target: sc_module {
 tlm_target_socket<>socket;
  
  SC_CTOR(Target) {
        socket.register_b_transport(this, &Target::b_transport);
    }
     
  void b_transport(tlm_generic_payload&trans, sc_time&delay) {
     auto* Adder = reinterpret_cast<AdderPayload*>(trans.get_data_ptr());   
     Adder -> sum = Adder -> a + Adder -> b;
     
     std::cout <<" Target Received: a = " << Adder -> a << "Target Received: b = " << Adder -> b << " Sum = " << Adder -> sum << std::endl;
     
     }
};
     
