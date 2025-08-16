## SystemC TLM 2.0 (Transaction-Level Modeling)

SystemC TLM 2.0 is a standardized C++ library built on top of SystemC that facilitates high-level modeling of communication between hardware modules.

### Key Features

- **Transaction Abstraction**  
  Models data transfers as transactions instead of low-level signals, enabling faster and more efficient simulations.

- **Initiator and Target Modules**  
  - **Initiator:** Starts transactions (e.g., sending read/write requests).  
  - **Target:** Receives and processes transactions.

- **Standardized Sockets**  
  Provides `simple_initiator_socket` and `simple_target_socket` for modular and reusable communication interfaces.

- **Generic Payload**  
  A flexible data structure carrying commands, addresses, and data for transactions.

- **Blocking Transport Interface (`b_transport`)**  
  Facilitates synchronous, blocking communication between initiators and targets.

- **Timing Models**  
  Supports loosely timed and approximately timed simulation styles to balance between accuracy and simulation speed.

### Benefits

- Speeds up design space exploration by abstracting away detailed signal-level timing.  
- Enables virtual prototyping and early software development before hardware is available.  
- Simplifies hardware/software co-design and verification.

---

Feel free to explore, use, and contribute to this repository for SystemC TLM 2.0 modeling!
