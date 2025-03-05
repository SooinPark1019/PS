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
const double PI = acos(-1);

/*
DP[i]=첫번째 재료의 가치가 i일 때 두번째 재료의 가능한 최대 가치

두 차원 모두 양수인 거는 당연히 그대로 합치고
그렇지 않을 경우 취할 차원을 선택

나머지는 취할 차원만 취하거나 아니면 둘다 취해야 함
*/

const int MAXN=100005;
struct st{
    int left, right, cnt;
};

st merge(st A, st B){
    st ret;
    if(A.left==0&&B.left==0) return {0, 0, 0};
    else if(A.left==0) return B;
    else if(B.left==0) return A;
    ret.left=A.left;
    ret.right=B.right;
    if(A.right==B.left) ret.cnt=A.cnt+B.cnt+1;
    else ret.cnt=A.cnt+B.cnt;
    return ret; 
}

bool compare(st A, st B){
    return A.left<B.left;
}

vector<st> seg;
vector<int> lazy;

int sz[MAXN], dep[MAXN], top[MAXN], par[MAXN], in[MAXN], out[MAXN];
vector<int> child[MAXN], graph[MAXN];
int N, pv=0;

void dfs1(int cur_node, int p){
    for(auto i : graph[cur_node]){
        if(i==p) continue;
        par[i]=cur_node;
        child[cur_node].push_back(i);
        dfs1(i, cur_node);
    }
}

void dfs2(int cur_node){
    sz[cur_node]=1;
    for(auto& i : child[cur_node]){
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

void lazyupdate(int node, int start, int end){
    if(lazy[node]>0){
        seg[node].cnt=end-start;    
        seg[node].left=lazy[node];
        seg[node].right=lazy[node];
        if(start!=end){
            lazy[node*2]=lazy[node];
            lazy[node*2+1]=lazy[node];
        }
        lazy[node]=0;
    }
}

void update(int node, int start, int end, int left, int right, int val){
    //cout << "update " << "node : " << node << " start : " << start << " end : " << end << " left : " << left << " right : " << right << "\n";
    lazyupdate(node, start, end);
    if(right<start||end<left) return;
    if(left<=start&&end<=right){
        lazy[node]=val;
        lazyupdate(node, start, end);
        //cout << "node : " << node << " start : " << start << " end : " << end << " seg : " << seg[node].cnt << " " << seg[node].left << " " << seg[node].right << "\n";
    }
    else{
        int mid=(start+end)>>1;
        update(node*2, start, mid, left, right, val);
        update(node*2+1, mid+1, end, left, right, val);
        seg[node]=merge(seg[node*2], seg[node*2+1]);
        //cout << "node : " << node << " start : " << start << " end : " << end << " seg : " << seg[node].cnt << " " << seg[node].left << " " << seg[node].right << "\n";
    }
}

st sum_query(int node, int start, int end, int left, int right){
    //cout << "sum " << "node : " << node << " start : " << start << " end : " << end << " left : " << left << " right : " << right << "\n";
    lazyupdate(node, start, end);
    if(right<start||end<left) return {0, 0, 0};
    if(left<=start&&end<=right) return seg[node];
    int mid=(start+end)>>1;
    return merge(sum_query(node*2, start, mid, left, right), sum_query(node*2+1, mid+1, end, left, right));
}

void hldupdate(int a, int b, int val){
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a, b);
        int st=top[a];
        //cout << "left : " << in[st] << " right : " << in[a] << "\n";
        update(1, 0, N, in[st], in[a], val);
        a=par[st];
    }
    if(dep[a]>dep[b]) swap(a, b);
    //cout << "left : " << in[a] << " right : " << in[b] << "\n";
    update(1, 0, N, in[a], in[b], val);
    return;
}

int hldquery(int a, int b){
    pair<int, st> A={a, {0, 0, 0}};
    pair<int, st> B={b, {0, 0, 0}};
    vector<st> V;
    while(top[a]!=top[b]){
        if(dep[top[a]]<dep[top[b]]) swap(a, b);
        int ct=top[a];
        st temp=sum_query(1, 0, N, in[ct], in[a]);
        //cout << " left : " << ct << " right : " << a << "\n";
        if(a==A.first){
            //cout << "A!\n";
            //cout << "temp left : " << temp.left << " temp right : " << temp.right << " temp.cnt : " << temp.cnt << "\n";
            //cout << "A left : " << A.second.left << " A right : " << A.second.right << " A.cnt : " << A.second.cnt << "\n";
            A.second=merge(temp, A.second);
            //cout << "A left : " << A.second.left << " A right : " << A.second.right << " A.cnt : " << A.second.cnt << "\n";
            a=par[ct];
            A.first=a;
        }
        else{
            //cout << "B!\n";
            //cout << "temp left : " << temp.left << " temp right : " << temp.right << " temp.cnt : " << temp.cnt << "\n";
            //cout << "B left : " << B.second.left << " B right : " << B.second.right << " B.cnt : " << B.second.cnt << "\n";
            B.second=merge(temp, B.second);
            //cout << "B left : " << B.second.left << " B right : " << B.second.right << " B.cnt : " << B.second.cnt << "\n";
            a=par[ct];
            B.first=a;
        }
    }
    if(dep[a]>dep[b]) swap(a, b);
    //cout << " left : " << a << " right : " << b << "\n";
    st temp=sum_query(1, 0, N, in[a], in[b]);
    if(b==A.first){
        //cout << "A!\n";
        //cout << "temp left : " << temp.left << " temp right : " << temp.right << " temp.cnt : " << temp.cnt << "\n";
        //cout << "A left : " << A.second.left << " A right : " << A.second.right << " A.cnt : " << A.second.cnt << "\n";
        A.second=merge(temp, A.second);
        //cout << "A left : " << A.second.left << " A right : " << A.second.right << " A.cnt : " << A.second.cnt << "\n";
        //cout << "B left : " << B.second.left << " B right : " << B.second.right << " B.cnt : " << B.second.cnt << "\n";
        
    }
    else{
        //cout << "B!\n";
        B.second=merge(temp, B.second);
    }
    int ans=A.second.cnt+B.second.cnt;
        if(A.second.left==B.second.left) ans++;
        return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--){
        int M;
        cin >> N >> M;
        memset(sz, 0, sizeof(sz));
        memset(dep, 0, sizeof(dep));
        memset(top, 0, sizeof(top));
        memset(par, 0, sizeof(par));
        memset(in, 0, sizeof(in));
        memset(out, 0, sizeof(out));
        seg.clear();
        seg.resize(4*N, {0, 0, 0});
        lazy.clear();
        lazy.resize(4*N, 0);
        pv=0;
        for(int i=0; i<=N; i++){
            child[i].clear();
            graph[i].clear();
        }
        for(int i=0; i<N-1; i++){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        dfs1(1, -1);
        dfs2(1);
        dfs3(1);
        /*for(int i=1; i<=N; i++){
            cout << "i : " << i << " in : " << in[i] << " top : " << top[i] << "\n";
        }*/
        vector<int> vis(N+1, 0);
        vis[1]=1;
        queue<pii> Q;
        Q.push({1, 1});
        while(!Q.empty()){
            int x=Q.front().first;
            int color=Q.front().second;
            Q.pop();
            hldupdate(x, x, color);
            for(auto i : graph[x]){
                if(vis[i]!=0) continue;
                vis[i]=1;
                Q.push({i, 3-color});
            }
        }
        /*for(int i=1; i<=N; i++){
            st temp=sum_query(1, 0, N, in[i], in[i]);
            cout << "i : " << i << " left : " << temp.left << " right : " << temp.right << " " << " cnt : " << temp.cnt << "\n";
        }
        cout << "-----------\n";*/
        //cout << "-------------------------\n";
        for(int i=1; i<=M; i++){
            int type;
            cin >> type;
            if(type==1){
                int a, b;
                cin >> a >> b;
                hldupdate(a, b, 3+i);
            }
            else{
                int a, b;
                cin >> a >> b;
                cout << hldquery(a, b) << "\n";
            }
            /*for(int j=1; j<=N; j++){
                st temp=sum_query(1, 0, N, in[j], in[j]);
                cout << "i : " << j << " left : " << temp.left << " right : " << temp.right << " " << " cnt : " << temp.cnt << "\n";
            }
            cout << "-----------\n";*/
        }
    }

    return 0;
}
