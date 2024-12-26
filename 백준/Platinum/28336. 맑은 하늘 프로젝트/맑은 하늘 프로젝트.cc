#include <ext/rope>
#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
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
const ll mod = 10007;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*

*/
int DP[505][505];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int TC;
    cin >> TC;
    while(TC--){
        int N, K;
        cin >> N >> K;
        vector<pii> V(N+1);
        for(int i=1; i<=N; i++){
            int a, b;
            cin >> a >> b;
            V[i]={a, b};
        }
        sort(all(V));
        for(int i=0; i<=N; i++){
            for(int j=0; j<=K; j++){
                DP[i][j]=1e18;
            }
        }
        DP[0][0]=0;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=K; j++){
                int a=i;
                while(a>0&&V[a].second>=V[i].first){
                    DP[i][j]=min(DP[i][j], DP[a-1][j-1]+V[i].first*(i-a+1));
                    a--;
                }
            }
        }
        int ans=1e18;
        for(int i=0; i<=K; i++){
            ans=min(ans, DP[N][i]);
        }
        cout << ans << "\n";
    }

    return 0;
}
