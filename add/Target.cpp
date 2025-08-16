#include<systemc>
#include<tlm>
#include<tlm_utils/simple_initiator_socket.h>
#include<tlm_utils/simple_target_socket.h>
#include "Adder.h"

using namespace tlm;
using namespace std;
using namespace sc_core;

struct Target:sc_module {
  tlm_utils::simple_target_socket<Target>socket;
  
  SC_CTOR(Target) {
        socket.register_b_transport(this, &Target::b_transport);
    }

    void b_transport(tlm_generic_payload& trans, sc_time& delay) {
        int* data = reinterpret_cast<int*>(trans.get_data_ptr());

        int a = data[0];
        int b = data[1];
        int sum = a + b;

        cout << "Target received: " << a << " + " << b << " = " << sum << endl;
        
        
        }
};

