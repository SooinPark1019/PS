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
const int MAXN = 1e5+5;

int DP[2005][2005][2];
char c[2]={'I', 'O'};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    string S, T;
    cin >> S >> T;

    for(int i=N; i>=0; i--){
        for(int j=M; j>=0; j--){
            for(int k=0; k<2; k++){
                if(i<N&&S[i]==c[k]){
                    DP[i][j][k]=max(DP[i][j][k], 1+DP[i+1][j][k^1]);
                }
                if(j<M&&T[j]==c[k]){
                    DP[i][j][k]=max(DP[i][j][k], 1+DP[i][j+1][k^1]);
                }
            }   
        }
    }

    int ans=0;
    for(int i=0; i<=N; i++){
        for(int j=0; j<=M; j++){
            if(DP[i][j][0]%2==0) ans=max(ans, DP[i][j][0]-1);
            else ans=max(ans, DP[i][j][0]);
        }
    }
    cout << ans;

    return 0;
}