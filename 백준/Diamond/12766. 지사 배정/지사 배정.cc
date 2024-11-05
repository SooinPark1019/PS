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
const int MAXN = (1<<18)+5;

/*
*/

int DP[5005][5005];
int company[5005];
vector<pii> graph[5005];
vector<pii> revgraph[5005];
vector<int> V;
int prefix[5005];
int N, B, S, R;

void dijkstra(vector<int>& dis, vector<pii> graph[5005]){
    //cout << "!!!!!!!!!!!!\n";
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    PQ.push({0, B+1});
    dis[B+1]=0;
    while(!PQ.empty()){
        int cur_cost=PQ.top().first;
        int cur_node=PQ.top().second;
        PQ.pop();
        if(dis[cur_node]!=cur_cost) continue;
        //cout << "cur : " << cur_cost << " " << cur_node << "\n";
        for(auto p : graph[cur_node]){
            int nxt_cost=p.second;
            int nxt_node=p.first;
            if(dis[nxt_node]>cur_cost+nxt_cost){
                //cout << "nxt : " << nxt_cost << " " << nxt_node << "\n";
                dis[nxt_node]=cur_cost+nxt_cost;
                PQ.push({dis[nxt_node], nxt_node});
            }
        }
    }
}

void sol(int t, int s, int e, int l, int r){
    if(s>e) return;
    int mid=(s+e)/2;
    int ans=-1;
    int opt=-1;
    for(int i=min(r, mid); i>=l; i--){
        int a=prefix[mid];
        if(i>0) a-=prefix[i-1];
        int temp=a*(mid-i);
        if(i>0){
            temp+=DP[t-1][i-1];
        }
        if(ans==-1||ans>temp){
            ans=temp;
            opt=i;
        }
    }   
    assert(opt!=-1);
    //if(opt==-1) return;
    DP[t][mid]=ans;
    sol(t, s, mid-1, l, opt);
    sol(t, mid+1, e, opt, r);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> B >> S >> R;
    for(int i=0; i<R; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b ,c});
        revgraph[b].push_back({a, c});
    }
    vector<int> dis(N+1, 1e18);
    vector<int> revdis(N+1, 1e18);

    dijkstra(dis, graph);
    dijkstra(revdis, revgraph);
    
    for(int i=1; i<=B; i++){
        assert(dis[i]!=1e18&&revdis[i]!=1e18);
        V.push_back(dis[i]+revdis[i]);
    }
    sort(all(V));
    for(int i=0; i<B; i++){
        prefix[i]=V[i];
        if(i>0) prefix[i]+=prefix[i-1];
        DP[1][i]=prefix[i]*i;
    }
    for(int i=2; i<=S; i++){
        sol(i, i-1, B-1, i-1, B-1);
        //cout << DP[i][B-1] << "\n";
    }
    cout << DP[S][B-1];
    return 0;
}