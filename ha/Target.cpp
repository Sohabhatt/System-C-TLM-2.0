#include<systemc>  // Include the SystemC header for hardware modeling
#include<tlm>  // Include the TLM header for Transaction-Level Modeling
#include<tlm_utils/simple_target_socket.h>  // Include the TLM utilities for target socket
#include "ha.h"  // Include the custom Half Adder header (ha.h)

using namespace std;  // Using the standard C++ namespace
using namespace sc_core;  // Using the SystemC core namespace
using namespace tlm;  // Using the TLM namespace for transaction-level modeling

// Define the Target module
struct Target : sc_module {  //Syntax for defining the Target Module
  tlm_utils::simple_target_socket<Target> socket;  // Declare a TLM target socket for communication with initiators
  
  SC_CTOR(Target) {  // Constructor for the Target module
    socket.register_b_transport(this, &Target::b_transport);  // Register the b_transport method to handle transactions
  }
  
  // The b_transport method handles incoming transactions from the initiator
  void b_transport(tlm_generic_payload& trans, sc_time& delay) {  
    bool* data = reinterpret_cast<bool*>(trans.get_data_ptr());  // Cast the data pointer to a boolean array
    
    bool a = data[0];  // Extract the first input a
    bool b = data[1];  // Extract the second input b
    
    data[2] = a ^ b;  // Compute the sum using XOR (a ^ b)
    data[3] = a & b;  // Compute the carry using AND (a & b)
    
    cout << "Target received: sum " << a << "^" << b << " = " << data[2] << endl;  // Output the computed sum
    cout << "Target received: carry " << a << "&" << b << " = " << data[3] << endl;  // Output the computed carry
  }
};
