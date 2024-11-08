#include <ext/rope>
#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define debug1(x,y) cout << x << " :: " << y << " "
#define coutn cout << "\n"
#define debug2 puts("--@222%--")
#define debug3 puts("--@333%--")

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

ll generaterandomprime(){
    uniform_int_distribution<ll> dist((ll)1e9, 2e9);
    ll randnum=dist(mt);
    while(1){
        int flag=0;
        for(ll i=2; i*i<randnum; i++){
            if(randnum%i==0){
                flag=1;
                break;
            }
        }
        if(flag==0) return randnum;
        randnum++;
    }
}

struct Hashing {
    i128 P, M;
    vector<i128> h, p;
    Hashing(i128 P, i128 M) : P(P), M(M) {}
    void build(const string &s){
        int n = s.size();
        h = p = vector<i128>(n+1); p[0] = 1;
        for(int i=1; i<=n; i++) h[i] = (h[i-1] * P + s[i-1]) % M;
        for(int i=1; i<=n; i++) p[i] = p[i-1] * P % M;
    }
    i128 get_hash(int s, int e) const {
        i128 res = (h[e] - h[s-1] * p[e-s+1]) % M;
        return (res + M) % M;
    }
};

i128 mod1=(ll)9223372036854775783;
uniform_int_distribution<ll> small(1e6, 1e7);
i128 key=small(mt);

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;
    cin >> S;
    ll left=1;
    ll right=S.length();
    ll ans=-1;
    Hashing H1(key, mod1);
    H1.build(S);
    //cout << (ll)H1.get_hash(1, 5) << "\n";
    //cout << (ll)H1.get_hash(18, 22) << "\n";
    while(left<=right){
        ll mid=(left+right)/2;
        //cout << mid << "-------\n";
        vector<pair<i128, int>> Hash;
        int flag=0;
        /*for(int i=0; i<=S.length()-mid; i++){
            i128 a=H1.get_hash(i, i+mid-1);
            cout << (ll)a << "\n";
        }*/
        for(int i=0; i<=S.length()-mid; i++){
            i128 a=H1.get_hash(i+1, i+mid);
            Hash.push_back({a, i});
        }
        sort(all(Hash));
        int curl=Hash[0].second;
        for(int i=1; i<Hash.size(); i++){
            if(Hash[i].first!=Hash[i-1].first) curl=Hash[i].second;
            else{
                if(Hash[i].second-curl>=mid){
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1){
            ans=max(ans, mid);
            left=mid+1;
        }
        else right=mid-1;
    }
    if(ans==0) cout << -1;
    else cout << ans;
    return 0;
}
