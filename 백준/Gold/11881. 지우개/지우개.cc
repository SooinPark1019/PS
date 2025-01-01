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
const ll mod = 1e9+7;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
DP[i][j]=i번째 지우개까지 봤을 때 j개를 고르는 모든 경우의 수의 합
*/

int DP[100005][3];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<int> V;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        V.push_back(a);
    }
    sort(all(V));
    for(int i=0; i<N; i++){
        //cout << DP[i][0] << " " << DP[i][1] << " " << DP[i][2] << "\n";
        int a=lower_bound(all(V), V[i])-V.begin();
        for(int j=1; j<3; j++){
            if(i>0){
                DP[i+1][j]+=DP[i][j];
                DP[i+1][j]%=mod;
            }
            DP[i+1][j]+=DP[a][j-1]*V[i];
            DP[i+1][j]%=mod;
        }
        DP[i+1][0]+=V[i]+DP[i][0];
        DP[i+1][0]%=mod;
    }
    cout << DP[N][2];
    return 0;
}
