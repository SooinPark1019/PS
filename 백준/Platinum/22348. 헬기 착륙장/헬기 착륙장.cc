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

int DP[505][50005];
int prefix[505][50005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    DP[0][0]=1;
    for(int i=0; i<500; i++){
        for(int j=0; j<50000; j++){
            if(DP[i][j]==0) continue;
            if(j+i+1<=50000){
            DP[i+1][j+i+1]+=DP[i][j];
            DP[i+1][j+i+1]%=mod;
            }
            DP[i+1][j]+=DP[i][j];
            DP[i+1][j]%=mod;
        }
    }
    for(int i=1; i<=500; i++){
        for(int j=0; j<=50000; j++){
            prefix[i][j]=DP[i][j];
            if(j>0) prefix[i][j]+=prefix[i][j-1];
            prefix[i][j]%=mod;
        }
    }
    
    int TC;
    cin >> TC;
    while(TC--){
        int a, b;
        cin >> a >> b;
        int ans=0;
        for(int i=1; i<500; i++){
            if(i*(i+1)/2>a+b) break;
            ans+=prefix[i][a];
            ans%=mod;
            if(b<i*(i+1)/2){
                ans-=prefix[i][i*(i+1)/2-b-1];
                ans+=mod;
                ans%=mod;
            }
            //cout << ans << "\n";
        }
        cout << ans << "\n";
    }
    return 0;
}