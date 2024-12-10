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
const ll mod = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
*/
int DP[30][30][2]={};
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--){
        int N;
        cin >> N;
        vector<int> V(N+2);
        for(int i=1; i<=N; i++){
            cin >> V[i];
        }
        if(N>=25){
            for(int i=0; i<N; i++) cout << "NO\n";
        }
        else{
            memset(DP, -1, sizeof(DP));
            DP[1][N][0]=1e9;
            DP[1][N][1]=1e9;
            for(int i=N-1; i>0; i--){
                for(int j=1; j+i<=N; j++){
                    for(int k=0; k<2; k++){
                        if(DP[j][i+j][k]==-1) continue;
                        //cout << j << " " << i+j << " " << k << " " << DP[j][j+i][k] << "\n";
                        if(k==0){
                            if(abs(V[j]-V[j+1])*2<=DP[j][i+j][k]){
                                DP[j+1][i+j][0]=max(DP[j+1][i+j][0], abs(V[j]-V[j+1]));
                            }
                            if(abs(V[j]-V[i+j])*2<=DP[j][i+j][k]){
                                DP[j+1][i+j][1]=max(DP[j+1][i+j][1], abs(V[j]-V[i+j]));
                            }
                        }
                        else{
                            if(abs(V[j]-V[i+j])*2<=DP[j][i+j][k]){
                                DP[j][i+j-1][0]=max(DP[j][i+j-1][0], abs(V[j]-V[i+j]));
                            }
                            if(abs(V[i+j-1]-V[i+j])*2<=DP[j][i+j][k]){
                                DP[j][i+j-1][1]=max(DP[j][i+j-1][1], abs(V[i+j-1]-V[i+j]));
                            }
                        }
                    }
                }
            }
            for(int i=1; i<=N; i++){
                if(DP[i][i][0]!=-1||DP[i][i][1]!=-1) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }
    return 0;
}
