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
#define sz(x) (int)x.size()

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
typedef complex<double> cpx;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 10007;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*

*/
vector<int> graph[300005];
int lvl[300005];
int par[300005];
int low[300005];

void dfs(int cur_node, int p){
    low[cur_node]=lvl[cur_node];
    for(int nxt : graph[cur_node]){
        if(nxt==p) continue;
        //cout << "cur_node : " << cur_node << " nxt : " << nxt << "\n";
        //cout << lvl[nxt] << " " << lvl[cur_node] << "\n";
        if(lvl[nxt]==0){//spanning edge
            lvl[nxt]=lvl[cur_node]+1;
            par[nxt]=cur_node;
            dfs(nxt, cur_node);
            low[cur_node]=min(low[cur_node], low[nxt]);
        }
        else low[cur_node]=min(low[cur_node], lvl[nxt]);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    lvl[1]=1;
    dfs(1, -1);
    /*for(int i=1; i<=N; i++){
        cout << low[i] << " ";
    }
    cout << "\n";*/
    int ans=0;
    for(int i=1; i<=N; i++){
        //cout << "i : " << i << " DP : " << DP[i] << "\n";
        int component=1;
        if(i==1) component=0;
        for(auto j : graph[i]){
            //cout << "i : " << i << " " << "j : " << j << " " << low[j] << "\n";
            if(par[j]==i&&low[j]>=lvl[i]) component++;
        }
        //cout << component << " " << graph[i].size() << "\n";
        if(component+M-graph[i].size()==N-1) ans+=i;
    }

    cout << ans;
    
    return 0;
}
