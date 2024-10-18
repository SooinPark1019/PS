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
const ll mod = 987654321;
const int MAXN = (1<<18)+5;
const int D = 20;
int DP[2][10005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    if(N%2!=0) cout << 0 << "\n";
    else{
        for(int i=1; i<=N; i++){
            for(int j=0; j<=i; j++){
                if(j==0||j==i){
                    DP[1][j]=1;
                }
                else{
                    DP[1][j]=(DP[0][j-1]+DP[0][j])%mod;
                }
            }
            for(int j=0; j<=i; j++){
                DP[0][j]=DP[1][j];
            }
        }
        cout << (DP[1][N/2]-DP[1][N/2+1]+mod)%mod;
    }
    
    return 0;
}