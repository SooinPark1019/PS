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
const ll MAXN=50005;

struct edge{
    int start, end, num;
    ll w;
};

struct comp{
    bool operator()(edge A, edge B){
        return B.w<A.w;
    }
};

class UnionFind{
private:
    vector<int> p, rank, setSize;
public:
    UnionFind(int N){
        p.assign(N, 0);
        for(int i=0; i<N; i++) p[i]=i;
        rank.assign(N, 0);
        setSize.assign(N, 1);
    };
    int findset(int i){
        return(p[i]==i) ? i : (p[i]=findset(p[i]));
    }
    bool isSameSet(int i, int j){
    return findset(i) == findset(j);
    }
    int SizeOfSet(int i){
        return setSize[findset(i)];
    }
    void UnionSet(int i, int j){
    if(isSameSet(i, j)) return;
    int x=findset(i);
    int y=findset(j);
    if(rank[x]>rank[y]) swap(y,x);
    p[x] = y;
    if(rank[x]==rank[y]) rank[y]++;
    setSize[y]+=setSize[x];
    }
};

vector<ll> V(MAXN, 0);
vector<pair<int, int>> graph[MAXN];
ll sz[MAXN], dep[MAXN], top[MAXN], par[MAXN], in[MAXN], out[MAXN];
vector<int> child[MAXN];
int check[200005];
vector<edge> E;
priority_queue<edge, vector<edge>, comp> PQ;
int pv=0, N;

struct Seg{
    vector<pair<ll, ll>> seg;
    vector<pair<ll, ll>> lazy;
    void init(){
        seg.resize(4*N+4, {1e18, 1e18});
        lazy.resize(4*N+4, {1e18, 1e18});
    }
    void LazyUpdate(int node, int start, int end){
        //cout << node << " " << start << " " << end << endl;
        if(lazy[node].first!=1e18){
            if(seg[node].first>lazy[node].first){
                seg[node].second=min(seg[node].first, lazy[node].second);
                seg[node].first=lazy[node].first;
            }
            else if(seg[node].first<lazy[node].first){
                seg[node].second=min(seg[node].second, lazy[node].first);
            }
            else{
                seg[node].second=min(seg[node].second, lazy[node].second);
            }
            if(start!=end){
                if(lazy[node*2].first>lazy[node].first){
                    lazy[node*2].second=min(lazy[node*2].first, lazy[node].second);
                    lazy[node*2].first=lazy[node].first;
                }
                else if(lazy[node*2].first<lazy[node].second){
                    lazy[node*2].second=min(lazy[node*2].second, lazy[node].first);
                }
                else{
                    lazy[node*2].second=min(lazy[node*2].second, lazy[node].second);
                }
                if(lazy[node*2+1].first>lazy[node].first){
                    lazy[node*2+1].second=min(lazy[node*2+1].first, lazy[node].second);
                    lazy[node*2+1].first=lazy[node].first;
                }
                else if(lazy[node*2+1].first<lazy[node].first){
                    lazy[node*2+1].second=min(lazy[node*2+1].second, lazy[node].first);
                }
                else{
                    lazy[node*2+1].second=min(lazy[node*2+1].second, lazy[node].second);
                }
            }
            lazy[node].first=1e18;
            lazy[node].second=1e18;
        }
        return;
    }
    void UpdateSeg(int node, int start, int end, int left, int right, ll value){
        if(left>right) return;
        //cout << node << " " << start << " " << end << " " << left << " " << right << " " << value << endl;
        LazyUpdate(node, start, end);
        //cout << "!" << endl;
        if(right<start||end<left) return;
        else if(left<=start&&end<=right){
            if(lazy[node].first>value){
                lazy[node].second=lazy[node].first;
                lazy[node].first=value;
            }
            else if(lazy[node].first<value){
                lazy[node].second=min(lazy[node].second, value);
            }
            LazyUpdate(node, start, end);
            //cout << node << " " << start << " " << end << " " << left << " " << right << endl;
        }
        else{
            int mid=(start+end)/2;
            //cout << mid << endl;
            UpdateSeg(node*2, start, mid, left, right, value);
            UpdateSeg(node*2+1, mid+1, end, left, right, value);
            if(seg[node*2].first<seg[node*2+1].first){
                seg[node].first=seg[node*2].first;
                seg[node].second=min(seg[node*2].second, seg[node*2+1].first);
            }
            else if(seg[node*2].first>seg[node*2+1].first){
                seg[node].first=seg[node*2+1].first;
                seg[node].second=min(seg[node*2].first, seg[node*2+1].second);
            }
            else{
                seg[node].first=seg[node*2].first;
                seg[node].second=min(seg[node*2].second, seg[node*2+1].second);
            }
        }
        return;
    }
    pair<ll, ll> SumSeg(int node, int start, int end, int left, int right){
        //cout << "start : " << start << " end : " << end << " left : " << left << " right : " << right << "\n";
        if(left>right) return {1e18, 1e18}; 
        LazyUpdate(node, start, end);
        if(right<start||end<left) return {1e18, 1e18};
        else if(left<=start&&end<=right){
            //cout << "start : " << start << " end : " << end << " seg[node] : " << seg[node] << "\n"; 
            return seg[node];
        }
        else{
            int mid=(start+end)/2;
            pair<ll, ll> A=SumSeg(node*2, start, mid, left, right);
            pair<ll, ll> B=SumSeg(node*2+1, mid+1, end, left, right);
            if(A.first<B.first){
                pair<ll, ll> ret;
                ret.first=A.first;
                ret.second=min(A.second, B.first);
                return ret;
            }
            else if(A.first>B.first){
                pair<ll, ll> ret;
                ret.first=B.first;
                ret.second=min(B.second, A.first);
                return ret;
            }
            else{
                pair<ll, ll> ret;
                ret.first=A.first;
                ret.second=min(A.second, B.second);
                return ret;
            }
        }
    }
};

Seg seg;

void dfs1(int cur_node, int p){
    //cout << cur_node << "\n";
    for(auto i : graph[cur_node]){
        if(i.first==p) continue;
        par[i.first]=cur_node;
        child[cur_node].push_back(i.first);
        V[i.first]=E[i.second].w;
        dfs1(i.first, cur_node);
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

void hldupd(int a, int b, int val){
    //cout << a << " " << b << endl;
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a, b);
        int st=top[a];
        seg.UpdateSeg(1, 0, N, in[st], in[a], val);
        a=par[st];
    }
    //cout << a << " " << b << endl;
    if(dep[a]>dep[b]) swap(a, b);
    //cout << a << " " << b << "\n";
    seg.UpdateSeg(1, 0, N, in[a]+1, in[b], val);
    return;
}

pair<ll, ll> hldquery(int a, int b){
    //cout << a << " " << b << "\n";
    pair<ll, ll> ret={1e18, 1e18};
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a, b);
        int st=top[a];
        //cout << in[a] << " " << in[st] << "\n";
        pair<ll, ll> temp=seg.SumSeg(1, 0, N, in[st], in[a]);
        if(ret.first>temp.first){
            ret.second=min(ret.first, temp.second);
            ret.first=temp.first;
        }
        else if(ret.first<temp.first){
            ret.second=min(ret.second, temp.first);
        }
        else{
            ret.second=min(ret.second, temp.second);
        }
        //cout << ret << "\n";
        a=par[st];
    }
    if(dep[a]>dep[b]) swap(a, b);
    //cout << a << " " << b << "\n";
    pair<ll, ll> temp=seg.SumSeg(1, 0, N, in[a]+1, in[b]);
    if(ret.first>temp.first){
        ret.second=min(ret.first, temp.second);
        ret.first=temp.first;
    }
    else if(ret.first<temp.first){
        ret.second=min(ret.second, temp.first);
    }
    else{
        ret.second=min(ret.second, temp.second);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int M;
    cin >> M;
    UnionFind UF(N+5);

    seg.init();

    for(int i=0; i<M; i++){
        int a, b;
        ll w;
        cin >> a >> b >> w;
        edge e={a, b, i, w};
        E.push_back(e);
        PQ.push(e);
    }
    ll total=0;
    while(!PQ.empty()){
        int a=PQ.top().start;
        int b=PQ.top().end;
        int num=PQ.top().num;
        ll weight=PQ.top().w;
        PQ.pop();
        if(UF.isSameSet(a, b)) continue;
        UF.UnionSet(a, b);
        //cout << a << " " << b << " " << weight << "\n";
        graph[a].push_back({b, num});
        graph[b].push_back({a, num});
        check[num]=1;
        total+=weight;
    }

    int flag=0;
    for(int i=1; i<=N; i++){
        if(!UF.isSameSet(1, i)){
            flag=1;
            break;
        }
    }

    if(flag==1){
        cout << -1;
        return 0;
    }
    dfs1(1, -1);
    dfs2(1);
    dfs3(1);

    /*for(int i=1; i<=N; i++) cout << in[i] << " ";
    cout << "\n";*/
    
    for(int i=0; i<E.size(); i++){
        if(check[i]==0){
            int a=E[i].start;
            int b=E[i].end;
            ll w=E[i].w;
            //cout << a << " " << b << " " << w << endl;
            hldupd(a, b, w);
        }
    }
    ll ans=1e18;
    for(int i=0; i<E.size(); i++){
        if(check[i]==1){
            int a=E[i].start;
            int b=E[i].end;
            ll w=E[i].w;
            pair<ll, ll> ret=hldquery(a, b);
            if(total<total-w+ret.first) ans=min(ans, total-w+ret.first);
            else if(total<total-w+ret.second) ans=min(ans, total-w+ret.second);
        }
    }
    if(ans==1e18) cout << -1;
    else cout << ans;
    return 0;
}