#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define int long long
#define ll long long

using namespace std;

//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
//#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>//이걸 코드의 윗부분에 추가
/*void m_erase(ordered_set &OS, ll val){
    ll index = OS.order_of_key(val);
    ordered_set::iterator it = OS.find_by_order(index);
    if(*it == val) OS.erase(it);
}*/
//다른 건 통상적인 PBDS처럼 사용하면 되지만 erase는 반드시!!! 이 함수를 통해서만 해야 함
//m_erase(OS, 지울 원소)처럼 사용하면 된다. 꼭 주의하자.
//얘네 쓰려면 define int long long 꺼라.

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
const int MAX=405, S = MAX - 2, T = MAX - 1; 
int N, M, K, cap[MAX][MAX], flow[MAX][MAX], level[MAX], work[MAX];
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
        //cout << "x : " << x << "\n";
        for(auto i : graph[x]){
            if(level[i]==-1&&cap[x][i]>flow[x][i]){
                level[i]=level[x]+1;
                Q.push(i);
            }
        }
    }
    return level[T]!=-1;
}

int dinic_dfs(int x, int dest, int max_flow){
    //cout << x << " " << dest << " " << max_flow << "\n";
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

    cin >> N >> M >> K;
    
    vector<array<int, 3>> edges;

    for(int i=0; i<M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, a, b});
    }

    sort(all(edges));

    int left=0;
    int right=M-1;
    int res=1e18;

    while(left<=right){
        int mid=(left+right)>>1;
        //cout << "mid : " << mid << "\n";
        for(int i=0; i<405; i++){
            graph[i].clear();
            work[i]=0;
            for(int j=0; j<405; j++){
                cap[i][j]=0;
                flow[i][j]=0;
            }
        }
        for(int i=1; i<=N; i++){
            graph[i].push_back(i+200);
            graph[i+200].push_back(i);
            cap[i][i+200]=1e18;
        }

        graph[S].push_back(1);
        graph[1].push_back(S);
        cap[S][1]=1e18;

        graph[T].push_back(N+200);
        graph[N+200].push_back(T);
        cap[N+200][T]=1e18;

        for(int i=0; i<=mid; i++){
            int u=edges[i][1];
            int v=edges[i][2];
            //cout << "u : " << u << " v : " << v << "\n";
            graph[u+200].push_back(v);
            graph[v].push_back(u+200);
            cap[u+200][v]+=1;
            graph[v+200].push_back(u);
            graph[u].push_back(v+200);
            cap[v+200][u]+=1;
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
        //cout << ans << "\n";
        if(ans>=K){
            res=min(edges[mid][0], res);
            right=mid-1;
        }
        else left=mid+1;
    }

    cout << res;

    return 0;
}
