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

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, W, D;
    cin >> N >> W >> D;
    vector<int> V;
    V.push_back(0);
    for(int i=0; i<N-1; i++){
        int a;
        cin >> a;
        V.push_back(a);
    }
    int maxdis=0;
    for(int i=N-1; i>0; i-=W){
        maxdis+=2*i;
    }
    int ans=0;
    if(D>=maxdis){
        ll total=0;
        for(auto i : V){
            total+=i;
        }
        cout << total;
    }
    else{
        vector<vector<vector<int>>> DP(N+1, vector<vector<int>>(W+1, vector<int>(D+1, -1)));
        DP[N][0][0]=0;
        for(int i=N; i>0; i--){
            for(int j=0; j<=D; j++){
                for(int k=0; k<W; k++){
                    if(DP[i][k][j]==-1) continue;
                    DP[i-1][k][j]=max(DP[i-1][k][j], DP[i][k][j]);
                    if(k==0){
                        if(j+2*(i-1)>D) continue;
                        DP[i-1][(k+1)%W][j+2*(i-1)]=max(DP[i-1][(k+1)%W][j+2*(i-1)], DP[i][k][j]+V[i-1]);
                    }
                    else{
                        DP[i-1][(k+1)%W][j]=max(DP[i-1][(k+1)%W][j], DP[i][k][j]+V[i-1]);
                    }
                }
            }
        }
        for(int i=0; i<=N; i++){
            for(int j=0; j<=D; j++){
                for(int k=0; k<W; k++){
                    ans=max(ans, DP[i][k][j]);
                }
            }
        }
        cout << ans;
    }
    return 0;
}