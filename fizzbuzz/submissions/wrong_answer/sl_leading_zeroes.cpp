#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	int best = -1, besti = -1;
	rep(i,0,N) {
		int cor = 0;
		rep(j,1,M+1) {
			if (j % 3 == 0 || j % 5 == 0) {
				string exp, w;
				if (j % 15 == 0) exp = "fizzbuzz";
				else if (j % 5 == 0) exp = "buzz";
				else if (j % 3 == 0) exp = "fizz";
				cin >> w;
				cor += (w == exp);
			} else {
				int x;
				cin >> x;
				if (cin) {
					cor += (x == j);
				} else {
					cin.clear();
					string w;
					cin >> w;
				}
			}
		}
		if (cor > best) {
			best = cor;
			besti = i + 1;
		}
	}
	cout << besti << endl;
}
