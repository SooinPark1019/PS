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
//#define int long long
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
const ll mod = 10007;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
*/
int DP[5005][10][(1<<9)];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    DP[0][0][0]=1;
    for(int i=0; i<5000; i++){
        for(int j=0; j<8; j++){
            for(int k=0; k<(1<<9); k++){
                if(DP[i][j][k]==0) continue;
                //cout << i << " " << j << " " << k << " " << DP[i][j][k] << "\n";
                if((k&(1<<j))!=0){
                    DP[i][j+1][k]+=DP[i][j][k];
                    DP[i][j+1][k]%=mod;
                    continue;
                }
                else{
                    DP[i][j+1][k]+=DP[i][j][k];
                    DP[i][j+1][k]%=mod;
                    if(j%3!=2&&(k&(1<<(j+1)))==0){
                        DP[i][j+1][k+(1<<j)+(1<<(j+1))]+=DP[i][j][k];
                        DP[i][j+1][k+(1<<j)+(1<<(j+1))]%=mod;
                    }
                    if(j+3<9&&(k&(1<<(j+3)))==0){
                        DP[i][j+1][k+(1<<j)+(1<<(j+3))]+=DP[i][j][k];
                        DP[i][j+1][k+(1<<j)+(1<<(j+3))]%=mod;
                    }
                }
            }
        }
        for(int k=0; k<(1<<9); k++){
            if(DP[i][8][k]==0) continue;
            int a=(1<<9)-1-k;
            DP[i+1][0][a]+=DP[i][8][k];
            DP[i+1][0][a]%=mod;
        }
    }
    int TC;
    cin >> TC;
    while(TC--){
        int N;
        cin >> N;
        cout << DP[N][0][0] << "\n";
    }
    return 0;
}
