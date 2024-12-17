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
const ll mod = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
*/

int fastmul(int a, int b){
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0){
        int temp=fastmul(a, b/2);
        return temp*temp%mod;
    }
    return a*fastmul(a, b-1)%mod;
}
int fac[400005];
int inv_fac[400005];
int bino(int a, int b){
    return fac[a]*inv_fac[b]%mod*inv_fac[a-b]%mod;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    fac[0]=1;
    for(int i=1; i<=400000; i++){
        fac[i]=fac[i-1]*i%mod;
    }

    inv_fac[400000]=fastmul(fac[400000], mod-2);

    for(int i=399999; i>=0; i--){
        inv_fac[i]=inv_fac[i+1]*(i+1)%mod;
    }

    int N;
    cin >> N;
    int total=1;
    int a=0;
    for(int i=0; i<N; i++){
        total*=N;
        total%=mod;
        total*=N;
        total%=mod;
        a*=N*N%mod;
        a%=mod;
        if(i>0){
            a-=N*bino(2*i, i+1)%mod*fastmul(N-1, i-1)%mod*(N-1)%mod*(N-1)%mod;
            a+=mod;
            a%=mod;
        }
        a+=N*bino(2*i, i)%mod*fastmul(N-1, i)%mod;
        a%=mod;
        //cout << total << " " << a << "\n";
        cout << (total-a+mod)%mod << "\n";
    }
    return 0;
}
