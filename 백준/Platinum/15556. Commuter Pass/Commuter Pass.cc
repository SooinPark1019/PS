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
//#define sz(x) (int)x.size()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long

using namespace std;

//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
/*#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>//이걸 코드의 윗부분에 추가
void m_erase(ordered_set &OS, int val){
    int index = OS.order_of_key(val);
    ordered_set::iterator it = OS.find_by_order(index);
    if(*it == val) OS.erase(it);
}*/
//다른 건 통상적인 PBDS처럼 사용하면 되지만 erase는 반드시!!! 이 함수를 통해서만 해야 함
//m_erase(OS, 지울 원소)처럼 사용하면 된다. 꼭 주의하자.
//얘네 쓰려면 define int long long 꺼라.

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

int N, M;
int S, T, U, V;
vector<pii> graph[100005];
int disfromS[100005], disfromT[100005], disfromU[100005], disfromV[100005];

void fill_dis(int start, int dis[100005]){
    for(int i=0; i<=N; i++) dis[i]=1e18;
    dis[start]=0;
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    PQ.push({0, start});
    while(!PQ.empty()){
        int cur_node=PQ.top().second;
        int cur_cost=PQ.top().first;
        //cout << "cur node : " << cur_node << " cur cost : " << cur_cost << endl;
        PQ.pop();
        if(dis[cur_node]!=cur_cost) continue;
        for(auto p : graph[cur_node]){
            int nxt_node=p.first;
            int nxt_cost=p.second;
            //cout << "nxt node : " << nxt_node << " " << " nxt cost : " << nxt_cost << endl;
            if(dis[nxt_node]>nxt_cost+cur_cost){
                dis[nxt_node]=nxt_cost+cur_cost;
                PQ.push({dis[nxt_node], nxt_node});
            }
        }
    }
}
int ans=1e18;
pii DP[100005];
pii dfs(int node, int curdis){
    //cout << "node : " << node << endl;
    int& a=DP[node].first;
    int& b=DP[node].second;
    if(a!=-1&&b!=-1){
        return {a, b};
    }
    a=disfromU[node];
    b=disfromV[node];
    for(auto p : graph[node]){
        //cout << p.first << " " << p.second << " " << p.second << " " << disfromS[node] << " " << disfromT[p.first] << endl;
        if(p.second+curdis+disfromT[p.first]==disfromS[T]){
            pii temp=dfs(p.first, curdis+p.second);
            a=min(a, temp.first);
            b=min(b, temp.second);
        }
    }
    ans=min(ans, a+disfromV[node]);
    ans=min(ans, b+disfromU[node]);
    return {a, b};
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> S >> T >> U >> V;

    for(int i=0; i<M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    fill_dis(S, disfromS);
    fill_dis(T, disfromT);
    fill_dis(U, disfromU);
    fill_dis(V, disfromV);

    ans=disfromU[V];

    for(int i=0; i<=N; i++) DP[i]={-1, -1};

    dfs(S, 0);
    cout << ans;

    return 0;
}
