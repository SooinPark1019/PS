#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define all(V) V.begin(), V.end()
#define ll long long
#pragma gcc optimize("O3")
#pragma gcc optimize("Ofast")
#pragma gcc optimize("unroll-loops")

struct edge{
    int g, l, id;
};

vector<edge> graph[100005];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int I, S, L, U;
    cin >> I >> S >> L >> U;

    for(int i=0; i<S; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, 2*c, i});
        graph[b].push_back({a, 2*c, i});
    }

    vector<int> dis(I+5, 1e18);
    dis[0]=0;
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    PQ.push({0, 0});

    while(!PQ.empty()){
        int curnode=PQ.top().second;
        int curdis=PQ.top().first;
        PQ.pop();
        if(dis[curnode]!=curdis) continue;
        for(auto s : graph[curnode]){
            int nxtnode=s.g;
            int nxtcost=s.l;
            if(dis[nxtnode]>curdis+nxtcost){
                dis[nxtnode]=curdis+nxtcost;
                PQ.push({dis[nxtnode], nxtnode});
            }
        }
    }

    set<int> ids;
    for(int i=0; i<I; i++){
        if(dis[i]<U){
            for(auto s : graph[i]){
                ids.insert(s.id);
            }
        }
    }

    cout << ids.size();

    return 0;
}