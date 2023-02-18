#include "validator.h"

void run(){
  int maxN = Arg("maxN");
  int n = Int(2, maxN); 
  Space(); 
  int m = Int(2, n);
  Endl();

  string tok = _token();
  Endl();
  assert((int)tok.size() == n);
    for (char c : tok) {
      assert(('a' <= c && c <= 'z'));
    }
}
