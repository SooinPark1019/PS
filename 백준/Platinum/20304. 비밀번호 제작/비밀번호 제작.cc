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
const ll mod = 998244353;
const int MAXN = (1<<20)+5;
const int D = 20;

/*
*/

int dis[MAXN];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    queue<int> Q;

    memset(dis, -1, sizeof(dis));

    for(int i=0; i<M; i++){
        int a;
        cin >> a;
        dis[a]=0;
        Q.push(a);
    }

    while(!Q.empty()){
        int x=Q.front();
        Q.pop();
        int a=1;
        while(a<=N){
            int y=x^a;
            if(y<=N&&dis[y]==-1){
                dis[y]=dis[x]+1;
                Q.push(y);
            }
            a<<=1;
        }
    }

    int ans=0;

    for(int i=0; i<=N; i++){
        ans=max(ans, dis[i]);
    }
    
    cout << ans;
    return 0;
}