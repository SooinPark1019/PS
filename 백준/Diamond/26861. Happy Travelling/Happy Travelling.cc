#include <ext/rope>
#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
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
int weight[500];

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
    Node() : Node(-1e18) {}
    constexpr Node(int val) : val(val) {}
};
constexpr Node nodeid(-1e18);  // 노드 항등원
struct Upd {  // 업데이트에 사용할 자료형 정의
    int val;
    Upd() : Upd(-1e18) {}
    constexpr Upd(int val) : val(val) {}
};
constexpr Upd updid(-1e18);  // 업데이트 항등원
struct Node2Node {  // 노드 연산 (구간 쿼리에 사용)
    Node operator() (const Node& a, const Node& b) const {
        return { max(a.val, b.val) };
    }
};
struct Upd2Node {  // 업데이트를 노드에 적용
    Node operator() (const Upd& a, const Node& b) const {
        return { a.val };
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, D;
    cin >> N >> K >> D;
    vector<int> V(N+1);
    vector<int> T(N+1);
    for(int i=1; i<=N; i++){
        cin >> V[i];
    }
    for(int i=1; i<=N-1; i++){
        cin >> T[i];
    }
    int ans;
    if(K<=100){
        vector<Seg<Node, Upd, Node2Node, Upd2Node>> SG(K, Seg<Node, Upd, Node2Node, Upd2Node>(N, nodeid, updid));
        for(int i=0; i<K; i++){
            SG[i].Init();
        }
        SG[N%K].Update(N, V[N]+weight[N%K]);
        for(int i=N-1; i>=1; i--){
            weight[i%K]+=D;
            int temp=-1e18;
            for(int j=0; j<K; j++){
                temp=max(temp, SG[j].Query(i+1, i+T[i]).val-weight[j%K]);
                //cout << i+1 << " " << i+T[i] << "\n";
            }
            temp+=V[i];
            ans=temp;
            SG[i%K].Update(i, temp+weight[i%K]);
        }
    }
    else{
        Seg<Node, Upd, Node2Node, Upd2Node> SG(N, nodeid, updid);
        SG.Init();
        vector<int> L(N+1);
        SG.Update(N, V[N]);
        L[N]=V[N];
        for(int i=N-1; i>=1; i--){
            for(int j=i+K; j<=N; j+=K){
                L[j]-=D;
                SG.Update(j, L[j]);
            }
            int a=SG.Query(i+1, i+T[i]).val;
            a+=V[i];
            ans=a;
            L[i]=a;
            SG.Update(i, a);
        }
    }
    cout << ans;
    return 0;
}