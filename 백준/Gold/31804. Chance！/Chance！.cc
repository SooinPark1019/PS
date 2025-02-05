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
//#define sz(x) (int)x.size()

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
typedef complex<double> cpx;
//typedef __int128 i128;
typedef long double ld;
typedef pair<double, int> pdl;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 1e9+7;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
DP[i]=첫번째 재료의 가치가 i일 때 두번째 재료의 가능한 최대 가치

두 차원 모두 양수인 거는 당연히 그대로 합치고
그렇지 않을 경우 취할 차원을 선택

나머지는 취할 차원만 취하거나 아니면 둘다 취해야 함
*/
int vis[1000005][2];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B;
    cin >> A >> B;
    queue<pii> Q;
    Q.push({A, 0});
    memset(vis, -1, sizeof(vis));

    vis[A][0]=0;

    while(!Q.empty()){
        int a=Q.front().first;
        int b=Q.front().second;
        Q.pop();
        if(b==0&&a*10<=B&&vis[a*10][1]==-1){
            vis[a*10][1]=vis[a][b]+1;
            Q.push({a*10, 1});
        }
        if(a+1<=B&&vis[a+1][b]==-1){
            vis[a+1][b]=vis[a][b]+1;
            Q.push({a+1, b});
        }
        if(a*2<=B&&vis[a*2][b]==-1){
            vis[a*2][b]=vis[a][b]+1;
            Q.push({a*2, b});
        }
    }

    int ans=1e18;
    if(vis[B][0]!=-1) ans=min(ans, vis[B][0]);
    if(vis[B][1]!=-1) ans=min(ans, vis[B][1]);

    cout << ans;

    return 0;
}
