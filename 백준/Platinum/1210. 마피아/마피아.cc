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
const int MAX = 500 + 2, S = MAX - 2, T = MAX - 1;
int N, cap[MAX][MAX], flow[MAX][MAX], level[MAX], work[MAX];
bool visited[MAX];
vector<int> graph[MAX];

bool dinic_bfs(){
    memset(level, -1, sizeof(level));
    level[S]=0;
    queue<int> Q;
    Q.push(S);
    while(!Q.empty()){
        int x=Q.front();
        Q.pop();
        for(auto i : graph[x]){
            if(level[i]<0 && cap[x][i]>flow[x][i]){
                level[i] = level[x]+1;
                Q.push(i); 
            }
        }
    }
    return level[T] != -1;
}

pii dinic_dfs(int x, int dest, int max_flow, int block){
    if(x==dest) return {max_flow, block};
    for(int& i=work[x]; i<graph[x].size(); i++){
        int nx=graph[x][i];
        if(level[nx]==level[x]+1&&cap[x][nx]>flow[x][nx]){
            int new_flow, new_block;
            if(max_flow>cap[x][nx]-flow[x][nx]){
                tie(new_flow, new_block)=dinic_dfs(nx, dest, cap[x][nx]-flow[x][nx], x);
            }
            else{
                tie(new_flow, new_block)=dinic_dfs(nx, dest, max_flow, block);
            }
            if(new_flow>0){
                flow[x][nx]+=new_flow;
                flow[nx][x]-=new_flow;
                return {new_flow, new_block};
            }
        }
    }
    return {0, -1};
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int start, end;
    cin >> start >> end;

    graph[S].push_back(start);
    graph[start].push_back(S);
    cap[S][start]=1e18;

    graph[T].push_back(end+N);
    graph[end+N].push_back(T);
    cap[end+N][T]=1e18;

    for(int i=1; i<=N; i++){
        int cost;
        cin >> cost;
        graph[i].push_back(i+N);
        graph[i+N].push_back(i);
        cap[i][i+N]=cost;
    }

    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        graph[a+N].push_back(b);
        graph[b+N].push_back(a);
        graph[b].push_back(a+N);
        graph[a].push_back(b+N);
        cap[a+N][b]=1e18;
        cap[b+N][a]=1e18;
    }

    vector<int> ans;

    while(dinic_bfs()){
        memset(work, 0, sizeof(work));
        while(1){
            pii A=dinic_dfs(S, T, 1e18, -1);
            if(A.first==0) break;
        }
    }

    queue<int> Q;
    Q.push(S);
    vector<int> vis(505);
    vis[S]=1;

    while(!Q.empty()){
        int x=Q.front();
        Q.pop();
        //cout << "x : " << x << "\n";
        for(auto i : graph[x]){
            if(vis[i]||cap[x][i]<=flow[x][i]) continue;
            //cout << "i : " << i << " cap : " << cap[x][i] << " flow : " << flow[x][i] << "\n";
            vis[i]=1;
            Q.push(i);
        }
    }

    for(int i=1; i<=N; i++){
        if(vis[i]==1&&vis[i+N]==0) cout << i << " ";
    }
    
    return 0;
}
