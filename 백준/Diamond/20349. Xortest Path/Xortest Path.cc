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

vector<pii> graph[MAXN+5];
vector<int> basis;
int lvl[MAXN+5];
int xorval[MAXN+5];

void add(int a){
    for(auto i : basis){
        a=min(a, a^i);
    }
    if(a!=0) basis.push_back(a);
}

int reduce(int a){
    for(auto i : basis){
        a=min(a, a^i);
    }
    return a;
}

void dfs(int cur_node, int p, int cur_xor){
    xorval[cur_node]=cur_xor;
    for(auto nxt : graph[cur_node]){
        if(nxt.first==p) continue;
        if(lvl[nxt.first]==0){
            lvl[nxt.first]=lvl[cur_node]+1;
            dfs(nxt.first, cur_node, cur_xor^nxt.second);
        }   
        else{
            int a=xorval[cur_node]^xorval[nxt.first];
            a^=nxt.second;
            add(a);
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, Q;
    cin >> N >> M >> Q;
    for(int i=0; i<M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    lvl[1]=1;
    dfs(1, -1, 0);

    while(Q--){
        int a, b;
        cin >> a >> b;
        int x=xorval[a]^xorval[b];
        x=reduce(x);
        cout << x << "\n";
    }
    
    return 0;
}