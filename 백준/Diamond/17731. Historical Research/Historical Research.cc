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

/*

*/

int N, sqrtn;
struct query{
    int start, end, index;
};
bool compare(query A, query B){
    if(A.start/sqrtn==B.start/sqrtn) return A.end<B.end;
    return A.start/sqrtn < B.start/sqrtn;
}//쿼리 비교함수
vector<int> V(100005);
vector<query> Q;
int ans[100005];
map<int, int> cnt;
multiset<int> MS;
map<int, int> indexa;

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
    int val;
    Node() : Node(0) {}
    constexpr Node(int val) : val(val) {}
};
constexpr Node nodeid(0);  // 노드 항등원
struct Upd {  // 업데이트에 사용할 자료형 정의
    int val;
    Upd() : Upd(0) {}
    constexpr Upd(int val) : val(val) {}
};
constexpr Upd updid(0);  // 업데이트 항등원
struct Node2Node {  // 노드 연산 (구간 쿼리에 사용)
    Node operator() (const Node& a, const Node& b) const {
        return { max(a.val, b.val) };
    }
};
struct Upd2Node {  // 업데이트를 노드에 적용
    Node operator() (const Upd& a, const Node& b) const {
        return { a.val+b.val };
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A;
    cin >> N >> A;
    sqrtn=sqrt(N);
    vector<int> X;
    for(int i=1; i<=N; i++){
        cin >> V[i];
        X.push_back(V[i]);
    }
    sort(all(X));
    X.erase(unique(all(X)), X.end());
    for(int i=0; i<X.size(); i++){
        indexa[X[i]]=i+1;
    }
    for(int i=1; i<=N; i++){
        V[i]=indexa[V[i]];
    }
    for(int i=0; i<A; i++){
        int a, b;
        cin >> a >> b;
        Q.push_back({a, b, i});
    }   
    sort(all(Q), compare);
    int start=Q[0].start;
    int end=Q[0].end;
    int index=Q[0].index;
    Seg<Node, Upd, Node2Node, Upd2Node> SG(N, nodeid, updid);
    SG.Init();
    for(int i=start; i<=end; i++){
        //cout << V[i] << " " << X[V[i]-1] << "\n";
        SG.Update(V[i], X[V[i]-1]);
    }
    ans[index]=SG.Query(1, N).val;
    for(int i=1; i<A; i++){
        int curs=Q[i].start;
        int cure=Q[i].end;
        int curi=Q[i].index;
        //cout << curs << " " <<cure << endl;
        while(start>curs){
            start--;
            SG.Update(V[start], X[V[start]-1]);
        }
        while(start<curs){
            SG.Update(V[start], -X[V[start]-1]);
            start++;
        }
        while(end<cure){
            end++;
            SG.Update(V[end], X[V[end]-1]);
        }
        while(end>cure){
            SG.Update(V[end], -X[V[end]-1]);
            end--;
        }
        //cout << SG.Query(1, N).val << "\n";
        ans[curi]=SG.Query(1, N).val;
    }
    for(int i=0; i<A; i++) cout << ans[i] << "\n";
    return 0;
}