#include<systemc>  // Include the SystemC header for hardware modeling
#include<tlm>  // Include TLM header for Transaction-Level Modeling
#include<tlm_utils/simple_initiator_socket.h>  // Include the TLM utils for initiator socket
#include "ha.h"  // Include the custom header file (which you define previously)

using namespace std;  // Using the standard C++ namespace
using namespace sc_core;  // Using the SystemC core namespace
using namespace tlm;  // Using the TLM namespace for transaction-level modeling

// Define the Initiator module
struct Initiator : sc_module { //Syntax for defining the Initiator Module
   tlm_utils::simple_initiator_socket<Initiator> socket;  // Declare a TLM initiator socket to communicate with a target
   
   SC_CTOR(Initiator) {  // Constructor for the Initiator module
     SC_METHOD(process);  // SC_METHOD is used to register the process in case of SystemC TLM 2.0
   }
   
   // Process method to initiate communication with the target
   void process() {  
     tlm_generic_payload trans;  // Create a generic payload object to hold transaction data
     sc_time delay = SC_ZERO_TIME;  // Set the delay to zero time for immediate transaction
    
     bool data[4];  // Declare an array to hold the input data
     data[0] = 1;  // Set input a to 1
     data[1] = 0;  // Set input b to 0 (a = 1, b = 0)
     
     // We have to define these fields in case of tlm_generic_payload
     trans.set_command(TLM_WRITE_COMMAND);  // Set the command type to WRITE
     trans.set_address(0);  // Set the address to 0
     trans.set_data_ptr(reinterpret_cast<unsigned char*>(data));  // Set the data pointer to the input data array
     trans.set_data_length(sizeof(data));  // Set the data length based on the size of the array
     
     cout << "Sending a = " << data[0] << " Sending b = " << data[1] << endl;  // Print the input data 
     socket->b_transport(trans, delay);  // Perform a block transport to send the transaction to the target (We have to write it in every code)
   }
};
