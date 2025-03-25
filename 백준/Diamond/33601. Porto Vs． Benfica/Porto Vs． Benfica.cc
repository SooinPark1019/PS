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
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
*/
int N, M;
vector<int> graph[200005];
vector<int> child[200005];

int sz[200005], dep[200005], top[200005], par[200005], in[200005], out[200005], sp[25][200005];
int pv=0;

void dfs1(int cur_node){
    sz[cur_node]=1;
    for(auto& i : child[cur_node]){
        dep[i]=dep[cur_node]+1;
        dfs1(i);
        sz[cur_node]+=sz[i];
        if(sz[i]>sz[child[cur_node][0]]) swap(i, child[cur_node][0]);
    }
}

void dfs2(int cur_node){
    in[cur_node]=++pv;
    for(auto i : child[cur_node]){
        if(i==child[cur_node][0]) top[i]=top[cur_node];
        else top[i]=i;
        dfs2(i);
    }
    out[cur_node]=pv;
}

vector<int> seg(200005*4, 1e18);
vector<int> lazy(200005*4, 1e18);

void lazyupdate(int node, int start, int end){
    if(lazy[node]!=1e18){
        seg[node]=min(seg[node], lazy[node]);
        if(start!=end){
            lazy[node*2]=min(lazy[node*2], lazy[node]);
            lazy[node*2+1]=min(lazy[node*2+1], lazy[node]);
        }
        lazy[node]=1e18;
    }
}

void range_update(int node, int start, int end, int left, int right, int val){
    lazyupdate(node, start, end);
    if(right<start||end<left) return;
    if(left<=start&&end<=right){
        lazy[node]=min(lazy[node], val);
        lazyupdate(node, start, end);
    }
    else{
        int mid=(start+end)>>1;
        range_update(node*2, start, mid, left, right, val);
        range_update(node*2+1, mid+1, end, left, right, val);
        seg[node]=min(seg[node*2], seg[node*2+1]);
    }
}

void point_update(int node, int start, int end, int index, int val){
    lazyupdate(node, start, end);
    if(index<start||end<index) return;
    if(start==end){
        seg[node]=val;
    }
    else{
        int mid=(start+end)>>1;
        point_update(node*2, start, mid, index, val);
        point_update(node*2+1, mid+1, end, index, val);
        seg[node]=min(seg[node*2], seg[node*2+1]);
    }
}

int min_query(int node, int start, int end, int left, int right){
    lazyupdate(node, start, end);
    if(right<start||end<left) return 1e18;
    if(left<=start&&end<=right){
        return seg[node];
    }
    int mid=(start+end)>>1;
    return min(min_query(node*2, start, mid, left, right), min_query(node*2+1, mid+1, end, left, right));
}

void hldupdate(int a, int b, int val){
    //cout << "a : " << a << " b : " << b << " val : " << val << "\n";
    while(top[a]!=top[b]){
        //cout << "a : " << a << " b : " << b << " val : " << val << "\n";
        if(dep[top[a]]<dep[top[b]]) swap(a, b);
        int st=top[a];
        range_update(1, 1, N, in[st], in[a], val);
        a=par[st];
    }
    //cout << "a : " << a << " b : " << b << " val : " << val << "\n";
    if(dep[a]>dep[b]) swap(a, b);
    range_update(1, 1, N, in[a], in[b], val);
}

int hldquery(int a, int b){
    int ret=1e18;
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a, b);
        int st=top[a];
        ret=min(ret, min_query(1, 1, N, in[st], in[a]));
        a=par[st];
    }
    if(dep[a]>dep[b]) swap(a, b);
    ret=min(ret, min_query(1, 1, N, in[a], in[b]));
    return ret;
}

int LCA(int a, int b){
    if(dep[b]>dep[a]) swap(a, b);
    for(int i=19; i>=0; i--){
        if(dep[a]-dep[b]&(1<<i)) a=sp[i][a];
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

    cin >> N >> M;

    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    memset(dep, -1, sizeof(dep));
    dep[N]=0;
    queue<int> Q;
    Q.push(N);

    while(!Q.empty()){
        int x=Q.front();
        Q.pop();
        for(auto i : graph[x]){
            if(dep[i]!=-1) continue;
            child[x].push_back(i);
            par[i]=x;
            sp[0][i]=x;
            dep[i]=dep[x]+1;
            Q.push(i);
        }
    }

    dfs1(N);
    dfs2(N);

    for(int i=1; i<20; i++){
        for(int j=1; j<=N; j++){
            sp[i][j]=sp[i-1][sp[i-1][j]];
        }
    }
    set<pii> S;
    for(int i=1; i<=N; i++){
        for(auto j : graph[i]){
            if(par[j]!=i&&par[i]!=j){
                int a=LCA(i, j);
                //cout << "i : " << i << " j : " << j << " lca : " << a << "\n";
                int temp=hldquery(a, a);
                //cout << "temp : " << temp << "\n";
                hldupdate(i, j, dep[i]+1+dep[j]);
                point_update(1, 1, N, in[a], temp);
            }
            //for(int i=1; i<=N; i++) cout << "i : " << i << " DP : " << hldquery(i, i) << "\n";
        }
    }

    //for(int i=1; i<=N; i++) cout << "i : " << i << " DP : " << hldquery(i, i) << "\n";
    vector<int> dis(200005, 1e18);
    dis[N]=0;
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    PQ.push({0, N});
    while(!PQ.empty()){
        int curdis=PQ.top().first;
        int curnode=PQ.top().second;
        PQ.pop();
        if(dis[curnode]!=curdis) continue;
        for(auto i : graph[curnode]){
            if(dis[i]>max(curdis+1, hldquery(i, i)-dep[i])){
                dis[i]=max(curdis+1, hldquery(i, i)-dep[i]);
                PQ.push({dis[i], i});
            }
        }
    }

    if(dis[1]>1e9) cout << -1;
    else cout << dis[1];

    return 0;
}
