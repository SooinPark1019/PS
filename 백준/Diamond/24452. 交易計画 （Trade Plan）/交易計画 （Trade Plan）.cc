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

int P1[400005], P2[400005], color[400005], ans[400005];
vector<pii> edges;
map<pii, vector<pii>> edgecluster;
map<pii, vector<array<int, 3>>> queries;

int find(int node, int p[400005]){
    //cout << "node : " << node << endl;
    return (p[node]==node) ? node : p[node]=find(p[node], p);
}
void merge(int node1, int node2, int p[400005]){
    int a=find(node1, p);
    int b=find(node2, p);
    p[a]=b;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    for(int i=1; i<=N; i++){
        P1[i]=i;
        P2[i]=i;
    }

    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }

    for(int i=1; i<=N; i++){
        cin >> color[i];
    }

    for(auto e : edges){
        int a=color[e.first];
        int b=color[e.second];
        if(a>b) swap(a, b);
        if(a==b){
            merge(e.first, e.second, P1);
        }
        else edgecluster[{a, b}].push_back(e);
    }

    int Q;
    cin >> Q;
    for(int i=0; i<Q; i++){
        int x, y;
        cin >> x >> y;
        int a=color[x];
        int b=color[y];
        if(a>b) swap(a, b);
        if(a==b){
            ans[i]=(find(x, P1)==find(y, P1))?1:0;
        }   
        else{
            queries[{a, b}].push_back({x, y, i});
        }
    }

    for(auto [colorp, query] : queries){
        //cout << colorp.first << " " << colorp.second << endl;
        for(auto e : edgecluster[colorp]){
            merge(find(e.first, P1), find(e.second, P1), P2);
        }
        for(auto q : query){
            //cout << q[0] << " " << q[1] << " " << q[2] << endl;
            //cout << "find : " << find(q[0], P1) << endl;
            int a=find(find(q[0], P1), P2);
            int b=find(find(q[1], P1), P2);
            ans[q[2]]=(a==b)?1:0;
            //cout << q[0] << " " << q[1] << " " << q[2] << endl;
        }
        for(auto e : edgecluster[colorp]){
            P2[find(e.first, P1)]=find(e.first, P1);
            P2[find(e.second, P1)]=find(e.second, P1);
        }
    }

    for(int i=0; i<Q; i++) cout << ans[i] << "\n";

    return 0;
}
