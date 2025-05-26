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
const ll mod = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);
const int FLAG_DEBUG = 0;

/*
*/
vector<pii> seg;
vector<int> lazy;
pii merge(pii A, pii B){
    if(A.first<B.first) return A;
    else if(A.first>B.first) return B;
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
    if(lazy[node]){
        seg[node].first+=lazy[node];
        if(start!=end){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
}
void update(int node, int start, int end, int left, int right, int value){
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
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int H, W, L, P;
    cin >> H >> W >> L >> P;

    vector<pii> trees;

    for(int i=0; i<P; i++){
        int x, y;
        cin >> x >> y;
        trees.push_back({x, y});
    }
    int ans=0;
    for(int i=L; i<=min(H, W); i++){
        seg.clear();
        lazy.clear();
        seg.resize(W*4+5);
        lazy.resize(W*4+5, 0);
        init(1, 1, W);

        //cout << query(1, 1, W, 1, W).first << " " << query(1, 1, W, 1, W).second << "\n";

        vector<array<int, 4>> V;
        for(auto p : trees){
            if(p.first-i+1>=1){
                V.push_back({p.first-i+1, max(1ll, p.second-i+1), p.second, 1});
                V.push_back({max(1ll, p.first-i+2), max(1ll, p.second-i+2), max(1ll, p.second-1), -1});
            }
            else{
                if(p.second-i+1>=1) V.push_back({1, p.second-i+1, p.second-i+1, 1});
                V.push_back({1, p.second, p.second, 1});
            }
            V.push_back({p.first, max(1ll, p.second-i+2), max(1ll, p.second-1), 1});
            if(p.first+1<=H) V.push_back({p.first+1, max(1ll, p.second-i+1), p.second, -1});
        }

        sort(all(V));

        int curpointer=0;
        for(int j=1; j<=H-i+1; j++){
            while(curpointer<V.size()&&V[curpointer][0]==j){
                update(1, 1, W, V[curpointer][1], V[curpointer][2], V[curpointer][3]);
                curpointer++;
            }
            pii res=query(1, 1, W, 1, W-i+1);
            if(!res.first) ans+=res.second;
        }
    }

    cout << ans;

    return 0;
}