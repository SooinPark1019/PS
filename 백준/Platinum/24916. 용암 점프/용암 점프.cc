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
int DP[30][30][30]={};
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
                        for(int k=0; k<=N+1; k++){
                            DP[i][j][k]=1e18;
                        }
                    }
                }
                DP[a-1][a][a+1]=0;
                for(int i=0; i<=N; i++){
                    for(int j=0; j+i<=N+1; j++){
                        for(int k=j+1; k<=j+i-1; k++){
                            if(DP[j][k][j+i]==1e18) continue;
                            //cout << "j : " << j << " " << " k : " << k << " j+i : " << j+i << " DP : " << DP[j][k][j+i]  << "\n";
                            //cout << abs(V[j]-V[k]) << "\n";
                            if(j>0&&abs(V[j]-V[k])>=DP[j][k][j+i]*2){
                                DP[j-1][j][j+i]=min(DP[j-1][j][j+i], abs(V[j]-V[k]));
                            }
                            if(j+i<=N&&abs(V[i+j]-V[k])>=DP[j][k][j+i]*2){
                                DP[j][j+i][j+i+1]=min(DP[j][j+i][j+i+1], abs(V[i+j]-V[k]));
                            }
                        }
                    }
                }
                int flag=0;
                for(int i=1; i<=N; i++){
                    if(DP[0][i][N+1]<1e18){
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
