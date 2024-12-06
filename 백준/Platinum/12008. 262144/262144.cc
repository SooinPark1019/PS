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
int leftDP[65][300005];
int rightDP[65][300005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    memset(leftDP, -1, sizeof(leftDP));
    memset(rightDP, -1, sizeof(rightDP));
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        leftDP[a][i]=i;
        rightDP[a][i]=i;
    }
    int ans=0;
    for(int i=1; i<60; i++){
        for(int j=0; j<N; j++){
            //cout << i << " " << j << " " << leftDP[i][j] << " " << rightDP[i][j] << "\n";
            if(j>0&&leftDP[i][j]!=-1&&rightDP[i][j-1]!=-1){
                leftDP[i+1][rightDP[i][j-1]]=leftDP[i][j];
                rightDP[i+1][leftDP[i][j]]=rightDP[i][j-1];
            }
            if(j<N-1&&rightDP[i][j]!=-1&&leftDP[i][j+1]!=-1){
                leftDP[i+1][rightDP[i][j]]=leftDP[i][j+1];
                rightDP[i+1][leftDP[i][j+1]]=rightDP[i][j];
            }
        }
    }
    for(int i=1; i<=60; i++){
        for(int j=0; j<N; j++){
            if(leftDP[i][j]!=-1||rightDP[i][j]!=-1) ans=i;
        }
    }
    cout << ans;
    return 0;
}
