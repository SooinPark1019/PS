#include <ext/rope>
#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
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
더하고 XOR

그냥 모든 더하는 경우를 각각 해보면 되는 듯?
DP[죽은 애들]=경우의 수 
*/

const int MAX=2505, S=MAX-2, T=MAX-1;
int N, cap[MAX][MAX], flow[MAX][MAX], level[MAX], work[MAX];
bool visited[MAX];
vector<int> graph[MAX];
char arr[MAX][MAX];

bool dinic_bfs(){
    //cout << "start bfs" << "\n";
    memset(level, -1, sizeof(level));
    level[S]=0;
    queue<int> Q;
    Q.push(S);
    while(!Q.empty()){
        int x=Q.front();
        //cout << "x : " << x << "\n";
        Q.pop();
        for(auto i : graph[x]){
            //cout << "i : " << i << " level : " << level[i] << " cap : " << cap[x][i] << " flow : " << flow[x][i] << "\n";
            if(level[i]<0&&cap[x][i]>flow[x][i]){
                level[i]=level[x]+1;
                Q.push(i);
            }
        }
    }
    return level[T]!=-1;
}

int dinic_dfs(int x, int dest, int max_flow){
    //cout << "x : " << x << " dest : " << dest << " max_flow : " << max_flow << "\n";
    if(x==dest){
        //cout << "max_flow : " << max_flow << "\n";
        return max_flow;
    }
    for(int& i=work[x]; i<graph[x].size(); i++){
        int nx=graph[x][i];
        //cout << "x : " << x << " nx : " << nx << " " << "cap : " << cap[x][nx] << " flow : " << flow[x][nx] << " " << level[nx] << " " << level[x] << "\n";
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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    int t=0;
    while(TC--){
        t++;
        cout << "Case #" << t << ": ";

        int N, M;
        cin >> N >> M;

        for(int i=0; i<MAX; i++){
            graph[i].clear();
        }

        memset(work, 0, sizeof(work));
        memset(level, 0, sizeof(level));
        memset(visited, 0, sizeof(visited));
        memset(cap, 0, sizeof(cap));
        memset(flow, 0, sizeof(flow));

        int total=0;

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cin >> arr[i][j];
                if(arr[i][j]=='#'||arr[i][j]=='?') total+=4;
            }
        }

        int dx[4]={-1, 1, 0, 0};
        int dy[4]={0, 0, -1, 1};

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                int a=i*M+j;
                //cout << "a : " << a << "\n";
                //cout << "i : " << i << " j : " << j << "\n";
                if((i+j)%2){
                    if(arr[i][j]=='#'){
                        graph[S].push_back(a);
                        graph[a].push_back(S);
                        cap[S][a]=1e18;
                    }
                    else if(arr[i][j]=='.'){
                        graph[a].push_back(T);
                        graph[T].push_back(a);
                        cap[a][T]=1e18;
                    }
                    else{
                        graph[S].push_back(a);
                        graph[a].push_back(S);
                        cap[S][a]=4;
                    }
                    for(int k=0; k<4; k++){
                        int nx=i+dx[k];
                        int ny=j+dy[k];
                        if(nx<0||nx>=N||ny<0||ny>=M) continue;
                        int b=nx*M+ny;
                        //cout << "a : " << a << " b : " << b << "\n";
                        graph[a].push_back(b);
                        graph[b].push_back(a);
                        cap[a][b]=2;
                        //cap[b][a]=2;
                    }
                }
                else{
                    if(arr[i][j]=='#'){
                        graph[a].push_back(T);
                        graph[T].push_back(a);
                        cap[a][T]=1e18;
                    }
                    else if(arr[i][j]=='.'){
                        graph[S].push_back(a);
                        graph[a].push_back(S);
                        cap[S][a]=1e18;
                    }
                    else{
                        graph[a].push_back(T);
                        graph[T].push_back(a);
                        cap[a][T]=4;
                    }
                }
            }
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
        /*visited[S] = 1;
        queue<int> q;
        q.push(S);
        while (!q.empty()) {  // source에서 방문 가능한 정점과 그렇지 않은 정점들이 min-cut으로 나뉘게 됨
            int x = q.front();
            q.pop();
            //cout << "x : " << x << "\n";
            for (auto& nx : graph[x]) {
                if (visited[nx]) continue;
                if (cap[x][nx] > flow[x][nx]) {
                    //cout << "nx : " << nx << " cap : " << cap[x][nx] << " flow : " << flow[x][nx] << "\n";
                    visited[nx] = 1;
                    q.push(nx);
                }
            }
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                int a=i*M+j;
                if((i+j)%2){
                    if(visited[a]) cout << "#";
                    else cout << ".";
                }
                else{
                    if(visited[a]) cout << ".";
                    else cout << "#";
                }
            }
            cout << "\n";
        }*/
        cout << total-ans << "\n";
    }

    return 0;
}
