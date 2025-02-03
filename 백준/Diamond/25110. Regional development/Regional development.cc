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
Z로 생각을 해보자
먼저 첫번째 두 배열을 그대로 붙인 상태로 시작을 해서
Z값을 계산
접두사=접미사 되는 곳을 찾아가지고 비용계산
남은 것을 다음 문자열로 이월
*/

const int MAX=1000+5, S=MAX-2, T=MAX-1;

int N, cap[MAX][MAX], flow[MAX][MAX], level[MAX], work[MAX], extra[MAX];
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
        for(auto nx : graph[x]){
            if(level[nx]<0&&cap[x][nx]>flow[x][nx]){
                level[nx]=level[x]+1;
                Q.push(nx);
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
            int new_flow=dinic_dfs(nx, dest, min(cap[x][nx]-flow[x][nx], max_flow));
            if(new_flow>0){
                flow[x][nx]+=new_flow;
                flow[nx][x]-=new_flow;
                return new_flow;
            }
        }
    }
    return 0;
}

struct st{
    int a, b, c;
};

vector<st> edge;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, R, M;
    cin >> N >> R >> M;

    for(int i=0; i<R; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(b);
        graph[b].push_back(a);
        cap[b][a]=1;
        extra[a]-=c;
        extra[b]+=c;
        edge.push_back({a, b, c});
    }

    int plustotal=0;
    int minustotal=0;

    for(int i=1; i<=N; i++){
        if(extra[i]>0){
            graph[S].push_back(i);
            graph[i].push_back(S);
            cap[S][i]=abs(extra[i]/M);
            plustotal+=abs(extra[i]/M);
        }
        else{
            graph[i].push_back(T);
            graph[T].push_back(i);
            cap[i][T]=abs(extra[i]/M);
            minustotal+=abs(extra[i]/M);
        }
    }

    if(plustotal!=minustotal){
        cout << "IMPOSSIBLE";
        return 0;
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

    if(ans!=plustotal){
        cout << "IMPOSSIBLE";
        return 0;
    }

    for(auto e : edge){
        if(flow[e.b][e.a]==cap[e.b][e.a]) cout << e.c-M << "\n";
        else cout << e.c << "\n"; 
    }
    
    return 0;
}
