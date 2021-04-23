#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct H {
	typedef uint64_t ull;
	ull x; H(ull x=0) : x(x) {}
#define OP(O,A,B) H operator O(H o) { ull r = x; asm \
	(A "addq %%rdx, %0\n adcq $0,%0" : "+a"(r) : B); return r; }
	OP(+,,"d"(o.x)) OP(*,"mul %1\n", "r"(o.x) : "rdx")
	H operator-(H o) { return *this + ~o.x; }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)

struct HashInterval {
	vector<H> ha, pw;
	HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
		pw[0] = 1;
		rep(i,0,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};

int N, M;
string s;

int sol(vi& P) {
	vi dup = P;
	for (int i : P) dup.push_back(i + N);
	vector<vi> nx(17, vi(sz(dup)));
	int ptr = 0;
	rep(i,0,sz(dup)) {
		while (ptr != sz(dup) && dup[ptr] < dup[i] + M) ++ptr;
		nx[0][i] = ptr;
	}
	rep(jmp,1,17) {
		rep(i,0,sz(dup)) {
			int x = nx[jmp - 1][i];
			if (x != sz(dup)) x = nx[jmp - 1][x];
			nx[jmp][i] = x;
		}
	}

	int mx = 0;
	rep(i,0,sz(P)) {
		int res = 0;
		int at = i;
		for (int jmp = 16; jmp >= 0; --jmp) {
			if (nx[jmp][at] <= i + sz(P)) {
				at = nx[jmp][at];
				res += 1 << jmp;
			}
		}
		mx = max(mx, res);
	}
	return mx;
}

bool isless(HashInterval& ha, int a, int b) {
  rep(i,0,M)
    if (s[a + i] != s[b + i]) return s[a + i] < s[b + i];
  assert(false);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	cin >> N >> M;

	cin >> s;
	rep(i,0,M-1) s.push_back(s[i]);
	
	HashInterval ha(s);
	vector<H> hashes;
	rep(i,0,N) {
		hashes.push_back(ha.hashInterval(i, i + M));
	}
	map<H, vi> idxs;
	rep(i,0,N) idxs[hashes[i]].push_back(i);

	vi res;
	int best = 0;
	for (auto& it : idxs) {
		int ans = sol(it.second);
		cerr << "occuring at " << it.second[0] << " has " << ans << endl;
		if (ans > best) {
			res.clear();
			best = ans;
		}
		if (ans == best) res.push_back(it.second[0]);
	}

	int ans = res[0];
	rep(i,1,sz(res)) {
		if (isless(ha, res[i], ans)) {
			cerr << "starting at " << res[i] << " is less than " << ans << endl;
			ans = res[i];
		}
	}
	rep(i,0,M) cout << s[ans + i];
	cout << endl;
}
