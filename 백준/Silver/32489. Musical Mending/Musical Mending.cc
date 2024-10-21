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
#define int long long

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;
const int MAXN = (1<<18)+5;
const int D = 20;

int N;
vector<int> V;

int sol(int a){
    int ret=0;
    for(auto i : V){
        ret+=abs(i-a);
        a++;
    }
    return ret;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        V.push_back(a);
    }

    int lo=-400000;
    int hi=400000;
    while(hi-lo>3){
        int q=(lo*2+hi)/3;
        int p=(lo+hi*2)/3;
        if(sol(q)>sol(p)){
            lo=q;
        }
        else hi=p;
    }
    int ans=1e18;
    for(int i=lo; i<=hi; i++){
        ans=min(ans, sol(i));
    }
    cout << ans;
    
    return 0;
}