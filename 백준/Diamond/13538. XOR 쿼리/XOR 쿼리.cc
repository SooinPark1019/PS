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
const ll mod = 1e7;
const int MAXN = (1<<18)+5;
const int D = 20;

/*
*/

const int MAX_DEPTH=20;
const int MAX_ST=1<<MAX_DEPTH;
const int MAX=500001;
const int MAX_RANGE=500001;
const int MAX_NODE=MAX*MAX_DEPTH+MAX_ST;

struct Node{
    int val;
    int ns, ne;
    int Nnum;
    int lnum, rnum;
    Node(): Node(-1, -1, -1){}
    Node(int ns, int ne, int Nnum): val(0), ns(ns), ne(ne), Nnum(Nnum), lnum(-1), rnum(-1){}
};

struct PersistentSegTree{
    int TN;
    int ncnt=0;
    int root[MAX];
    Node node[MAX_NODE];

    PersistentSegTree(): TN(0), ncnt(0){
        fill(root, root+MAX, -1);
        root[TN++]=initialize(0, MAX_ST/2);
    }
    int initialize(int s, int e){
        Node& curr=node[ncnt]=Node(s, e, ncnt);
        ncnt++;
        if(s+1<e){
            int mid=(s+e)/2;
            curr.lnum=initialize(s, mid);
            curr.rnum=initialize(mid, e);
        }
        return curr.Nnum;
    }
    void addNode(int y, int val){
        root[TN]=addNode(node[root[TN-1]], y, val, 0, MAX_ST/2);
        TN++;
    }
    int addNode(Node& shadow, int y, int val, int s, int e){
        if(e<=y||y<s) return shadow.Nnum;
        Node& curr=node[ncnt]=Node(s, e, ncnt);
        ncnt++;
        if(s+1==e){
            curr.val=shadow.val+val;
        }
        else{
            int mid=(s+e)/2;
            curr.lnum=addNode(node[shadow.lnum], y, val, s, mid);
            curr.rnum=addNode(node[shadow.rnum], y, val, mid, e);
            curr.val=node[curr.lnum].val+node[curr.rnum].val;
        }
        return curr.Nnum;
    }
    int sum(int tn, int s, int e){
        return sum(node[root[tn]], s, e);
    }
    int sum(Node& curr, int s, int e){
        if(e<=curr.ns||curr.ne<=s) return 0;
        if(s<=curr.ns&&curr.ne<=e) return curr.val;
        return sum(node[curr.lnum], s, e)+sum(node[curr.rnum], s, e);
    }
    // 인덱스 s~e 내에서 k번째로 작은 값을 찾아옴(k는 0-based)
    int get_kth(int s, int e, int k){
        return get_kth(node[root[s-1]], node[root[e]], k);
    }
    int get_kth(Node& curs, Node& cure, int k){
        if(cure.ns+1==cure.ne) return cure.ns;
        int lcnt=node[cure.lnum].val-node[curs.lnum].val;
        if(lcnt<=k){
            return get_kth(node[curs.rnum], node[cure.rnum], k-lcnt);
        }
        else{
            return get_kth(node[curs.lnum], node[cure.lnum], k);
        }
    }
    int xormax(int s, int e, int k){
        return xormax(node[root[s-1]], node[root[e]], k);
    }
    int xormax(Node& curs, Node& cure, int k){
        if(curs.ns+1==curs.ne) return curs.ns;
        int a=63-__builtin_clzll((curs.ne-curs.ns)>>1);
        int lcnt=node[cure.lnum].val-node[curs.lnum].val;
        int rcnt=node[cure.rnum].val-node[curs.rnum].val;
        //cout << curs.ns << " " << curs.ne << " " << a << " " << lcnt << " " << rcnt << "\n";
        if(lcnt&&rcnt){
            if((k&(1ll<<a))!=0) return xormax(node[curs.lnum], node[cure.lnum], k);
            else return xormax(node[curs.rnum], node[cure.rnum], k);
        }
        else if(lcnt){
            return xormax(node[curs.lnum], node[cure.lnum], k);
        }
        else{
            return xormax(node[curs.rnum], node[cure.rnum], k);
        }
    }
    void reduce(int k){
        TN-=k;
    }
};

PersistentSegTree PST;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    while(N--){
        int type;
        cin >> type;
        if(type==1){
            int a;
            cin >> a;
            PST.addNode(a, 1);
        }
        else if(type==2){
            int L, R, x;
            cin >> L >> R >> x;
            cout << PST.xormax(L, R, x) << "\n";
        }
        else if(type==3){
            int k;
            cin >> k;
            PST.reduce(k);
        }
        else if(type==4){
            int L, R, x;
            cin >> L >> R >> x;
            cout << PST.sum(R, 0, x+1)-PST.sum(L-1, 0, x+1) << "\n";
        }
        else{
            int L, R, k;
            cin >> L >> R >> k;
            cout << PST.get_kth(L, R, k-1) << "\n";
        }
    }

    return 0;
}
