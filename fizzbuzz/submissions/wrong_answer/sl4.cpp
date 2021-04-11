#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)

int main() {
	int N, M;
	cin >> N >> M;
	int best = -1;
	vector<int> bestv;
	rep(i,0,N) {
		int cor = 0;
		rep(j,1,M+1) {
			string w;
			cin >> w;
			string exp = to_string(j);
			cor += (w == exp);
		}
		if (cor > best) {
			best = cor;
			bestv.clear();
		}
		if (cor == best) bestv.push_back(i + 1);
	}
	for (int x : bestv) cout << x << ' ';
	cout << endl;
}
