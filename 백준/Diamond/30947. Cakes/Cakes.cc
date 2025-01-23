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
const int INF = 1e9+7;
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

const int MAX=400+5;

int S=MAX-2;
int T=MAX-1;

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
            if(level[i]<0&&cap[x][i]>flow[x][i]){
                level[i]=level[x]+1;
                Q.push(i);
            }
        }
    }
    return level[T]!=-1;
}

int dinic_dfs(int x, int dest, int max_flow){
    if(x==dest) return max_flow;
    for(int& i=work[x]; i<graph[x].size(); i++){
        int nx=graph[x][i];
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

int cake_profit[205];
int ingredient_cost[205];
int tool_cost[205];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int G, C, Toolcnt;
    cin >> G >> C >> Toolcnt;

    for(int i=1; i<=C; i++){
        cin >> cake_profit[i];
    }

    for(int i=1; i<=G; i++){
        cin >> ingredient_cost[i];
    }

    for(int i=1; i<=Toolcnt; i++){
        cin >> tool_cost[i];
    }

    for(int i=1; i<=C; i++){
        for(int j=1; j<=G; j++){
            int a;
            cin >> a;
            if(cake_profit[i]>=0)cake_profit[i]-=ingredient_cost[j]*a;
        }
    }

    for(int i=1; i<=C; i++){
        int a;
        cin >> a;
        for(int j=0; j<a; j++){
            int b;
            cin >> b;
            graph[i].push_back(b+200);
            graph[b+200].push_back(i);
            cap[i][b+200]=1e18;
        }
    }

    for(int i=1; i<=C; i++){
        if(cake_profit[i]<0) continue;
        graph[S].push_back(i);
        graph[i].push_back(S);
        cap[S][i]=cake_profit[i];
    }

    for(int j=1; j<=Toolcnt; j++){
        graph[T].push_back(j+200);
        graph[j+200].push_back(T);
        cap[j+200][T]=tool_cost[j];
    }

    int ans=0;

    while(dinic_bfs()){
        memset(work, 0, sizeof(work));
        while(1){
            int new_flow=dinic_dfs(S, T, 1e18);
            if(new_flow==0) break;
            ans+=new_flow;
        }
    }

    int total=0;

    for(int i=1; i<=C; i++){
        if(cake_profit[i]>0) total+=cake_profit[i];
    }

    cout << total-ans;

    return 0;
}
