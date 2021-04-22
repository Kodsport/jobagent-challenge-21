#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef uint64_t LL;
static LL mod = pow(10,9) + 7;

LL po(LL a, LL b){
    if (b == 0) return 1;
    LL c = po(a,b/2);
    if (b%2 == 1) return (((c*c)%mod)*a) % mod;
    else return (c*c) % mod; 
}

LL get_hash(LL hash, char in, char out, ll m){
    hash = (hash - (out - 'a')*po(26,m-1)) % mod;
    hash = (hash*26 + (in - 'a')) % mod;
    return hash;
}

int main(){
    ll n, m;
    cin >> n >> m;
    map<LL, ll> occ;
    vector<char> inp;
    vi ans; ll best = 0; 
    
    char c;
    LL hash = 0;
    rep(i,0,n){
        cin >> c; inp.push_back(c);
        if (i<m-1){
            hash = get_hash(hash, c, 'a',m);
        }
        else{
            hash = get_hash(hash, c, inp[i-m], m);
            occ[hash] ++;
            if (occ[hash] > best){best = occ[hash]; ans.clear(); ans.push_back(i - m + 1);}
            else if (occ[hash] == best) ans.push_back(i-m);
        }
    }
    rep(i,0,m-1){
        inp.push_back(inp[i]);
        hash = get_hash(hash, inp[n+i], inp[n-m + i],m);
        occ[hash] ++;
        if (occ[hash] > best){best = occ[hash]; ans.clear(); ans.push_back(n-m+i + 1);}
        else if (occ[hash] == best) ans.push_back(n - m + i);
    }

    string out = ""; rep(i,0,n+1) out += '{';
    trav(i,ans){
        string s = "";
        rep(j,i,i+m){
            s += inp[j];
        }
        if (out.compare(s) > 0){
            out = s;
        }
    }
    cout << out << endl;
}