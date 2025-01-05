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
#define int long long
//#define sz(x) (int)x.size()

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
typedef complex<double> cpx;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 1e9+7;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
PST로 잘 안되넹
내가 못하는 건지 원래 안되는건지

그러면 이렇게 하자
먼저 쿼리를 싹다 받고
루트 관찰을 한 번 해보자

결국에 문제가 되는 지점을 한 번 생각해보면
어떤 애들을 고려할지가 애매한 건데

*/
const int MAX=200005*4;
template<typename Node, typename Upd,
         typename Node2Node, typename Upd2Node>
struct Seg { // 1-indexed
public:
    Seg() : Seg(0, Node(), Upd()) {}
    explicit Seg(int n, const Node& nodeid, const Upd& updid)
        : n(n), nodeid(nodeid), updid(updid), lg(Log2(n)), sz(1 << lg), seg(sz << 1, nodeid) {}
    void Set(int i, const Node& val) { seg[--i | sz] = val; }
    void Init() { for (int i = sz - 1; i; --i) seg[i] = N2N(seg[i << 1], seg[i << 1 | 1]); }
    void Update(int i, const Upd& x) {  // point update + range query
        --i |= sz;
        seg[i] = U2N(x, seg[i]);
        while (i >>= 1) Up(i);
    }
    void Update(int l, int r, const Upd& x) {  // range update + point query
        --l |= sz, --r |= sz;
        for (int L = l, R = r; L <= R; L >>= 1, R >>= 1) {
            if (L & 1) seg[L] = N2N(x, seg[L++]);
            if (~R & 1) seg[R] = N2N(x, seg[R--]);
        }
        for (int i = 1; i <= lg; ++i) {
            if (l >> i << i != l) Up(l >> i);
            if (r + 1 >> i << i != r + 1) Up(r >> i);
        }
    }
    Node Query(int i) {  // point query + range update
        --i |= sz;
        Node ret = nodeid;
        while (i) {
            ret = N2N(ret, seg[i]);
            i >>= 1;
        }
        return ret;
    }
    Node Query(int l, int r) {  // range query + point update
        --l |= sz, --r |= sz;
        Node ret = nodeid;
        for (; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) ret = N2N(ret, seg[l++]);
            if (~r & 1) ret = N2N(ret, seg[r--]);
        }
        return ret;
    }
         /*Node Query(int l, int r) {  // 교환법칙이 성립하지 않는 연산에 대해서는 이 쿼리를 사용
        --l |= sz, --r |= sz;
        Node ret = nodeid;
        int cnt=0;
        for (int L = l, R = r; L <= R; L = (L+1)>>1, R = (R-1)>>1, cnt++);
        for (int i=cnt-1, L, R; i>=0; --i) {
            L = ((l - 1)>>i) + 1;
            R = ((r + 1)>>i) - 1;
            if (L & 1) ret = N2N(seg[L++], ret);
            if (~R & 1) ret = N2N(ret, seg[R--]);
        }
        return ret;
    }*/
private:
    const int n, lg, sz;
    const Node nodeid; const Upd updid;
    vector<Node> seg;
    Node2Node N2N; Upd2Node U2N;
    static int Log2(int n) {
        int ret = 0;
        while (n > 1 << ret) ret++;
        return ret;
    }
    void Up(int i) {
        seg[i] = N2N(seg[i << 1], seg[i << 1 | 1]);
    }
};
struct Node {  // 세그먼트 트리 노드 자료형 정의
    int val, cnt;
    Node() : Node(0, 0) {}
    constexpr Node(int val, int cnt) : val(val), cnt(cnt) {}
};
constexpr Node nodeid(0, 0);  // 노드 항등원
struct Upd {  // 업데이트에 사용할 자료형 정의
    int val, cnt;
    Upd() : Upd(0, 0) {}
    constexpr Upd(int val, int cnt) : val(val), cnt(cnt) {}
};
constexpr Upd updid(0, 0);  // 업데이트 항등원
struct Node2Node {  // 노드 연산 (구간 쿼리에 사용)
    Node operator() (const Node& a, const Node& b) const {
        return { a.val + b.val, a.cnt+b.cnt };
    }
};
struct Upd2Node {  // 업데이트를 노드에 적용
    Node operator() (const Upd& a, const Node& b) const {
        return { a.val, a.cnt };
    }
};

pii lastchangedrow[200005];
pii lastchangedcol[200005];

int N, Q;

void update_query(int cur_time, int index, int v, Seg<Node, Upd, Node2Node, Upd2Node>& seg, pii lastchanged[200005]){
    //cout << "curtime : " << cur_time << "\n";
    if(lastchanged[index].first!=0) seg.Update(lastchanged[index].first, {0, 0});
    lastchanged[index].first=cur_time;
    lastchanged[index].second=v;
    seg.Update(lastchanged[index].first, {lastchanged[index].second, 1});
    //cout << "seg : " << sum(1, 0, Q, lastchanged[index].first, lastchanged[index].first, seg).first << " " << sum(1, 0, Q, lastchanged[index].first, lastchanged[index].first, seg).second << "\n";
}

int sum_query(int cur_time, int index, Seg<Node, Upd, Node2Node, Upd2Node>& seg, pii lastchanged[200005]){
    //cout << "times : " << lastchanged[index].first << " " << cur_time << "\n";
    Node A=seg.Query(lastchanged[index].first, cur_time);
    //cout << A.first << " " << A.second << "\n";
    int ret=A.val+(N-A.cnt)*lastchanged[index].second;
    return ret;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q;
    Seg<Node, Upd, Node2Node, Upd2Node> rowseg(Q, nodeid, updid);
    Seg<Node, Upd, Node2Node, Upd2Node> colseg(Q, nodeid, updid);
    rowseg.Init();
    colseg.Init();
    for(int i=1; i<=Q; i++){
        int type;
        cin >> type;
        if(type==1){
            int index, v;
            cin >> index >> v;
            update_query(i, index, v, rowseg, lastchangedrow);
        }
        else if(type==2){
            int index, v;
            cin >> index >> v;
            update_query(i, index, v, colseg, lastchangedcol);
        }
        else if(type==3){
            int index;
            cin >> index;
            cout << sum_query(i, index, colseg, lastchangedrow) << "\n";
        }
        else{
            int index;
            cin >> index;
            cout << sum_query(i, index, rowseg, lastchangedcol) << "\n";
        }
    }

    return 0;
}
