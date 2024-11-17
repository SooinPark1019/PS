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

/*
*/

int DP[100005][10];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<string> V;
    for(int i=0; i<N; i++){
        string S;
        cin >> S;
        V.push_back(S);
    }
    string S="UNIST";
    DP[0][0]=1;
    for(int i=0; i<N; i++){
        for(int j=0; j<=5; j++){
            DP[i+1][j]+=DP[i][j];
            DP[i+1][j]%=mod;
            for(int k=0; k<5; k++){
                if(k==V[i].length()||j+k==5||V[i][k]!=S[j+k]) break;
                DP[i+1][j+k+1]+=DP[i][j];
                DP[i+1][j+k+1]%=mod;
            }
        }
    }

    cout << DP[N][5];

    return 0;
}