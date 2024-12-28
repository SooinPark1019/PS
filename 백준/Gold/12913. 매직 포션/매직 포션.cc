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
#define sz(x) (int)x.size()

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
typedef complex<double> cpx;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 1e9+123;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
각 단어마다 짝을 지어준 다음에
DP[i][j]=인덱스 i, 인덱스 j인 경우의 최소 비용
*/

vector<pii> graph[55];
int DP[55][55];

struct st{
    int cur_node, cur_time, left_potion;
};

struct comp{
    bool operator()(st A, st B){
        return A.cur_time>B.cur_time;
    }
};

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    for(int i=0; i<N; i++){
        string S;
        cin >> S;
        for(int j=0; j<S.length(); j++){
            graph[i].push_back({j, (S[j]-'0')*2});
        }
    }
    priority_queue<st, vector<st>, comp> PQ;
    vector<vector<int>> dis(N+1, vector<int>(K+1, 1e18));
    dis[0][K]=0;
    PQ.push({0, 0, K});
    while(!PQ.empty()){
        int cur_node=PQ.top().cur_node;
        int cur_time=PQ.top().cur_time;
        int left_potion=PQ.top().left_potion;
        PQ.pop();
        if(dis[cur_node][left_potion]!=cur_time) continue;
        for(auto i : graph[cur_node]){
            int nxt_node=i.first;
            int nxt_time=i.second;
            if(dis[nxt_node][left_potion]>cur_time+nxt_time){
                dis[nxt_node][left_potion]=cur_time+nxt_time;
                PQ.push({nxt_node, dis[nxt_node][left_potion], left_potion});
            }
            if(left_potion>0&&dis[nxt_node][left_potion-1]>cur_time+nxt_time/2){
                dis[nxt_node][left_potion-1]=cur_time+nxt_time/2;
                PQ.push({nxt_node, dis[nxt_node][left_potion-1], left_potion-1});
            }
        }
    }
    int ans=1e18;
    for(int i=0; i<=K; i++){
        ans=min(ans, dis[1][i]);
    }
    cout << (double)ans/2;
}
