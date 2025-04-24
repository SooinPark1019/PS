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
//#define sz(x) (int)x.size()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long

using namespace std;

//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
/*#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>//이걸 코드의 윗부분에 추가
void m_erase(ordered_set &OS, int val){
    int index = OS.order_of_key(val);
    ordered_set::iterator it = OS.find_by_order(index);
    if(*it == val) OS.erase(it);
}*/
//다른 건 통상적인 PBDS처럼 사용하면 되지만 erase는 반드시!!! 이 함수를 통해서만 해야 함
//m_erase(OS, 지울 원소)처럼 사용하면 된다. 꼭 주의하자.
//얘네 쓰려면 define int long long 꺼라.

typedef long long ll;
typedef complex<double> cpx;
//typedef __int128 i128;
typedef long double ld;
typedef pair<double, int> pdl;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 1e9+7;
const int MAXN = 200005;
const double PI = acos(-1);

/*
*/
vector<int> seg(MAXN*4, 0);
void update(int node, int start, int end, int index, int value){
    //cout << "node : " << node << " start : " << start << " end : " << end << " index : " << index << " value : " << value << "\n"; 
    if(index<start||end<index) return;
    if(start==end){
        seg[node]+=value;
    }
    else{
        int mid=(start+end)>>1;
        update(node*2, start, mid, index, value);
        update(node*2+1, mid+1, end, index, value);
        seg[node]=seg[node*2]+seg[node*2+1];
    }
    return;
}
int query(int node, int start, int end, int left, int right){
    if(right<start||end<left) return 0;
    if(left<=start&&end<=right) return seg[node];
    int mid=(start+end)>>1;
    return query(node*2, start, mid, left, right)+query(node*2+1, mid+1, end, left, right);
}

vector<int> graph[MAXN];
int sz[MAXN], dep[MAXN], top[MAXN], par[MAXN], in[MAXN], sp[20][MAXN];
vector<int> child[MAXN];
int pv=0, N;

void dfs1(int node, int p){
    for(auto i : graph[node]){
        if(i==p) continue;
        par[i]=node;
        sp[0][i]=node;
        child[node].push_back(i);
        dfs1(i, node);
    }
}

void dfs2(int node){
    sz[node]=1;
    for(auto& i: child[node]){
        dep[i]=dep[node]+1;
        dfs2(i);
        sz[node]+=sz[i];
        if(sz[i]>sz[child[node][0]]) swap(i, child[node][0]);
    }
}

void dfs3(int node){
    in[node]=++pv;
    for(auto i : child[node]){
        if(i==child[node][0]) top[i]=top[node];
        else top[i]=i;
        dfs3(i);
    }
}

void treeupdate(int node, int val){
    //cout << "update : " << in[node] << "\n";
    update(1, 1, N, in[node], val);
}

int sumquery(int a, int b){
    int ret=0;
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a, b);
        int st=top[a];
        //cout << "sum : " << in[st] << " " << in[a] << "\n";
        ret+=query(1, 1, N, in[st], in[a]);
        a=par[st];
    }
    if(dep[a]>dep[b]) swap(a, b);
    //cout << "sum : " << in[a] << " " << in[b] << "\n";
    ret+=query(1, 1, N, in[a], in[b]);
    return ret;
}

int LCA(int a, int b){
    if(dep[b]>dep[a]) swap(a, b);
    for(int j=19; j>=0; j--){
        if(dep[a]-dep[b]&(1<<j)) a=sp[j][a];
    }
    if(a==b) return a;
    for(int j=19; j>=0; j--){
        if(sp[j][a]!=sp[j][b]){
            a=sp[j][a];
            b=sp[j][b];
        }
    }
    return sp[0][a];
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Q;
    cin >> N >> Q;
    for(int i=2; i<=N; i++){
        int a;
        cin >> a;
        graph[a].push_back(i);
        graph[i].push_back(a);
    }
    dfs1(1, -1);
    dfs2(1);
    dfs3(1);
    for(int i=1; i<20; i++){
        for(int j=0; j<=N; j++){
            sp[i][j]=sp[i-1][sp[i-1][j]];
        }
    }
    while(Q--){
        int a, b, type;
        cin >> a >> b >> type;
        //cout << "LCA : " << LCA(a, b) << "\n";
        int res=sumquery(a, b);
        //cout << "res : " << res << "\n";
        res-=sumquery(LCA(a, b), LCA(a, b));
        //cout << "res : " << res << "\n";
        if(res) cout << "NO\n";
        else cout << "YES\n";
        //cout << a << " " << b << "\n";
        if(type){
            if(res==0) treeupdate(a, 1);
            else treeupdate(b, 1);
        }
    }
    return 0;
}
