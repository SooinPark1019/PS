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
//#define int long long

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
DP[i]=첫번째 재료의 가치가 i일 때 두번째 재료의 가능한 최대 가치

두 차원 모두 양수인 거는 당연히 그대로 합치고
그렇지 않을 경우 취할 차원을 선택

나머지는 취할 차원만 취하거나 아니면 둘다 취해야 함
*/

const int MAX=250+2, S=MAX-2, T=MAX-1;

int cap[MAX][MAX], flow[MAX][MAX], level[MAX], work[MAX];
vector<int> graph[MAX];
vector<array<int, 3>> edges;

bool dinic_bfs(){
    memset(level, -1, sizeof(level));
    level[S]=0;

    queue<int> Q;
    Q.push(S);
    while(!Q.empty()){
        int x=Q.front();
        Q.pop();
        for(auto i : graph[x]){
            if(level[i]<0&&cap[x][i]>flow[x][i]){
                level[i]=level[x]+1;
                Q.push(i);
            }
        }
    }
    return level[T]!=-1;
}

int dinic_dfs(int x, int dest, int max_flow){
    //cout << "x : " << x << endl;
    if(x==dest) return max_flow;
    for(int& i=work[x]; i<graph[x].size(); i++){
        int nx=graph[x][i];
        //cout << "nx : " << nx << endl;
        if(level[nx]==level[x]+1&&cap[x][nx]>flow[x][nx]){
            int new_flow=dinic_dfs(nx, dest, min(max_flow, cap[x][nx]-flow[x][nx]));
            if(new_flow>0){
                flow[x][nx]+=new_flow;
                flow[nx][x]-=new_flow;
                return new_flow;
            }
        }
    }
    return 0;
}

int dis[MAX][MAX];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, C, M;
    cin >> K >> C >> M;

    for(int i=1; i<=K+C; i++){
        for(int j=1; j<=K+C; j++){
            cin >> dis[i][j];
            if(i!=j&&dis[i][j]==0) dis[i][j]=1e9;
        }
    }

    for(int k=1; k<=K+C; k++){
        for(int i=1; i<=K+C; i++){
            for(int j=1; j<=K+C; j++){
                if(dis[i][k]+dis[k][j]<dis[i][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }

    for(int i=1; i<=K; i++){
        for(int j=K+1; j<=K+C; j++){
            edges.push_back({dis[i][j], i, j});
        }
    }

    sort(all(edges));

    int left=1;
    int right=edges.size();
    int ans=1e18;
    while(left<=right){
        int mid=(left+right)>>1;
        //cout << left << " " << right << " " << mid << endl;
        for(int i=1; i<MAX; i++){
            vector<int> temp;
            swap(graph[i], temp);
        }
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));
        for(int i=1; i<=K; i++){
            graph[S].push_back(i);
            graph[i].push_back(S);
            cap[S][i]=M;
        }

        for(int i=K+1; i<=K+C; i++){
            graph[i].push_back(T);
            graph[T].push_back(i);
            cap[i][T]=1;
        }

        for(int i=0; i<mid; i++){
            int u=edges[i][1];
            int v=edges[i][2];
            graph[u].push_back(v);
            graph[v].push_back(u);
            cap[u][v]=1;
        }
        int max_flow=0;
        while(dinic_bfs()){
            memset(work, 0, sizeof(work));
            while(1){
                int new_flow=dinic_dfs(S, T, 1e9);
                //cout << "new_flow : " << new_flow << endl;
                if(new_flow==0) break;
                max_flow+=new_flow;
            }
        }
        //cout << "max_flow : " << max_flow << endl;
        if(max_flow>=C){
            ans=min(ans, edges[mid-1][0]);
            right=mid-1;
        }
        else left=mid+1;
    }

    cout << ans;

    return 0;
}
