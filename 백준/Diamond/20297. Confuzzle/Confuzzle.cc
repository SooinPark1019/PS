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
const int MAX = 200005;
const int D = 20;

/*
*/

int N, sub[MAX];
vector<int> graph[MAX];
bool visited[MAX];
int value[MAX];
pii dis[MAX];
int ans=1e18;

int getSub(int x, int px){
    sub[x] = 1;
    for (auto& nx : graph[x]) {
        if (visited[nx] || nx == px) continue;
        sub[x] += getSub(nx, x);
    }
    return sub[x];
}
int getCentroid(int x){  // 조금 더 빠르고 센트로이드를 구할 때마다 getSub을 호출하지 않아도 가능
    for (auto& nx : graph[x]) {
        if (sub[x] < 2 * sub[nx] && sub[nx] < sub[x]) {
            sub[x] -= sub[nx];
            sub[nx] += sub[x];
            return getCentroid(nx);
        }
    }
    return x;
}

void solve(int x, int cur_cent, int par, int cur_dis){
    if(dis[value[x]].first!=cur_cent){
        dis[value[x]].first=cur_cent;
        dis[value[x]].second=cur_dis;
    }
    else{
        ans=min(ans, dis[value[x]].second+cur_dis);
        dis[value[x]].second=min(dis[value[x]].second, cur_dis);
    }
    for(auto i : graph[x]){
        if(i==par||visited[i]) continue;
        solve(i, cur_cent, x, cur_dis+1);
    }
}
void dnc(int x){
    x = getCentroid(x);  // x = getCentroid(x, -1, getSub(x, -1));

    visited[x] = 1;  // 센트로이드가 되었던 정점은 더이상 사용하지 않는 것을 유의
    dis[value[x]]={x, 0};
    for (auto& nx : graph[x]) {
        if (visited[nx]) continue;
        solve(nx, x, x, 1);
    }
    
    for (auto& nx : graph[x]) {
        if (visited[nx]) continue;
        dnc(nx);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i=1; i<=N; i++){
        cin >> value[i];
    }

    for(int i=1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    getSub(1, -1);

    for(int i=1; i<=N; i++){
        dis[i]={-1, -1};
    }
    dnc(1);
    cout << ans;
    return 0;
}