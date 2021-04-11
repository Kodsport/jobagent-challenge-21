#include "validator.h"

void run(){
    int n = Int(2, 1000); 
    Space(); 
    int m = Int(2, 100);
	Endl();

	for (int i = 0; i < n; i++) {
		vector<string> tokens = SpacedTokens(m);
		for (const string& tok : tokens) {
			assert(!tok.empty());
		}
	}
}
