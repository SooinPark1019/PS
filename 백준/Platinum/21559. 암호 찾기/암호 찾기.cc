#include <ext/rope>
#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
//#pragma GCC optimize ("O3")
//#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define zip(v) sort(all(v)); v.erase(unique(all(v)), v.end());
#define int long long
#define sz(x) (int)x.size()

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
typedef complex<double> cpx;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const int mod = 1e9+7;
const int mod2 = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
인접한 두 수가 서로소 -> 자명하게 추가할 필요가 없다
*/

struct Hashing {
    ll P, M;
    vector<ll> h, p;
    Hashing(ll P, ll M) : P(P), M(M){}
    void build(const string &s){
        int n = s.size();
        h = p = vector<long long>(n+1); p[0] = 1;
        for(int i=1; i<=n; i++) h[i] = (h[i-1] * P + s[i-1]) % M;
        for(int i=1; i<=n; i++) p[i] = p[i-1] * P % M;
    }
    ll get_hash(int s, int e) const {
        ll res = (h[e] - h[s-1] * p[e-s+1]) % M;
        return (res + M) % M;
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, K;
    cin >> N >> K;

    string S, T;
    cin >> S >> T;

    Hashing Smod1(57, mod);
    Hashing Smod2(37, mod2);

    Hashing Tmod1(57, mod);
    Hashing Tmod2(37, mod2);

    Smod1.build(S);
    Smod2.build(S);
    
    Tmod1.build(T);
    Tmod2.build(T);

    set<pii> S1;

    for(int i=0; i<=N-K; i++){
        S1.insert({Smod1.get_hash(i+1, i+K), Smod2.get_hash(i+1, i+K)});
    }

    set<pii> S2;

    for(int i=0; i<=N-K; i++){
        pii A={Tmod1.get_hash(i+1, i+K), Tmod2.get_hash(i+1, i+K)};
        if(S1.find(A)!=S1.end()){
            S2.insert(A);
        }
    }

    cout << S2.size();
    
    return 0;
}
