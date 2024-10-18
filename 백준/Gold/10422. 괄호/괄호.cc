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
const ll mod = 1e9+7;
const int MAXN = (1<<18)+5;
const int D = 20;
int fac[5005];
int invfac[5005];
int fastmul(int a, int b){
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0){
        int temp=fastmul(a, b/2);
        return temp*temp%mod;
    }
    return a*fastmul(a, b-1)%mod;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    fac[0]=1;
    for(int i=1; i<=5000; i++){
        fac[i]=fac[i-1]*i%mod;
    }
    invfac[5000]=fastmul(fac[5000], mod-2);
    for(int i=4999; i>=0; i--){
        invfac[i]=invfac[i+1]*(i+1)%mod;
    }

    while(TC--){
        int a;
        cin >> a;
        if(a%2!=0) cout << 0 << "\n";
        else cout << fac[a]*fastmul(fac[a/2], mod-2)%mod*fastmul(fac[a/2], mod-2)%mod*fastmul(a/2+1, mod-2)%mod << "\n";
    }
    
    return 0;
}