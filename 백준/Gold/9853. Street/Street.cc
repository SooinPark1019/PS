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
const ll MAX = 200000;

ll DP[505][505];
ll r[505];

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, T;
    cin >> N >> K >> T;

    for(int i=0; i<N; i++){
        cin >> r[i];
    }

    memset(DP, -1, sizeof(DP));

    DP[0][0]=0;

    for(int i=0; i<N; i++){
        for(int j=0; j<=K; j++){
            //if(DP[i][j]==-1) continue;
            DP[i+1][j]=max(DP[i+1][j], DP[i][j]);
            ll temp=1e18;
            for(ll k=i; k<min(N, i+T); k++){
                temp=min(temp, r[k]);
                DP[k+1][j+1]=max(DP[k+1][j+1], DP[i][j]+temp*(k-i+1));
            }
        }
    }

    cout << DP[N][K];

}
