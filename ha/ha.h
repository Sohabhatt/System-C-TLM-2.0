//Array-based TLM Payload Communication
#ifndef HALF_ADDER_H  // Check if HALF_ADDER_H is not defined to prevent multiple inclusions
#define HALF_ADDER_H  // Define the macro HALF_ADDER_H 

// Define a struct to hold the inputs and outputs of the half adder
struct half_adder_payload {
  bool a;    // Represents the first input of the half adder.
  bool b;    // Represents the second input of the half adder.
  bool sum;  // Holds the sum output of the half adder.
  bool cout; // Holds the carry out output of the half adder.
};

#endif  // End the preprocessor conditional to ensure this header file is only included once
