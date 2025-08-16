#ifndef COUNTER_H
#define COUNTER_H

using namespace std;
using namespace sc_core;
using namespace tlm;

struct counter {
  int count;
  int reset;
  int clock;
  int result;
  };
  
#endif  
