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
DP[i]=첫번째 재료의 가치가 i일 때 두번째 재료의 가능한 최대 가치

두 차원 모두 양수인 거는 당연히 그대로 합치고
그렇지 않을 경우 취할 차원을 선택

나머지는 취할 차원만 취하거나 아니면 둘다 취해야 함
*/

struct Line{
    ll a, b;
    ll get(ll x){
        return a*x+b;
    }
};
struct Node{
    Node *l, *r;
    ll s, e;
    Line line;
    Node(){ 
        l=r=NULL;
        s=-1e10;
        e=1e10;
        line={0, LNF};
    }
    Node(ll a, ll b){
        l=r=NULL;
        s=a;
        e=b;
        line={0, LNF};
    }
};

Node* SegmentTree[400005];

void update(Node* node, Line v){
    ll s=node->s, e=node->e, m=(s+e)>>1;
    //cout << "s : " << s << " e : " << e << " m : " << m << "\n";
    Line low=node->line, high=v;
    if(low.get(s)>high.get(s)) swap(low, high);
    //cout << "high : " << high.a << " " << high.b << " low : " << low.a << " " << low.b << "\n";
    //cout << "get s : " << low.get(s) << " " << high.get(s) << "\n";
    if(low.get(e)<=high.get(e)){
        node->line=low;
    }
    else if(low.get(m)<high.get(m)){
        node->line=low;
        if(!node->r) node->r=new Node(m+1, e);
        update(node->r, high);
    }
    else{
        node->line=high;
        if(!node->l) node->l=new Node(s, m);
        update(node->l, low);
    }
    return;
}

ll query(Node* node, ll x){
    if(!node) return LNF;
    ll s=node->s, e=node->e, m=(s+e)>>1;
    //cout << "node line : " << node->line.a << " " << node->line.b << "\n";
    if(x<=m) return min(node->line.get(x), query(node->l, x));
    else return min(node->line.get(x), query(node->r, x));
}

void update_seg(int node, int start, int end, int index, int a, int b){
    if(index<start||end<index) return;
    //cout << "start : " << start << " end : " << end << endl;
    update(SegmentTree[node], {a, b});
    if(start!=end){
        int mid=(start+end)>>1;
        update_seg(node*2, start, mid, index, a, b);
        update_seg(node*2+1, mid+1, end, index, a, b);
    }
    return;
}

int sum_seg(int node, int start, int end, int left, int right, int x){
    if(right<start||end<left) return LNF;
    if(left<=start&&end<=right){
        //cout << "node : " << node << " start : " << start << " end : " << end << "\n";
        //cout << query(SegmentTree[node], x) << "\n";
        return query(SegmentTree[node], x);
    }
    else{
        int mid=(start+end)>>1;
        return min(sum_seg(node*2, start, mid, left, right, x), sum_seg(node*2+1, mid+1, end, left, right, x));
    }
}

void init_seg(int node, int start, int end){
    SegmentTree[node]=new Node;
    if(start!=end){
        int mid=(start+end)>>1;
        init_seg(node*2, start, mid);
        init_seg(node*2+1, mid+1, end);
    }
}

int wprefix[100005];
int dprefix[100005];
int ans[100005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, D;
    cin >> N >> D;

    init_seg(1, 0, N);

    for(int i=1; i<=N; i++){
        cin >> dprefix[i] >> wprefix[i];
        wprefix[i]+=wprefix[i-1];
        dprefix[i]+=dprefix[i-1];
    }

    int cur=0;
    update_seg(1, 0, N, 0, 0, 0);
    for(int i=1; i<=N; i++){
        //cout << "i : " << i << "\n";
        while(dprefix[i]-dprefix[cur]>D) cur++;
        //cout << "cur : " << cur << "\n";
        //cout << "prefix : " << wprefix[i] << "\n";
        int a=sum_seg(1, 0, N, cur, N, wprefix[i]);
        //cout << "a : " << a << "\n";
        ans[i]=a+wprefix[i]*wprefix[i];
        //cout << "ans : " << ans[i] << "\n";
        //cout << "a : " << -2*wprefix[i] << " b : " << ans[i]+wprefix[i]*wprefix[i] << "\n";
        update_seg(1, 0, N, i, -2*wprefix[i], ans[i]+wprefix[i]*wprefix[i]);
    }

    cout << ans[N];

    return 0;
}