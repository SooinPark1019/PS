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
*/

struct edge{
    int e, w, num;
};

struct st{
    int cost, prevnode, curnode, edgenum;
};

struct comp{
    bool operator()(st A, st B){
        return B.cost<A.cost;
    }
};

int score[5005];
vector<edge> graph[2005];
vector<pii> tree[2005];

int sol(int cur_node, int par){
    int ret=1;
    for(auto i : tree[cur_node]){
        if(i.first==par) continue;
        int temp=sol(i.first, cur_node);
        score[i.second]+=temp;
        ret+=temp;
    }
    return ret;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for(int i=0; i<M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c, i+1});
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++) tree[j].clear();
        vector<int> dis(N+1, 1e18);
        dis[i]=0;
        priority_queue<st, vector<st>, comp> PQ;
        PQ.push({dis[i], -1, i, -1});
        while(!PQ.empty()){
            int cur_cost=PQ.top().cost;
            int cur_node=PQ.top().curnode;
            int prev_node=PQ.top().prevnode;
            int edge_num=PQ.top().edgenum;
            PQ.pop();
            if(dis[cur_node]!=cur_cost){
                continue;
            }
            if(prev_node!=-1) tree[prev_node].push_back({cur_node, edge_num});
            for(auto e : graph[cur_node]){
                int next_node=e.e;
                int next_cost=e.w;
                if(dis[next_node]>next_cost+cur_cost){
                    dis[next_node]=next_cost+cur_cost;
                    PQ.push({dis[next_node], cur_node, next_node, e.num});
                }
            }
        }

        sol(i, -1);
    }

    vector<int> ans;
    int ansscore=-1;

    for(int i=1; i<=M; i++){
        //cout << "i : " << i << " score : " << score[i] << "\n";
        if(ansscore<score[i]){
            ansscore=score[i];
            ans.clear();
            ans.push_back(i);
        }
        else if(ansscore==score[i]){
            ans.push_back(i);
        }
    }

    cout << ans.size() << "\n";
    for(auto i : ans) cout << i << " ";
    return 0;
}
