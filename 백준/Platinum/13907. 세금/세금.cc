#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-12;
const i128 LNF = 1e18;
const int mod = 998244353;

struct edge{
    int cost, goal, indegree;
};

struct comp{
    bool operator()(edge A, edge B){
        return B.cost<A.cost;
    }
};

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;
    int S, D;
    cin >> S >> D;
    vector<pair<int, int>> graph[1005];
    for(int i=0; i<M; i++){
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({w, b});
        graph[b].push_back({w, a});
    }
    int dis[1005][1005];
    for(int i=0; i<=N; i++){
        for(int j=1; j<=N; j++){
            dis[i][j]=987654321;
        }
    }
    dis[0][S]=0;
    priority_queue<edge, vector<edge>, comp> PQ;
    PQ.push({0, S, 0});
    while(!PQ.empty()){
        int cost=PQ.top().cost;
        int start=PQ.top().goal;
        int indegree=PQ.top().indegree;
        PQ.pop();
        if(dis[indegree][start]!=cost) continue;
        for(auto e : graph[start]){
            int line_cost=e.first;
            int goal=e.second;
            if(dis[indegree+1][goal]>cost+line_cost){
                dis[indegree+1][goal]=cost+line_cost;
                PQ.push({cost+line_cost, goal, indegree+1});
            }
        }
    }
    int totaltax=0;
    int ans=987654321;
    for(int i=0; i<=N; i++){
        ans=min(ans, dis[i][D]);
    }
    cout << ans << "\n";
    for(int i=0; i<K; i++){
        int p;
        cin >> p;
        totaltax+=p;
        ans=987654321;
        for(int i=0; i<=N; i++){
            ans=min(ans, dis[i][D]+totaltax*i);
        }
        cout << ans << "\n";
    }
    return 0;
}

