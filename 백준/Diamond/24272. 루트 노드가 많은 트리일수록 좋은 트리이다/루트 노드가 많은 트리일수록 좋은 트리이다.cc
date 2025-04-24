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
int N, Q;
vector<pii> seg(100005*4, {0, 1});
vector<int> lazy(100005*4);
vector<int> graph[100005];
int S[100005], E[100005], P[100005], cnt=0;
map<pii, int> edgetype;

void dfs(int x, int par){
    S[x]=++cnt;
    for(auto i : graph[x]){
        if(i==par) continue;
        P[i]=x;
        dfs(i, x);
    }
    E[x]=cnt;
    return;
}
pii merge(pii A, pii B){
    if(A.first<B.first) return A;
    if(A.first>B.first) return B;
    return {A.first, A.second+B.second};
}
void init(int node, int start, int end){
    if(start==end) seg[node]={0, 1};
    else{
        int mid=(start+end)>>1;
        init(node*2, start, mid);
        init(node*2+1, mid+1, end);
        seg[node]=merge(seg[node*2], seg[node*2+1]);
    }
}
void lazyupdate(int node, int start, int end){
    if(lazy[node]!=0){
        seg[node].first+=lazy[node];
        if(start!=end){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    return;
}
void update(int node, int start, int end, int left, int right, int value){
    if(left>right) return;
    lazyupdate(node, start, end);
    if(right<start||end<left) return;
    if(left<=start&&end<=right){
        lazy[node]+=value;
        lazyupdate(node, start, end);
    }
    else{
        int mid=(start+end)>>1;
        update(node*2, start, mid, left, right, value);
        update(node*2+1, mid+1, end, left, right, value);
        seg[node]=merge(seg[node*2], seg[node*2+1]);
    }
}
pii query(int node, int start, int end, int left, int right){
    lazyupdate(node, start, end);
    if(right<start||end<left) return {1e18, 0};
    if(left<=start&&end<=right) return seg[node];
    int mid=(start+end)>>1;
    return merge(query(node*2, start, mid, left, right), query(node*2+1, mid+1, end, left, right));
}
void rollback(int a, int b){//a->b를 rollback, b쪽에 -1하기
    if(a==P[b]){
        //cout << S[b] << " " << E[b] << -1 << "\n";
        update(1, 1, N, S[b], E[b], -1);
    }
    else{
        //cout << 1 << " " << S[a]-1 << -1 << "\n";
        //cout << E[a]+1 << " " << N << -1 << "\n";
        update(1, 1, N, 1, S[a]-1, -1);
        update(1, 1, N, E[a]+1, N, -1);
    }
}
void edgeupdate(int a, int b, int flag){//a->b를 추가
    if(edgetype[{a, b}]) rollback(a, b);
    if(edgetype[{b, a}]) rollback(b, a);
    edgetype[{a, b}]=0;
    edgetype[{b, a}]=0;

    if(flag==0) return;

    edgetype[{a, b}]=1;
    if(a==P[b]){
        //cout << S[b] << " " << E[b] << 1 << "\n";
        update(1, 1, N, S[b], E[b], 1);
    }
    else{
        //cout << 1 << " " << S[a]-1 << 1 << "\n";
        //cout << E[a]+1 << " " << N << 1 << "\n";
        update(1, 1, N, 1, S[a]-1, 1);
        update(1, 1, N, E[a]+1, N, 1);
    }
    return;
}
void output(){
    pii ans=query(1, 1, N, 1, N);
    if(ans.first!=0) cout << 0 << "\n";
    else cout << ans.second << "\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    init(1, 1, N);

    vector<array<int, 3>> edges;

    for(int i=0; i<N-1; i++){
        int a, b;
        char c1, c2;
        cin >> a >> c1 >> c2 >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        if(c2=='>') edges.push_back({a, b, 1});
        else if(c1=='<') edges.push_back({b, a, 1});
        else edges.push_back({a, b, 0});
    }

    dfs(1, -1);

    for(auto e : edges){
        int n1=e[0];
        int n2=e[1];
        int type=e[2];
        if(type==0) continue;
        edgeupdate(n1, n2, 1);
    }

    cin >> Q;

    while(Q--){
        int a, b;
        char c1, c2;
        cin >> a >> c1 >> c2 >> b;
        if(c2=='>') edgeupdate(a, b, 1);
        else if(c1=='<') edgeupdate(b, a, 1);
        else edgeupdate(a, b, 0);
        output();
    }

    return 0;
}
