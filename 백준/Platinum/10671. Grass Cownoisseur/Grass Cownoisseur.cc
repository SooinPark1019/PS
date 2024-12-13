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
const ll mod = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
*/
int id;
vector<int> graph[100005];
vector<int> rev_graph[100005];
int d[100005], finished[100005];
int Sccnum;
int sn[100005];
stack<int> S;
vector<vector<int>> ans;
vector<int> sccgraph[100005];
vector<int> rev_sccgraph[100005];

int DFS(int node){
    d[node]=++id;
    S.push(node);

    int result=d[node];
    for(auto i : graph[node]){
        if(d[i]==0) result=min(result, DFS(i));
        else if(finished[i]==0) result=min(result, d[i]);
    }
    if(result==d[node]){
        vector<int> scc;
        while(1){
            int temp=S.top();
            S.pop();
            scc.push_back(temp);
            finished[temp]=1;
            sn[temp]=Sccnum;
            if(temp==node) break;
        }
        ans.push_back(scc);
        Sccnum++;
    }
    return result;
}

int DP[100005];
int DP2[100005];

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
        rev_graph[b].push_back(a);
    }

    for(int i=1; i<=N; i++){
        if(d[i]==0) DFS(i);
    }

    for(int i=1; i<=N; i++){
        for(auto j : graph[i]){
            if(sn[j]==sn[i]) continue;
            sccgraph[sn[i]].push_back(sn[j]);
            rev_sccgraph[sn[j]].push_back(sn[i]);
        }
    }

    /*for(auto v : ans){
        for(auto i : v) cout << i << " ";
        cout << "\n";
    }*/

    memset(DP, -1, sizeof(DP));
    memset(DP2, -1, sizeof(DP2));

    DP[sn[1]]=0;
    DP2[sn[1]]=0;

    for(int i=0; i<Sccnum; i++){
        if(DP2[i]==-1) continue;
        for(auto j : rev_sccgraph[i]){
            DP2[j]=max(DP2[j], DP2[i]+(int)ans[j].size());
        }
    }

    for(int i=Sccnum-1; i>=0; i--){
        if(DP[i]==-1) continue;
        //cout << i << " " << DP[i] << "\n";
        for(auto j : sccgraph[i]){
            DP[j]=max(DP[j], DP[i]+(int)ans[j].size());
        }
    }

    int res=0;
    for(int i=1; i<=N; i++){
        for(auto j : graph[i]){
            if(sn[i]!=sn[j]){
                if(DP2[sn[i]]!=-1&&DP[sn[j]]!=-1){
                    res=max(res, DP2[sn[i]]+DP[sn[j]]);
                }
            }
        }
    }

    cout << res+ans[sn[1]].size();

    return 0;
}
