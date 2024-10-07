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
const int MAXN = 1e9+7;
const int D = 20;

long long fastmul(long long a, long long b){
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==1) return fastmul(a, b-1)*a%mod;
    else{
        long long c=fastmul(a, b/2);
        return c*c%mod;
    }
}

int fac[1000005];
int inv_fac[1000005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    fac[0]=1;
    for(int i=1; i<=1000000; i++)
        fac[i]=fac[i-1]*i%mod;
    inv_fac[1000000]=fastmul(fac[1000000], mod-2);
    for(int i=999999; i>=0; i--)
        inv_fac[i]=inv_fac[i+1]*(i+1)%mod;

    vector<int> V;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        V.push_back(a/2);
    }
    int ans=1;
    for(int i=0; i<N-1; i++){
        if(V[i]<V[i+1]){
            ans*=fac[V[i+1]-1]*inv_fac[V[i]-1]%mod*inv_fac[V[i+1]-V[i]]%mod;
            ans%=mod;
        }
        else{
            ans*=fac[V[i]]*inv_fac[V[i+1]]%mod*inv_fac[V[i]-V[i+1]]%mod;
            ans%=mod;
        }
    }

    cout << ans;
    
    return 0;
}