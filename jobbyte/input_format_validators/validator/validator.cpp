#include "validator.h"

void run(){
    int n = Int(2, 100000); 
	Endl();

	set<int> current, best;
	for (int i = 0; i < n; i++) {
		vector<int> tokens = SpacedInts(2, 1, n);
		assert(tokens[0] <= n); assert(current.count(tokens[0]) == 0); current.insert(tokens[0]);
		assert(tokens[1] <= n); assert(best.count(tokens[1]) == 0); best.insert(tokens[1]);
	}
}
