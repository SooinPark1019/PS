#include <ext/rope>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>//이걸 코드의 윗부분에 추가

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

void m_erase(ordered_set &OS, int val){
    int index = OS.order_of_key(val);
    ordered_set::iterator it = OS.find_by_order(index);
    if(*it == val) OS.erase(it);
}//다른 건 통상적인 PBDS처럼 사용하면 되지만 erase는 반드시!!! 이 함수를 통해서만 해야 함
//m_erase(OS, 지울 원소)처럼 사용하면 된다. 꼭 주의하자.

vector<int> disfromsource(200005, 1e18);
vector<int> disfromsink(200005, 1e18);

vector<pii> graph[200005];

void fill_dis(int S, int E, vector<int>& dis){
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    PQ.push({0, S});
    dis[S]=0;
    while(!PQ.empty()){
        int cur_node=PQ.top().second;
        int cur_cost=PQ.top().first;
        PQ.pop();
        if(dis[cur_node]!=cur_cost) continue;
        for(auto p : graph[cur_node]){
            int nxt_cost=p.second;
            int nxt_node=p.first;
            if(dis[nxt_node]>nxt_cost+cur_cost){
                dis[nxt_node]=nxt_cost+cur_cost;
                PQ.push({dis[nxt_node], nxt_node});
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    int S, T, L, K;
    cin >> S >> T >> L >> K;

    for(int i=0; i<M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    fill_dis(S, T, disfromsource);
    fill_dis(T, S, disfromsink);

    if(disfromsink[S]<=K){
        cout << N*(N-1)/2;
        return 0;
    }

    ordered_set OS;

    for(int i=1; i<=N; i++){
        OS.insert(disfromsink[i]);
    }
    int ans=0;
    for(int i=1; i<=N; i++){
        m_erase(OS, disfromsink[i]);
        ans+=OS.order_of_key(K-L-disfromsource[i]+1);
    }

    OS.clear();

    for(int i=1; i<=N; i++){
        OS.insert(disfromsource[i]);
    }
    for(int i=1; i<=N; i++){
        m_erase(OS, disfromsource[i]);
        ans+=OS.order_of_key(K-L-disfromsink[i]+1);
    }

    cout << ans;

    return 0;
}
