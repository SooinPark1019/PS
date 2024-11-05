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
typedef unsigned long long ull;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ull mod = 4294967296;
const ll MAXN=500005;

vector<ull> V(MAXN, 0);
vector<int> graph[MAXN];
ull sz[MAXN], dep[MAXN], top[MAXN], par[MAXN], in[MAXN], out[MAXN];
vector<int> child[MAXN];
int pv=0, N;

struct Seg{
    vector<ull> seg;
    vector<pair<ull, ull>> lazy;
    void init(){
        seg.resize(4*N+4, 0);
        lazy.resize(4*N+4, {1, 0});
    }
    void LazyUpdate(int node, int start, int end){
        //cout << node << " " << start << " " << end << endl;
        if(lazy[node].first!=1||lazy[node].second!=0){
            seg[node]=(lazy[node].first*seg[node]%mod+(ull)(end-start+1)*lazy[node].second%mod)%mod;
            if(start!=end){
                lazy[node*2].first*=lazy[node].first;
                lazy[node*2].first%=mod;
                lazy[node*2].second=(lazy[node*2].second*lazy[node].first%mod+lazy[node].second)%mod;
                lazy[node*2+1].first*=lazy[node].first;
                lazy[node*2+1].first%=mod;
                lazy[node*2+1].second=(lazy[node*2+1].second*lazy[node].first%mod+lazy[node].second)%mod;
            }
            lazy[node].first=1;
            lazy[node].second=0;
        }
        return;
    }
    void UpdateSeg(int node, int start, int end, int left, int right, ull value1, ull value2){
        //cout << node << " " << start << " " << end << " " << left << " " << right << endl;
        LazyUpdate(node, start ,end);
        if(right<start||end<left) return;
        else if(left<=start&&end<=right){
            lazy[node].first*=value1;
            lazy[node].first%=mod;
            lazy[node].second=(value1*lazy[node].second%mod+value2)%mod;
            LazyUpdate(node, start, end);
            //cout << node << " " << start << " " << end << " " << left << " " << right << endl;
        }
        else{
            int mid=(start+end)/2;
            UpdateSeg(node*2, start, mid, left, right, value1, value2);
            UpdateSeg(node*2+1, mid+1, end, left, right, value1, value2);
            seg[node]=(seg[node*2]+seg[node*2+1])%mod;
        }
        return;
    }
    ull SumSeg(int node, int start, int end, int left, int right){
        LazyUpdate(node, start, end);
        if(right<start||end<left) return 0;
        else if(left<=start&&end<=right){
            return seg[node];
        }
        else{
            int mid=(start+end)/2;
            return (SumSeg(node*2, start, mid, left, right)+SumSeg(node*2+1, mid+1, end, left, right))%mod;
        }
    }
};

Seg seg;

void dfs1(int cur_node, int p){
    //cout << cur_node << "\n";
    for(auto i : graph[cur_node]){
        if(i==p) continue;
        par[i]=cur_node;
        child[cur_node].push_back(i);
        dfs1(i, cur_node);
    }
}

void dfs2(int cur_node){
    sz[cur_node]=1;
    for(auto &i : child[cur_node]){
        dep[i]=dep[cur_node]+1;
        dfs2(i);
        sz[cur_node]+=sz[i];
        if(sz[i]>sz[child[cur_node][0]]) swap(i, child[cur_node][0]);
    }
}

void dfs3(int cur_node){
    in[cur_node]=++pv;
    for(auto i : child[cur_node]){
        if(i==child[cur_node][0]) top[i]=top[cur_node];
        else top[i]=i;
        dfs3(i);
    }
    out[cur_node]=pv;
}

void subtreemulupd(int node, ull val){
    //cout << node << " " << val << endl;
    seg.UpdateSeg(1, 0, N, in[node], out[node], val, 0);
}

void subtreeplusupd(int node, ull val){
    seg.UpdateSeg(1, 0, N, in[node], out[node], 1, val);
}

ull subtreequery(int node){
    return seg.SumSeg(1, 0, N, in[node], out[node]);
}

void hldmulupd(int a, int b, int val){
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a, b);
        int st=top[a];
        seg.UpdateSeg(1, 0, N, in[st], in[a], val, 0);
        a=par[st];
    }
    if(dep[a]>dep[b]) swap(a, b);
    //cout << a << " " << b << "\n";
    seg.UpdateSeg(1, 0, N, in[a], in[b], val, 0);
    return;
}

void hldplusupd(int a, int b, int val){
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a, b);
        int st=top[a];
        seg.UpdateSeg(1, 0, N, in[st], in[a], 1, val);
        a=par[st];
    }
    if(dep[a]>dep[b]) swap(a, b);
    //cout << a << " " << b << "\n";
    seg.UpdateSeg(1, 0, N, in[a], in[b], 1, val);
    return;
}

ull hldquery(int a, int b){
    //cout << a << " " << b << "\n";
    ull ret=0;
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a, b);
        int st=top[a];
        //cout << in[a] << " " << in[st] << "\n";
        ret+=seg.SumSeg(1, 0, N, in[st], in[a]);
        ret%=mod;
        //cout << ret << "\n";
        a=par[st];
    }
    if(dep[a]>dep[b]) swap(a, b);
    //cout << a << " " << b << "\n";
    ret+=seg.SumSeg(1, 0, N, in[a], in[b]);
    ret%=mod;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Q;
    cin >> N >> Q;
    seg.init();
    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs1(1, -1);
    dfs2(1);
    dfs3(1);
    while(Q--){
        int type;
        cin >> type;
        if(type==1){
            int a;
            ull V;
            cin >> a >> V;
            subtreeplusupd(a, V);
        }
        else if(type==2){
            int a, b;
            ull V;
            cin >> a >> b >> V;
            hldplusupd(a, b, V);
        }
        else if(type==3){
            int a;
            ull V;
            cin >> a >> V;
            //cout << a << " " << V << endl;
            subtreemulupd(a, V);
        }
        else if(type==4){
            int a, b;
            ull V;
            cin >> a >> b >> V;
            hldmulupd(a, b, V);
        }
        else if(type==5){
            int a;
            cin >> a;
            cout << subtreequery(a) << "\n";
        }
        else{
            int a, b;
            cin >> a >> b;
            cout << hldquery(a, b) << "\n";
        }
    }
    return 0;
}