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
  vi P(N);
  rep(i,0,N) cin >> P[i], P[i]--;

  int res = 0;
  while (true) {
    bool ch = false;
    rep(i,0,N) {
      if (P[i] != i) {
        swap(P[i], P[P[i]]);
        ++res;
        ch = true;
        goto again;
      }
    }
    break;
again:;
  }
  cout << res << endl;
}
