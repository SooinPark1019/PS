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

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;
const ll MAX = 200000;

struct st{
    ll sz, sum, DP, DP2, depthDP;
};

bool compare(st A, st B){
    return (double)A.sz/A.sum<(double)B.sz/B.sum;
}

vector<int> graph[MAX+5];
ll val[200005], sz[200005], sum[200005], DP[200005], DP2[200005], depth[200005], depthDP[200005];

void find_depth(int cur_node){
    for(auto i : graph[cur_node]){
        depth[i]=depth[cur_node]+1;
        find_depth(i);
    }
}

void DFS(int cur_node){
    sz[cur_node]=1;
    sum[cur_node]=val[cur_node];
    depthDP[cur_node]=depth[cur_node];
    vector<st> V;
    for(auto i : graph[cur_node]){
        DFS(i);
        V.push_back({sz[i], sum[i], DP[i], DP2[i], depthDP[i]});
        sz[cur_node]+=sz[i];
        sum[cur_node]+=sum[i];
        DP[cur_node]+=DP[i];
        depthDP[cur_node]=max(depthDP[cur_node], depthDP[i]);
    }
    ll cur_time=0;
    if(V.size()==0) return;
    sort(all(V), compare);
    vector<ll> prefix;
    prefix.push_back(V[0].sum);
    for(int i=1; i<V.size(); i++){
        prefix.push_back(prefix.back()+V[i].sum);
    }

    for(int i=0; i<V.size(); i++){
        DP[cur_node]+=(cur_time+1)*V[i].sum;
        cur_time+=2*V[i].sz;
    }
    cur_time=0;
    DP2[cur_node]=LLONG_MAX-5;
    //cout << "cur node : " << cur_node << " DP : " << DP[cur_node] << "\n";
    for(int i=0; i<V.size(); i++){
        if(depthDP[cur_node]==V[i].depthDP){
            ll temp=DP[cur_node]-V[i].DP+V[i].DP2;
            temp-=(cur_time+1)*V[i].sum;
            temp-=2*V[i].sz*(prefix.back()-prefix[i]);
            temp+=(2*(sz[cur_node]-1-V[i].sz)+1)*V[i].sum;
            //cout << temp << " ";
            DP2[cur_node]=min(DP2[cur_node], temp);
        }
        //cout << "\n";
        cur_time+=2*V[i].sz;
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, T;
    cin >> N >> T;

    for(int i=2; i<=N; i++){
        ll p, a;
        cin >> p >> a;
        graph[p].push_back(i);
        val[i]=a;
    }
    ll mindis=2*(N-1);
    depth[1]=0;
    find_depth(1);
    if(T==1){
        ll maxdepth=0;
        for(int i=2; i<=N; i++){
            maxdepth=max(maxdepth, depth[i]);
        }
        mindis-=maxdepth;
    }
    //cout << mindis << endl;
    DFS(1);
    if(T==1) cout << mindis << " " << DP2[1];
    else cout << mindis << " " << DP[1];
}
