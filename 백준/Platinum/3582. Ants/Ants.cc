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
const int MAXN = 2e5+5;
const int D = 20;

vector<int> graph[205];
double d[205][205]={};//비용
int c[205][205]={};//용량
int f[205][205]={};//유량
double dist[205]={};
int inqueue[205]={}, vis[205]={}, s=201, e=202, N, M;

double caldist(pii a, pii b){
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<pii> V;
    for(int i=0; i<2*N; i++){
        int a, b;
        cin >> a >> b;
        V.push_back({a, b});
    }

    for(int i=0; i<N; i++){
        graph[s].push_back(i);
        graph[i+N].push_back(e);
        graph[i].push_back(s);
        graph[e].push_back(i+N);
        c[s][i]=1;
        c[i+N][e]=1;
        for(int j=N; j<2*N; j++){
            graph[i].push_back(j);
            graph[j].push_back(i);
            d[i][j]=caldist(V[i], V[j]);
            d[j][i]=-d[i][j];
            c[i][j]=1;
        }
    }
    int maxflow=0;
    vector<int> ans(N+1);
    while(1){
        memset(vis, -1, sizeof(vis));
        memset(inqueue, 0, sizeof(inqueue));
        fill(dist, dist+204, 1e18);
        queue<int> Q;
        dist[s]=0;
        vis[s]=0;
        inqueue[s]=1;
        Q.push(s);
        while(!Q.empty()){
            int x=Q.front();
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
        if(vis[e]==-1) break;
        int a=INF;
        for(int i=e; i!=s; i=vis[i]){
            a=min(a, c[vis[i]][i]-f[vis[i]][i]);
            if((vis[i]<N)){
                ans[vis[i]]=i-N+1;
            }
        }
        for(int i=e; i!=s; i=vis[i]){
            f[vis[i]][i]+=a;
            f[i][vis[i]]-=a;
        }
        maxflow+=a;
    }
    assert(maxflow==N);
    for(int i=0; i<N; i++){
        cout << ans[i] << "\n";
    }
    
    return 0;
}