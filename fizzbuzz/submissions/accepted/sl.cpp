#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)

int main() {
	int N, M;
	cin >> N >> M;
	int best = -1;
	int bestv;
	rep(i,0,N) {
		int cor = 0;
		rep(j,1,M+1) {
			string w;
			cin >> w;
			string exp;
			if (j % 15 == 0) exp = "fizzbuzz";
			else if (j % 3 == 0) exp = "fizz";
			else if (j % 5 == 0) exp = "buzz";
			else exp = to_string(j);
			cor += (w == exp);
		}
		if (cor > best) {
			best = cor;
      bestv = i + 1;
		}
	}
  cout << bestv << endl;
}
