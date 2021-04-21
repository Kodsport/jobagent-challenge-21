#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// Arithmetic mod 2^64-1. 2x slower than mod 2^64 and more
// code, but works on evil test data (e.g. Thue-Morse, where
// ABBA... and BAAB... of length 2^10 hash the same mod 2^64).
// "typedef ull H;" instead if you think test data is random,
// or work mod 10^9+7 if the Birthday paradox is not a problem.
typedef uint64_t ull;
struct H {
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

vector<H> getHashes(string& str, int length) {
	if (sz(str) < length) return {};
	H h = 0, pw = 1;
	rep(i,0,length)
		h = h * C + str[i], pw = pw * C;
	vector<H> ret = {h};
	rep(i,length,sz(str)) {
		ret.push_back(h = h * C + str[i] - pw * str[i-length]);
	}
	return ret;
}

struct SuffixArray {
	vi sa, lcp;
	SuffixArray(string& s, int lim=256) { // or basic_string<int>
		int n = sz(s) + 1, k = 0, a, b;
		vi x(all(s)+1), y(n), ws(max(n, lim)), rank(n);
		sa = lcp = y, iota(all(sa), 0);
		for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
			p = j, iota(all(y), n - j);
			rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
			fill(all(ws), 0);
			rep(i,0,n) ws[x[i]]++;
			rep(i,1,lim) ws[i] += ws[i - 1];
			for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
			rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
				(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
		}
		rep(i,1,n) rank[sa[i]] = i;
		for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
			for (k && k--, j = sa[rank[i] - 1];
					s[i + k] == s[j + k]; k++);
	}
};

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N, M;
	cin >> N >> M;
	string str;
	cin >> str;
	str += str;
	vector<H> ha = getHashes(str, M);
	map<ull, vi> has;
	rep(i,0,N) {
		has[ha[i].get()].push_back(i);
	}

	int ans = -1;
	set<int> cands;
	for (auto& pa : has) {
		vi v = move(pa.second);
		int n = sz(v);
		rep(i,0,n)
			v.push_back(v[i] + N);
		vi next(2*n+1);
		next[2*n] = 2*n;
		rep(i,0,2*n)
			next[i] = (int)(lower_bound(all(v), v[i] + M) - v.begin());
		vector<vi> nexts(20);
		nexts[0] = next;
		rep(i,1,20) {
			auto &v = nexts[i-1], &w = nexts[i];
			w.resize(2*n+1);
			rep(j,0,2*n+1)
				w[j] = v[v[j]];
		}
		int best = -1;
		rep(i,0,n) {
			int steps = 0, at = i, target = i + n;
			for (int j = 19; j >= 0; j--) {
				int pot = nexts[j][at];
				if (pot <= target) {
					at = pot;
					steps += 1 << j;
				}
			}
			best = max(best, steps);
		}
		if (best > ans) {
			ans = best;
			cands.clear();
		}
		if (best == ans) {
			cands.insert(v[0]);
		}
	}

	cerr << "occurs " << ans << " times" << endl;
	assert(!cands.empty());

	SuffixArray sa(str);
	rep(i,0,sz(sa.sa)) {
		int ind = sa.sa[i];
		if (cands.count(ind)) {
			assert(ind < N);
			cout << str.substr(ind, M) << endl;
			return 0;
		}
	}
	assert(false);
}
