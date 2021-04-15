#include <bits/stdc++.h>
using namespace std;

#define len(x) x.size()
#define ll long long
#define rep(i, from, to) for (ll i = from; i < (to); ++i)

ll max(ll a,ll b){if(a>b) return a; return b;}

ll inf = 1000000000000000000;

vector<ll> jobs;

ll binsearch(ll val){
    ll left = 0;
    ll right = len(jobs)-1;
    ll mid = -1;

    while (left < right){
        mid = (left + right) / 2;
        if (jobs[mid] < val) left = mid + 1;
        else right = mid;
    }
    return right;
}
int main(){
    int N;
    cin >> N;
    
    vector<long long> mest_cash;
    unordered_map<ll, int> parser;

    rep(i,0,N){
        long long t;
        cin >> t;
        if (parser[t] != 1){
            parser[t] = 1;
            mest_cash.push_back(0);
            jobs.push_back(t);
        }
    }   
    
    mest_cash.push_back(0); jobs.push_back(inf);
    sort(jobs.begin(), jobs.end());

    rep(i,0,len(jobs)-1){
        ll tim = jobs[i];
        ll index = binsearch(tim + 1);
        mest_cash[index] = max(mest_cash[index], mest_cash[i]);
        rep(j,2,5){
            ll index = binsearch(tim + j*100000);
            mest_cash[index] = max(mest_cash[index], mest_cash[i]+j);
        }
    }
    cout << mest_cash[len(mest_cash) -1] << endl;
}
