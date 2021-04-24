#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define len(x) x.size()
#define ll long long
ll max(ll a,ll b){if(a>b) return a; return b;}

ll inf = pow(10,18);

vector<ll> jobs;

ll search(ll value, ll index){
    rep(j,index, len(jobs)){
        if (jobs[j] >= value) return j;
    }
    return (len(jobs) - 1);
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
        ll index = search(tim + 1, i+1);
        mest_cash[index] = max(mest_cash[index], mest_cash[i]);
        rep(j,2,5){
            index = search(tim + j*100000, index);
            mest_cash[index] = max(mest_cash[index], mest_cash[i]+j);
        }
    }
    cout << mest_cash[len(mest_cash) -1] << endl;
}
