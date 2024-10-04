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
const int MAXN = 2e5+5;
const int D = 20;

vector<pii> graph[1000005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<int> ans(N+1);
    priority_queue<pii> PQ;
    for(int i=1; i<=N; i++){
        cin >> ans[i];
        PQ.push({ans[i], i});
    }
    for(int i=0; i<M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    while(!PQ.empty()){
        int cur_max=PQ.top().first;
        int cur_node=PQ.top().second;
        PQ.pop();
        if(ans[cur_node]!=cur_max) continue;
        for(auto p : graph[cur_node]){
            int nxt_node=p.first;
            if(ans[nxt_node]<cur_max-p.second){
                ans[nxt_node]=cur_max-p.second;
                PQ.push({ans[nxt_node], nxt_node});
            }
        }
    }
    for(int i=1; i<=N; i++) cout << ans[i] << "\n";
    return 0;
}