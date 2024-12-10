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
            for(int a=1; a<=N; a++){
                for(int i=0; i<=N+1; i++){
                    for(int j=0; j<=N+1; j++){
                        DP[i][j][0]=1e18;
                        DP[i][j][1]=1e18;
                    }
                }
                DP[a-1][a+1][0]=0;
                for(int i=0; i<=N; i++){
                    for(int j=0; j+i<=N+1; j++){
                        for(int k=0; k<2; k++){
                            if(DP[j][i+j][k]==1e18) continue;
                            int cur;
                            if(k==0) cur=j+1;
                            else cur=j+i-1;
                            if(j>0&&abs(V[cur]-V[j])>=DP[j][i+j][k]*2){
                                DP[j-1][i+j][0]=min(DP[j-1][i+j][0], abs(V[cur]-V[j]));
                            }
                            if(i+j<=N&&abs(V[cur]-V[i+j])>=DP[j][i+j][k]*2){
                                DP[j][i+j+1][1]=min(DP[j][i+j+1][1], abs(V[cur]-V[i+j]));
                            }
                        }
                    }
                }
                int flag=0;
                for(int i=0; i<2; i++){
                    if(DP[0][N+1][i]!=1e18){
                        flag=1;
                        break;
                    }
                }
                if(flag==0) cout << "NO\n";
                else cout << "YES\n";
            }
        }
    }
    return 0;
}
