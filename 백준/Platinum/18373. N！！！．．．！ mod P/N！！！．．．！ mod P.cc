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

int fac[1005];

int fastmul(int a, int b, int P){
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0){
        int temp=fastmul(a, b/2, P);
        return temp*temp%P;
    }
    return a*fastmul(a, b-1, P)%P;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, P;
    cin >> N >> K >> P;

    fac[0]=1;
    for(int i=1; i<=12; i++){
        fac[i]=fac[i-1]*i;
    }

    if(N==2){
        cout << 2%P;
        return 0;
    }
    if(N==3){
        N=6;
        K--;
        if(K==1){
            cout << fac[N]%P;
            return 0;
        }
    }

    if(K>=3||N>=13){
        cout << 0 << "\n";
        return 0;
    }
    N=fac[N];
    if(P<=N){
        cout << 0 << "\n";
        return 0;
    }
    if(N==fac[12]){
        int ans=P-1;
        int cur=P-1;
        int temp=1;
        while(cur>N){
            temp*=cur;
            temp%=P;
            cur--;
        }
        ans*=fastmul(temp, P-2, P);
        ans%=P;
        cout << ans;
    }
    else{
        int ans=1;
        for(int i=1; i<=N; i++){
            ans*=i;
            ans%=P;
        }
        cout << ans;
    }

    return 0;
}