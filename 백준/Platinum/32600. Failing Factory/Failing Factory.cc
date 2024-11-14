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
const int D = 20;

/*
1을 루트로 하는 트리를 생각하자
엘리스는 부모로 올라갈 것이고
퀸은 리프와의 최단 경로로 끌어내릴 것이다
각 정점마다 부모와의 거리, 리프와의 최단 경로를 적어 두자
*/

const int MAX = 100005;

int N, M, dn[MAX], sn[MAX], dnum, snum;  // dfs number & scc number
vector<int> graph[MAX];
vector<vector<int>> scc;
stack<int> ST;
double V[MAX];
double DP[MAX];
int indegree[MAX];
set<int> sccgraph[MAX];

int scc_dfs(int x) {
    int ret = dn[x] = ++dnum;
    ST.push(x);
    for (auto& nx : graph[x]) {  // 문제에서 간선이 어떻게 주어지는지에 따라 수정이 필요할 수 있음    
        if (dn[nx] == 0) ret = min(ret, scc_dfs(nx));
        else if (sn[nx] == 0) ret = min(ret, dn[nx]);
    }
    if (ret == dn[x]) {
        ++snum;
        scc.push_back({});
        while (1) {
            int st_top = ST.top();
            ST.pop();
            sn[st_top] = snum;
            scc.back().push_back(st_top);
            if (st_top == x) break;
        }
    }
    return ret;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //scanf("%d %d", &N, &M);
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        cin >> V[i];
        //scanf("%lf", &V[i]);
        V[i]=1-V[i];
    }
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        //scanf("%d %d", &a, &b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= N; ++i) {
        if (dn[i] == 0) scc_dfs(i);  // 방문하지 않은 모든 정점에 대해 scc_dfs를 실행
    }

    for(int i=1; i<=N; i++){
        for(auto j : graph[i]){
            if(sn[i]==sn[j]) continue;
            if(sccgraph[sn[i]].find(sn[j])==sccgraph[sn[i]].end()){
                sccgraph[sn[i]].insert(sn[j]);
                indegree[sn[j]]++;
            }
        }
    }

    for(int i=1; i<=snum; i++){
        double temp=1;
        for(auto j : scc[i-1]){
            temp*=V[j];
        }
        DP[i]=temp;
    }
    queue<int> Q;

    for(int i=1; i<=snum; i++){
        if(indegree[i]==0) Q.push(i);
    }

    while(!Q.empty()){
        int x=Q.front();
        Q.pop();
        for(auto i : sccgraph[x]){
            DP[i]*=DP[x];
            indegree[i]--;
            if(indegree[i]==0) Q.push(i);
        }
    }

    double ans=0;
    for(int i=1; i<=snum; i++){
        ans=max(ans, DP[i]);
    }
    cout << fixed;
    cout.precision(300);
    cout << ans;
    //printf("%lf\n", ans);
    //printf("%.9g", ans);
    //ans=0.281111111111;
    //printf("%.9g\n", ans);
    
    return 0;
}