#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int N;
	cin >> N;
  if (N%2 == 0) {
    cout << "beata" << endl;
    return 0;
  }
  if (N > 50000) {
    cout << "alf" << endl;
    return 0;
  }
	vi res(N / 2 + 2);
	rep(i,3,sz(res)) {
		bitset<2 * 1690> reach;
		rep(k,0,i/2) {
			int l = i - 3 - k;
			reach.set(res[k] ^ res[l]);
		}
		for (int j = 0;; ++j) {
			if (reach.test(j) == 0) {
				res[i] = j;
				break;
			}
		}
		if (i%100000==0) cerr << "ping " << i << endl;
	}

	int a = N / 2 + (N % 2);
	int b = N / 2;
	int ans = res[a] ^ res[b];
	if (ans) cout << "alf" << endl;
	else cout << "beata" << endl;
}
