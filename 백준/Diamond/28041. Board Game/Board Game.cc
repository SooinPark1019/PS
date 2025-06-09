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
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
*/

struct Line{
    int a, b;
    int get(int x){
        return a*x+b;
    }
};
struct Node{
    Node *l, *r;
    ll s, e;
    Line line;
    Node(){
        l=r=NULL;
        s=-1e9;
        e=1e9;
        line={0, -LNF};
    }
    Node(ll a, ll b){
        l=r=NULL;
        s=a;
        e=b;
        line={0, -LNF};
    }
};
void update(Node* node, Line v){
    //cout << v.a << " " << v.b << " " << node->s << " " << node->e << endl;
    ll s=node->s, e=node->e, m=(s+e)>>1;
    //cout << "s : " << s << " e : " << e << " m : " << m << endl;
    Line low=node->line, high=v;
    if(low.get(s)>high.get(s)) swap(low, high);
    if(low.get(e)<=high.get(e)){
        node->line=high;
    }
    else if(low.get(m)<high.get(m)){
        node->line=high;
        if(!node->r) node->r=new Node(m+1, e);
        update(node->r, low);
    }
    else{
        node->line=low;
        if(!node->l) node->l=new Node(s, m);
        update(node->l, high);
    }
    return;
}
ll query(Node* node, ll x){
    if(!node) return -LNF;
    ll s=node->s, e=node->e, m=(s+e)>>1;
    if(x<=m) return max(node->line.get(x), query(node->l, x));
    else return max(node->line.get(x), query(node->r, x));
}
vector<int> balls[100005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pii> V;
    for(int i=0; i<N; i++){
        int x, y;
        cin >> x >> y;
        V.push_back({x, y});
    }

    int Q;
    cin >> Q;
    vector<pii> player;

    for(int i=0; i<Q; i++){
        int a, b;
        cin >> a >> b;
        player.push_back({a, b});
    }

    vector<int> left(N, 0);
    vector<int> right(N, Q-1);
    vector<int> ans(N, Q);

    while(1){
        int flag=0;
        vector<vector<int>> G(Q);
        for(int i=0; i<N; i++){
            if(left[i]<=right[i]){
                //cout << "i : " << i << " m : " << ((left[i]+right[i])>>1) << endl;
                flag=1;
                G[(left[i]+right[i])>>1].push_back(i);
            }
        }
        if(flag==0) break;
        Node* root = new Node();
        for(int i=0; i<Q; i++){
            //cout << "i : " << i << endl;
            update(root, {player[i].first, player[i].second});
            for(auto j : G[i]){
                //cout << query(root, V[j].first) << endl;
                if(query(root, V[j].first)<=V[j].second){
                    left[j]=i+1;
                }
                else{
                    ans[j]=min(ans[j], i);
                    right[j]=i-1;
                }
            }
        }
    }

    for(int i=0; i<N; i++){
        balls[ans[i]].push_back(i);
    }

    for(int i=0; i<Q; i++){
        cout << balls[i].size() << " ";
        for(auto j : balls[i]) cout << j+1 << " ";
        cout << "\n";
    }

    return 0;
}
