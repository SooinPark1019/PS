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
DP[i]=첫번째 재료의 가치가 i일 때 두번째 재료의 가능한 최대 가치

두 차원 모두 양수인 거는 당연히 그대로 합치고
그렇지 않을 경우 취할 차원을 선택

나머지는 취할 차원만 취하거나 아니면 둘다 취해야 함
*/
pii pos[200005];
vector<int> graph[200005][2];
vector<pii> X[200005];
vector<pii> Y[200005];
int DP[200005][2];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N, K;
    cin >> M >> N >> K;

    for(int i=1; i<=K; i++){
        int a, b;
        cin >> a >> b;
        pos[i]={a, b};
        X[a].push_back({b, i});
        Y[b].push_back({a, i});
    }
    int S=K+1, E=K+2;

    pos[S]={1, 1};
    X[1].push_back({1, S});
    Y[1].push_back({1, S});
    pos[E]={M, N};
    X[M].push_back({N, E});
    Y[N].push_back({M, E});

    for(int i=1; i<=M; i++){
        sort(all(X[i]));
        for(int j=0; j<(int)X[i].size()-1; j++){
            graph[X[i][j].second][0].push_back(X[i][j+1].second);
            graph[X[i][j+1].second][0].push_back(X[i][j].second);
        }
    }

    for(int i=1; i<=N; i++){
        sort(all(Y[i]));
        for(int j=0; j<(int)Y[i].size()-1; j++){
            graph[Y[i][j].second][1].push_back(Y[i][j+1].second);
            graph[Y[i][j+1].second][1].push_back(Y[i][j].second);
        }
    }

    for(int i=0; i<=E; i++){
        for(int j=0; j<2; j++){
            DP[i][j]=1e18;
        }
    }

    DP[S][0]=0;
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> PQ;
    PQ.push({0, S, 0});

    while(!PQ.empty()){
        int cur_dis=PQ.top()[0];
        int cur_node=PQ.top()[1];
        int cur_status=PQ.top()[2];
        //cout << cur_dis << " " << cur_node << " " << cur_status << endl;
        PQ.pop();
        if(cur_dis!=DP[cur_node][cur_status]) continue;
        for(auto i : graph[cur_node][cur_status]){
            int nxt_dis=abs(pos[cur_node].first-pos[i].first)+abs(pos[cur_node].second-pos[i].second);
            if(nxt_dis+cur_dis<DP[i][cur_status]){
                DP[i][cur_status]=nxt_dis+cur_dis;
                PQ.push({DP[i][cur_status], i, cur_status});
            }
        }
        if(cur_node==S||cur_node==E) continue;
        cur_status^=1;
        for(auto i : graph[cur_node][cur_status]){
            int nxt_dis=abs(pos[cur_node].first-pos[i].first)+abs(pos[cur_node].second-pos[i].second)+1;
            if(nxt_dis+cur_dis<DP[i][cur_status]){
                DP[i][cur_status]=nxt_dis+cur_dis;
                PQ.push({DP[i][cur_status], i, cur_status});
            }
        }
    }
    int ans=min(DP[E][0], DP[E][1]);
    if(ans==1e18) cout << -1;
    else cout << ans;

    return 0;
}
