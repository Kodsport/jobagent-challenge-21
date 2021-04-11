#include "validator.h"

void run(){
    int n = Int(1, Arg("n")); 
    Space(); 
    int m = Int(1, Arg("m"));
	Endl();

	for (int i = 0; i < n; i++) {
		string Lin = Line();
        int spaces = 0;
        string sub = "";
		for (int j = 0; j < Lin.size(); j++){
            if (Lin[j] == ' '){
                spaces++;
                assert(sub.size() != 0);
                sub = "";
            }
            else sub += Lin[j];
        }
        assert(spaces == m - 1);
	}
}