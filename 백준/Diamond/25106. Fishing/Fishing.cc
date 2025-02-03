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
typedef pair<double, int> pdl;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 1e9+7;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
Z로 생각을 해보자
먼저 첫번째 두 배열을 그대로 붙인 상태로 시작을 해서
Z값을 계산
접두사=접미사 되는 곳을 찾아가지고 비용계산
남은 것을 다음 문자열로 이월
*/

const int MAX_DEPTH = 20;
const int MAX_ST = 1 << MAX_DEPTH;
const int MAX = 300005;
const int MAX_NODE = MAX_ST+MAX*MAX_DEPTH;

struct Node{
    int leftsum, rightsum, maxsum, totalsum;
    int ns, ne, nNum, lNum, rNum;

    Node():Node(-1, -1, -1){}
    Node(int ns1, int ne1, int nNum1) : leftsum(0), rightsum(0), maxsum(0), totalsum(0), ns(ns1), ne(ne1), nNum(nNum1), lNum(-1), rNum(-1){}
};

struct PST{
    int TN;
    int ncnt;
    int root[MAX];
    Node node[MAX_NODE];

    PST():TN(0), ncnt(0){
        fill(root, root+MAX, -1);
        root[TN++]=initialize(0, MAX_ST/2);
    }

    int initialize(int s, int e){
        Node& curr=node[ncnt]=Node(s, e, ncnt);
        ncnt++;
        if(s+1<e){
            int mid=(s+e)>>1;
            curr.lNum=initialize(s, mid);
            curr.rNum=initialize(mid, e);
        }
        return curr.nNum;
    }

    void addNode(int y, int val){
        //cout << "TN : " << TN << "\n";
        root[TN]=addNode(node[root[TN-1]], y, val, 0, MAX_ST/2);
        ++TN;
    }

    int addNode(Node& shadow, int y, int val, int s, int e){
        //cout << s << " " << e << " " << y << " " << val << "\n";
        if(e<=y||y<s) return shadow.nNum;
        Node& curr=node[ncnt]=Node(s, e, ncnt);
        ncnt++;
        if(s+1==e){
            curr.leftsum=shadow.leftsum+val;
            curr.rightsum=shadow.rightsum+val;
            curr.maxsum=shadow.maxsum+val;
            curr.totalsum=shadow.totalsum+val;
        }
        else{
            int mid=(s+e)>>1;
            curr.lNum=addNode(node[shadow.lNum], y, val, s, mid);
            curr.rNum=addNode(node[shadow.rNum], y, val, mid, e);
            curr.leftsum=max(node[curr.lNum].leftsum, node[curr.lNum].totalsum+node[curr.rNum].leftsum);
            curr.rightsum=max(node[curr.rNum].rightsum, node[curr.rNum].totalsum+node[curr.lNum].rightsum);
            curr.maxsum=max({node[curr.lNum].maxsum, node[curr.rNum].maxsum, node[curr.lNum].rightsum+node[curr.rNum].leftsum});
            curr.totalsum=node[curr.lNum].totalsum+node[curr.rNum].totalsum;
        }
        return curr.nNum;
    }

    Node sum(int tn, int s, int e){
        return sum(node[root[tn]], s, e);
    }

    Node sum(Node& curr, int s, int e){
        //cout << "s : " << curr.ns << " e : " << curr.ne-1 << "\n";
        if(e<=curr.ns||curr.ne<=s){
            Node ret;
            ret.leftsum=0;
            ret.rightsum=0;
            ret.maxsum=0;
            ret.totalsum=0;
            return ret;
        }
        if(s<=curr.ns&&curr.ne<=e) return curr;
        Node A=sum(node[curr.lNum], s, e);
        Node B=sum(node[curr.rNum], s, e);
        Node ret;
        ret.leftsum=max(A.leftsum, A.totalsum+B.leftsum);
        ret.rightsum=max(B.rightsum, B.totalsum+A.rightsum);
        ret.maxsum=max({A.maxsum, B.maxsum, A.rightsum+B.leftsum});
        ret.totalsum=A.totalsum+B.totalsum;
        //cout << "leftsum : " << ret.leftsum << " " << " rightsum : " << ret.rightsum << " " << " maxsum : " << ret.maxsum << " totalsum : " << ret.totalsum << "\n";
        return ret;
    }
};

struct st{
    int row, col, val;
};

bool comp(st A, st B){
    return A.row<B.row;
}

PST seg;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int K;
    cin >> K;

    vector<st> V(K+1);
    V[0]={0, 0, 0};
    for(int i=1; i<=K; i++){
        int r, c, v;
        cin >> r >> c >> v;
        V[i]={r, c, v};
    }

    sort(all(V), comp);

    for(int i=1; i<=K; i++){
        seg.addNode(V[i].col, V[i].val);
    }

    int Q;
    cin >> Q;
    vector<int> ans;
    while(Q--){
        int H, X, Y;
        cin >> H >> X >> Y;
        if(ans.size()>=3) H^=ans[ans.size()-3];
        if(ans.size()>=2) X^=ans[ans.size()-2];
        if(ans.size()>=1) Y^=ans[ans.size()-1];

        //cout << "H : " << H << " X : " << X << " Y : " << Y << "\n";

        int left=0;
        int right=K;
        int treeindex=0;
        while(left<=right){
            int mid=(left+right)>>1;
            if(V[mid].row<=H){
                treeindex=max(treeindex, mid);
                left=mid+1;
            }
            else right=mid-1;
        }
        //cout << "treeindex : " << treeindex << "\n";
        ans.push_back(seg.sum(treeindex, X, Y+1).maxsum);
    }

    for(auto i : ans) cout << i << "\n";

    return 0;
}