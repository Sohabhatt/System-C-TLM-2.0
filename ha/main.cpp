#include <systemc>  // Include the SystemC header
#include <tlm>  // Include TLM header for Transaction-Level Modeling
#include "Initiator.cpp"  // Include the Initiator module
#include "Target.cpp"  // Include the Target module

// Main simulation function
int sc_main(int argc, char* argv[]) {
    Initiator initiator("initiator");  // Instantiate the Initiator module with the name "initiator"
    Target target("target");  // Instantiate the Target module with the name "target"
    
    initiator.socket.bind(target.socket);  // Bind the Initiator's socket to the Target's socket for the communication

    sc_start();  // Start the SystemC simulation
    return 0;  // Indicate successful execution
}
