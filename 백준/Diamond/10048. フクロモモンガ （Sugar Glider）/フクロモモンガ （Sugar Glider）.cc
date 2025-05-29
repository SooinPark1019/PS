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
int dis[100005];
int H[100005];
vector<pii> graph[100005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, X;
    cin >> N >> M >> X;

    for(int i=1; i<=N; i++) cin >> H[i];

    for(int i=0; i<M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    for(int i=1; i<=N; i++){
        dis[i]=1e18;
    }
    dis[1]=0;
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    PQ.push({0, 1});
    int flag=0;
    while(!PQ.empty()){
        int cur_dis=PQ.top().first;
        int cur_node=PQ.top().second;
        PQ.pop();
        if(dis[cur_node]!=cur_dis) continue;
        int cur_height=max(0ll, X-cur_dis);
        for(auto p : graph[cur_node]){
            int nxt_node=p.first;
            int nxt_dis=p.second;
            if(H[cur_node]<nxt_dis) continue;
            else if(H[nxt_node]<cur_height-nxt_dis){
                nxt_dis+=cur_height-nxt_dis-H[nxt_node];
            }
            else if(cur_height<nxt_dis){
                nxt_dis+=nxt_dis-cur_height;
            }
            if(dis[nxt_node]>cur_dis+nxt_dis){
                dis[nxt_node]=cur_dis+nxt_dis;
                PQ.push({dis[nxt_node], nxt_node});
            }
        }
    }
    int ans=dis[N];
    if(ans>=1e17){
        cout << -1;
    }
    else{
        int cur_height=max(0ll, X-ans);
        ans+=H[N]-cur_height;
        cout << ans;
    }
    return 0;
}
