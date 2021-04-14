#include "validator.h"

void run(){
  int n = Int(2, 100000); 
  Endl();

  vector<int> jobs = SpacedInts(n, 1, n);
  assert(set<int>(jobs.begin(), jobs.end()).size() == n);
}
