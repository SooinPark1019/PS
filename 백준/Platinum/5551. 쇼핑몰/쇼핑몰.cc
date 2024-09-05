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

vector<pll> graph[3005];

struct edge{
    ll a, b, c;
};

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;
    vector<edge> V;
    for(int i=0; i<M; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
        V.push_back({a, b, c});
    }
    priority_queue<pll, vector<pll>, greater<pll>> PQ;
    vector<ll> dis(N+5, 1e18);
    for(int i=0; i<K; i++){
        int a;
        cin >> a;
        dis[a]=0;
        PQ.push({0, a});
    }
    while(!PQ.empty()){
        ll cur_cost=PQ.top().first;
        ll cur_pos=PQ.top().second;
        PQ.pop();
        if(dis[cur_pos]!=cur_cost) continue;
        for(auto p : graph[cur_pos]){
            int nxt_cost=p.second;
            int nxt_pos=p.first;
            if(dis[nxt_pos]>cur_cost+nxt_cost){
                dis[nxt_pos]=cur_cost+nxt_cost;
                PQ.push({dis[nxt_pos], nxt_pos});
            }
        }
    }
    ll ans=0;
    for(int i=1; i<=N; i++){
        ans=max(ans, dis[i]);
    }
    for(auto e : V){
        if(min(dis[e.a], dis[e.b])+e.c<=max(dis[e.a], dis[e.b])) continue;
        ans=max(ans, max(dis[e.a], dis[e.b])+(e.c-(max(dis[e.a], dis[e.b])-min(dis[e.a], dis[e.b]))+1)/2);
    }
    cout << ans;
}
