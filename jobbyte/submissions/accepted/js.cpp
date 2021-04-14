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
  vi X(N);
  rep(i,0,N) cin >> X[i], X[i]--;
  int res = N;

  rep(i,0,N) {
    if (X[i] != -1) {
      --res;
      int at = i;
      while (X[at] != -1) {
        int nat = X[at];
        X[at] = -1;
        at = nat;
      }
    }
  }

  cout << res << endl;
}
