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
//#define int long long
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
vector<int> graph[2005];
int d[2005][2005]={};
int c[2005][2005]={};
int f[2005][2005]={};
int inqueue[2005]={};
int vis[2005]={};
int dist[2005]={};
int s=2001;
int e=2002;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    cin >> N >> M;



    for(int i=1; i<=N; i++){
        c[i][i+1000]=1;
        graph[i].push_back(i+1000);
        graph[i+1000].push_back(i);
    }

    for(int i=0; i<M; i++){
        int a, b, cost;
        cin >> cost >> a >> b;
        graph[a+1000].push_back(b);
        graph[b].push_back(a+1000);
        d[a+1000][b]=cost;
        d[b][a+1000]=-cost;
        c[a+1000][b]=1;
        graph[b+1000].push_back(a);
        graph[a].push_back(b+1000);
        d[b+1000][a]=cost;
        d[a][b+1000]=-cost;
        c[b+1000][a]=1;
    }

    int a, b;
    cin >> a >> b;

    graph[s].push_back(a);
    graph[a].push_back(s);
    c[s][a]=2;
    c[a][a+1000]=2;
    graph[b+1000].push_back(e);
    graph[e].push_back(b+1000);
    c[b+1000][e]=2;
    c[b][b+1000]=2;

    int result=0;
    int maxflow=0;
    while(1){
        memset(vis, -1, sizeof(vis));
        memset(inqueue, 0, sizeof(inqueue));
        fill(dist, dist+2004, INF);
        queue<int> Q;
        dist[s]=0;
        vis[s]=0;
        inqueue[s]=1;
        Q.push(s);
        while(!Q.empty()){
            int x=Q.front();
            //cout << x << "\n";
            Q.pop();
            inqueue[x]=0;
            for(auto i : graph[x]){
                if(dist[i]>dist[x]+d[x][i]&&c[x][i]>f[x][i]){
                    dist[i]=dist[x]+d[x][i];
                    vis[i]=x;
                    if(inqueue[i]==0){
                        Q.push(i);
                        inqueue[i]=1;
                    }
                }
            }
        }
        //cout <<"vis : " << vis[e] << "\n";
        if(vis[e]==-1) break;
        int a=INF;
        for(int i=e; i!=s; i=vis[i]){
            a=min(a, c[vis[i]][i]-f[vis[i]][i]);
        }
        for(int i=e; i!=s; i=vis[i]){
            f[vis[i]][i]+=a;
            f[i][vis[i]]-=a;
            result+=d[vis[i]][i]*a;
        }
        maxflow+=a;
    }
    if(maxflow<2) cout << -1 << "\n";
    else cout << result << "\n";

    return 0;
}
