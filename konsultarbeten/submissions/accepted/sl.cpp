#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef vector<int> vi;

int main() {
	int N;
	cin >> N;
	vector<ll> a(N);
	rep(i,0,N) cin >> a[i];
	sort(all(a));
	vi dp(N+1);
	for (int i = N-1; i >= 0; i--) {
		ll t = a[i];
		int r = 0;
		rep(j,2,5) {
			int k = (int)(lower_bound(all(a), t + 100'000 * j) - a.begin());
			r = max(r, dp[k] + j);
		}
		dp[i] = r;
	}
	cout << dp[0] << endl;
	exit(0);
}
