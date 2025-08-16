#include<systemc>  // Include the SystemC header for hardware modeling
#include<tlm>  // Include TLM header for Transaction-Level Modeling
#include<tlm_utils/simple_target_socket.h>  // Include TLM utils for target socket
#include "fa.h"  // Include the custom header file (presumably for Full Adder)

using namespace std;  // Using the standard C++ namespace
using namespace sc_core;  // Using the SystemC core namespace
using namespace tlm;  // Using the TLM namespace for transaction-level modeling

// Define the Target module, derived from sc_module
struct Target : sc_module { //Syntax for defining the Target Module
  tlm_utils::simple_target_socket<Target> socket;  // Declare a TLM target socket for communication with initiators
  
  SC_CTOR(Target) {  // Constructor for the Target module
     socket.register_b_transport(this, &Target::b_transport);  // Register the b_transport method for handling transactions
  }
  
  // The b_transport method handles incoming transactions from the initiator
  void b_transport(tlm_generic_payload& trans, sc_time& delay) {  
      bool* data = reinterpret_cast<bool*>(trans.get_data_ptr());  // Cast the data pointer to a boolean array
      
      bool a = data[0];  // Extract input a
      bool b = data[1];  // Extract input b
      bool cin = data[2];  // Extract carry-in input
      
      data[3] = a ^ b ^ cin;  // Compute the sum as the XOR of a, b, and cin
      data[4] = (a && b) || (b && cin) || (cin && a);  // Compute the carry-out using OR and AND operations

      cout << "Target received = sum: " << data[3] << endl;  // Output the sum value
      cout << "Target received = carry: " << data[4] << endl;  // Output the carry value
  }
};
