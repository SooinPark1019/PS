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
//#define int long long
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
DP[i]=첫번째 재료의 가치가 i일 때 두번째 재료의 가능한 최대 가치

두 차원 모두 양수인 거는 당연히 그대로 합치고
그렇지 않을 경우 취할 차원을 선택

나머지는 취할 차원만 취하거나 아니면 둘다 취해야 함
*/

int N, M, A, B;
const int MAX=5000+5, S=MAX-2, T=MAX-1;
int cap[MAX][MAX], flow[MAX][MAX], level[MAX], work[MAX];
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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    int t=0;
    while(TC--){
        int N;
        cin >> N;

        t++;
        cout << "Case #" << t << ": ";

        for(int i=0; i<MAX; i++){
            for(int j=0; j<MAX; j++){
                cap[i][j]=0;
                flow[i][j]=0;
            }
            level[i]=0;
            work[i]=0;
            visited[i]=0;
            graph[i].clear();
        }
        
        cin.ignore();
        map<string, vector<int>> M;
        for(int i=0; i<N; i++){
            string S;
            getline(cin, S);
            string temp;
            for(auto c : S){
                if(c==' '){
                    M[temp].push_back(i);
                    temp="";
                }
                else{
                    temp+=c;
                }
            }
            M[temp].push_back(i);
        }
        graph[S].push_back(0);
        graph[0].push_back(S);
        cap[S][0]=1e9;
        graph[T].push_back(1);
        graph[1].push_back(T);
        cap[1][T]=1e9;

        int i=0;
        for(auto p : M){
            zip(p.second);
            for(auto j : p.second){
                graph[j].push_back(N+i);
                graph[N+i].push_back(j);
                cap[j][N+i]=1e9;
            }
            i++;
        }
        for(auto p : M){
            for(auto j : p.second){
                graph[j].push_back(N+i);
                graph[N+i].push_back(j);
                cap[N+i][j]=1e9;
            }
            i++;
        }
        for(int i=0; i<M.size(); i++){
            graph[N+i].push_back(N+i+M.size());
            graph[N+i+M.size()].push_back(N+i);
            cap[N+i][N+i+M.size()]=1;
        }
        int ans=0;
        while(dinic_bfs()){
            memset(work, 0, sizeof(work));
            while(1){
                int new_flow=dinic_dfs(S, T, 1e9);
                if(new_flow==0) break;
                ans+=new_flow;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}
