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
시간이 가장 오래걸리는 것부터 놓자.
a*b가 가장 오래걸리는 것부터 놓는게 맞을까?
*/

vector<int> graph[65];
int ans[65];
int deepestleaf[65];
vector<int> prime;
int par[65];
int child[65];

void find_par(int cur_node){
    for(auto i : graph[cur_node]){
        if(i==par[cur_node]) continue;
        child[cur_node]++;
        par[i]=cur_node;
        find_par(i);
    }
}

int dfs(int cur_node, int cur_depth){
    int ret=cur_depth;
    for(auto i : graph[cur_node]){
        if(i==par[cur_node]||ans[i]!=0) continue;
        ret=max(ret, dfs(i, cur_depth+1));
    }
    deepestleaf[cur_node]=ret;
    return ret;
}

void dfs2(int cur_node, int curidx){
    assert(ans[cur_node]<=1e18&&ans[cur_node]>0);
    //cout << cur_node << " " << curidx << endl;
    int maxdepth=-1;
    int maxarg;
    for(auto i : graph[cur_node]){
        if(i==par[cur_node]||ans[i]!=0) continue;
        if(maxdepth<deepestleaf[i]){
            maxdepth=deepestleaf[i];
            maxarg=i;
        }
    }
    if(maxdepth==-1) return;
    ans[maxarg]=ans[cur_node]*prime[curidx];
    dfs2(maxarg, curidx);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=2; i<=1000; i++){
        int flag=0;
        for(int j=2; j*j<=i; j++){
            if(i%j==0){
                flag=1;
                break;
            }
        }
        if(flag==0){
            prime.push_back(i);
            if(prime.size()>60) break;
        }
    }
    find_par(1);

    ans[1]=1;
    int curidx=0;

    while(curidx<60){
        memset(deepestleaf, 0, sizeof(deepestleaf));
        int maxdis=0;
        int maxroot;
        for(int i=1; i<=N; i++){
            if(ans[i]==0) continue;
            if(maxdis<dfs(i, 0)){
                maxdis=dfs(i, 0);
                maxroot=i;
            }
        }
        //cout << maxdis << endl;
        if(maxdis==0) break;
        dfs2(maxroot, curidx);
        curidx++;
        //cout << curidx << endl;
    }

    for(int i=1; i<=N; i++){
        cout << ans[i] << " ";
    }
    
    return 0;
}