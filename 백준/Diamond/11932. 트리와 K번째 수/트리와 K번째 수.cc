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
const int D = 18;

/*
*/

const int MAX_DEPTH=18;
const int MAX_ST=1<<MAX_DEPTH;
const int MAX=100005;
const int MAX_RANGE=100005;
const int MAX_NODE=MAX*MAX_DEPTH+MAX_ST;
vector<int> graph[MAX];
vector<int> X;
vector<int> V;
map<int, int> dict;
int depth[MAX], sp[MAX_DEPTH][MAX], rootnum[MAX];

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
    void addNode(int curnode, int val){
        root[TN]=addNode(node[root[rootnum[sp[0][curnode]]]], dict[V[curnode]], val, 0, MAX_ST/2);
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
    int get_kth(int a, int b, int c, int d, int k){
        //cout << root[a] << " " << root[b] << " " << root[c] << " " << root[d] << endl;
        return get_kth(node[root[a]], node[root[b]], node[root[c]], node[root[d]], k);
    }
    int get_kth(Node& cura, Node& curb, Node& curc, Node& curd, int k){
        if(cura.ns+1==cura.ne) return cura.ns;
        //cout << cura.Nnum << " " << curb.Nnum << " " << curc.Nnum <<  " " << curd.Nnum << "\n";
        //cout << node[cura.lnum].ns << " " << node[curb.lnum].ns << " " << node[curc.lnum].ns << " " << node[curd.lnum].ns << " " << "\n";
        //cout << node[cura.lnum].ne << " " << node[curb.lnum].ne << " " << node[curc.lnum].ne << " " << node[curd.lnum].ne << " " << "\n";
        int lcnt=node[cura.lnum].val+node[curb.lnum].val-node[curc.lnum].val-node[curd.lnum].val;
        //cout << lcnt << endl;
        if(lcnt<=k){
            return get_kth(node[cura.rnum], node[curb.rnum], node[curc.rnum], node[curd.rnum], k-lcnt);
        }
        else{
            return get_kth(node[cura.lnum], node[curb.lnum], node[curc.lnum], node[curd.lnum], k);
        }
    }
};

PersistentSegTree PST;

void lca_dfs(int x) {  // 모든 정점의 깊이와 부모를 전처리, 루트 노드의 부모가 자기 자신이 되도록 구현하면 편리함
    for (auto& nx : graph[x]) {
        if (depth[nx] > -1) continue;
        depth[nx] = depth[x] + 1;
        sp[0][nx] = x;
        lca_dfs(nx);
    }
}

int LCA(int a, int b) {
    if (depth[b] > depth[a]) swap(a, b);
    //cout << a << " " << b << " " << depth[a] << " " << depth[b] << "\n";
    for (int j = D - 1; j >= 0; --j) {
        //cout << (depth[a] - depth[b] & (1 << j)) << "\n"; // 두 정점의 깊이를 동일하게 만드는 과정
        if (depth[a] - depth[b] & (1 << j)) a = sp[j][a];
    }
    //cout << a << "\n";
    if (a == b) return a;  // a 또는 b가 LCA인 경우
    for (int j = D - 1; j >= 0; --j) {  // 공통 조상을 찾는 과정
        if (sp[j][a] != sp[j][b]) {
            a = sp[j][a];
            b = sp[j][b];
        }
    }
    //cout << a << "\n";
    return sp[0][a];
}

void add_dfs(int curnode){
    //cout << curnode << " " << sp[0][curnode] << "\n";
    rootnum[curnode]=PST.TN;
    //cout << PST.TN << "\n";
    PST.addNode(curnode, 1);
    for(auto i : graph[curnode]){
        //cout << "i : " << i << "\n";
        if(i==sp[0][curnode]) continue;
        add_dfs(i);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    V.resize(N+1);
    for(int i=1; i<=N; i++){
        cin >> V[i];
        X.push_back(V[i]);
    }

    sort(all(X));
    X.erase(unique(all(X)), X.end());

    for(int i=0; i<X.size(); i++){
        dict[X[i]]=i;
    }

    for(int i=1; i<N; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    memset(depth, -1, sizeof(depth));
    depth[1]=0;
    lca_dfs(1);

    for (int i = 1; i < D; ++i) {  // 희소 배열 구성
        for (int j = 1; j <= N; ++j) {
            sp[i][j] = sp[i - 1][sp[i - 1][j]];
        }
    } // LCA를 원하는 곳에 사용

    add_dfs(1);

    while(M--){
        int a, b, k;
        cin >> a >> b >> k;
        int c=LCA(a, b);
        int d=sp[0][c];
        //cout << a << " " << b << " " << c << " " << d << endl;
        //cout << rootnum[a] << " " << rootnum[b] << " " << rootnum[c] << " " << rootnum[d] << endl;
        //cout << PST.get_kth(rootnum[a], rootnum[b], rootnum[c], rootnum[d], k-1) << endl;
        cout << X[PST.get_kth(rootnum[a], rootnum[b], rootnum[c], rootnum[d], k-1)] << "\n";
    }

    return 0;
}
