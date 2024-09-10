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
//#define int long long

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;

template<typename Node, typename Lazy,
         typename Node2Node, typename Lazy2Node, typename Lazy2Lazy>
struct LazySeg { // 1-indexed
public:
    LazySeg() : LazySeg(0, Node(), Lazy()) {}
    explicit LazySeg(int n, const Node& nodeid, const Lazy& lazyid)
        : n(n), nodeid(nodeid), lazyid(lazyid), lg(Log2(n)), sz(1 << lg), seg(sz << 1, nodeid), lazy(sz, lazyid) {}
    void Set(int i, const Node& val) { //cout << i << " " << val.val1 << " " << val.val2 << endl; 
    seg[--i | sz] = val; }  // 초기값 할당
    void Init() { for (int i = sz - 1; i; --i) seg[i] = N2N(seg[i << 1], seg[i << 1 | 1]); }  // 초기화
    void Update(int i, const Lazy& x) {  // point update
        --i |= sz;
        for (int j = lg; j; --j) Down(i >> j);
        LazyProp(i, x);
        for (int j = 1; j <= lg; ++j) Up(i >> j);
    }
    void Update(int l, int r, const Lazy& x) {  // range update
        --l |= sz, --r |= sz;
        for (int i = lg; i; --i) {
            if (l >> i << i != l) Down(l >> i);
            if (r + 1 >> i << i != r + 1) Down(r >> i);
        }
        for (int L = l, R = r; L <= R; L >>= 1, R >>= 1) {
            if (L & 1) LazyProp(L++, x);
            if (~R & 1) LazyProp(R--, x);
        }
        for (int i = 1; i <= lg; ++i) {
            if (l >> i << i != l) Up(l >> i);
            if (r + 1 >> i << i != r + 1) Up(r >> i);
        }
    }
    Node Query(int i) {  // point query
        --i |= sz;
        for (int j = lg; j; --j) Down(i >> j);
        return seg[i];
    }
    Node Query(int l, int r) {  // range query
        --l |= sz, --r |= sz;
        Node ret = nodeid;
        for (int i = lg; i; --i) {
            if (l >> i << i != l) Down(l >> i);
            if (r + 1 >> i << i != r + 1) Down(r >> i);
        }
        for (; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) ret = N2N(ret, seg[l++]);
            if (~r & 1) ret = N2N(ret, seg[r--]);
        }
        return ret;
    }
private:
    const int n, lg, sz;
    const Node nodeid; const Lazy lazyid;
    vector<Node> seg; vector<Lazy> lazy;
    Node2Node N2N; Lazy2Node L2N; Lazy2Lazy L2L;
    static int Log2(int n) {
        int ret = 0;
        while (n > 1 << ret) ret++;
        return ret;
    }
    void LazyProp(int i, const Lazy& x) {
        seg[i] = L2N(x, seg[i]);
        if (i < sz) lazy[i] = L2L(x, lazy[i]);
    }
    void Down(int i) {
        LazyProp(i << 1, lazy[i]);
        LazyProp(i << 1 | 1, lazy[i]);
        lazy[i] = lazyid;
    }
    void Up(int i) {
        seg[i] = N2N(seg[i << 1], seg[i << 1 | 1]);
    }
};
struct Node {  // 세그먼트 트리 노드 자료형 정의
    int val1, val2;
    Node() : Node(1e9, -1e9) {}
    constexpr Node(int val1, int val2) : val1(val1), val2(val2) {}
};
constexpr Node nodeid(1e9, -1e9);  // 노드 항등원
struct Lazy {  // 레이지 자료형 정의
    int val1, val2;
    Lazy() : Lazy(1e9, -1e9) {}
    constexpr Lazy(int val1, int val2) : val1(val1), val2(val2) {}
};
constexpr Lazy lazyid(1e9, -1e9);  // 레이지 항등원
struct Node2Node {  // 노드 연산 (구간 쿼리에 사용)
    Node operator() (const Node& a, const Node& b) const {
        return { min(a.val1, b.val1), max(a.val2, b.val2) };
    }
};
struct Lazy2Node {  // 레이지를 노드에 적용하는 연산
    Node operator() (const Lazy& a, const Node& b) const {
        return { min(a.val1, b.val1), max(a.val2, b.val2) };
    }
};
struct Lazy2Lazy {  // 레이지를 전파할 때 기존 레이지와 전파된 레이지의 연산
    Lazy operator() (const Lazy& a, const Lazy& b) const {
        return { min(a.val1, b.val1), max(a.val2, b.val2) };
    }
};

pii sparsetable[18][100005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    int M;
    cin >> M;

    vector<LazySeg<Node, Lazy, Node2Node, Lazy2Node, Lazy2Lazy>> LS(18, LazySeg<Node, Lazy, Node2Node, Lazy2Node, Lazy2Lazy>(N, nodeid, lazyid));

    for(int i=1; i<18; i++){
        LS[i].Init();
    }


    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        if(a<b){
            LS[0].Update(a, min(a+K-1, b), Lazy(1e9, b));
        }
        else{
            LS[0].Update(max(a-K+1, b), a, Lazy(b, -1e9));
        }
    }

    for(int i=1; i<=N; i++){
        sparsetable[0][i]={min(LS[0].Query(i, i).val1, i), max(LS[0].Query(i, i).val2, i)};
        //cout << i << " " << sparsetable[i][0].first << " " << sparsetable[i][0].second << endl;
    }

    for(int i=1; i<18; i++){
        //cout << i << endl;
        for(int j=1; j<=N; j++){
            //cout << j << endl;
            Node A=LS[i-1].Query(sparsetable[i-1][j].first, sparsetable[i-1][j].second);
            sparsetable[i][j]={min(A.val1, j), max(A.val2, j)};
            //cout << sparsetable[j][i].first << " " << sparsetable[j][i].second << endl;
        }
        for(int j=1; j<=N; j++){
            LS[i].Update(j, Lazy(sparsetable[i][j].first, sparsetable[i][j].second));
        }
    }

    //cout << "!" << endl;

    int Q;
    cin >> Q;
    while(Q--){
        int S, T;
        cin >> S >> T;
        int left=0;
        int right=M;
        pii a={S, S};
        Node A=LS[17].Query(a.first, a.second);
        if(min(A.val1, a.first)>T||max(A.val2, a.second)<T){
            cout << -1 << "\n";
            continue;
        }
        ll ans=0;
        for(int i=16; i>=0; i--){
            Node A=LS[i].Query(a.first, a.second);
            if(min(a.first, A.val1)<=T&&max(a.second, A.val2)>=T) continue;
            ans+=(1ll<<i);
            a.first=min(a.first, A.val1);
            a.second=max(a.second, A.val2);
        }
        cout << ans+1 << "\n";
        /*while(left<=right){
            int mid=(left+right)/2;
            int temp=mid;
            pii a={S, S};
            int i=0;
            while(temp!=0){
                if((temp&1)!=0){
                    Node A=LS[i].Query(a.first, a.second);
                    a={min(A.val1, a.first), max(A.val2, a.second)};
                }
                i++;
                temp>>=1;
            }
            if(a.first<=T&&T<=a.second){
                ans=min(ans, mid);
                right=mid-1;
            }
            else left=mid+1;
        }
        if(ans==987654321) cout << -1 << "\n";
        else cout << ans << "\n";*/
    }

    return 0;
}