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

int DP[2][2][2005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<pii> V;
    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        V.push_back({a+1000, b+1000});
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            for(int k=0; k<=2000; k++){
                DP[i][j][k]=1e18;
            }
        }
    }
    DP[0][0][1000]=0;
    DP[1][0][1000]=0;
    for(int j=0; j<N; j++){
        for(int i=0; i<2; i++){
            for(int k=0; k<=2000; k++){
                if(DP[i][0][k]==1e18) continue;
                //cout << i << " " << j << " " << k << " " << DP[i][j][k] << "\n";
                int x, y;
                if(j==0){
                    x=1000;
                    y=1000;
                }
                else{
                    if(i==1){
                        x=V[j-1].first;
                        y=k;
                    }
                    else{
                        x=k;
                        y=V[j-1].second;
                    }
                }
                //cout << x << " " << y << "\n";
                DP[1][1][y]=min(DP[1][1][y], DP[i][0][k]+abs(V[j].first-x));
                DP[0][1][x]=min(DP[0][1][x], DP[i][0][k]+abs(V[j].second-y));
            }
        }
        for(int i=0; i<2; i++){
            for(int k=0; k<=2000; k++){
                DP[i][0][k]=DP[i][1][k];
                DP[i][1][k]=1e18;
            }
        }
    }
    int ans=1e18;
    for(int i=0; i<2; i++){
        for(int k=0; k<=2000; k++){
            ans=min(ans, DP[i][0][k]);
        }
    }
    cout << ans;
}