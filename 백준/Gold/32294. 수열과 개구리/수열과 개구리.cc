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
const ll mod = 998244353;
const int MAXN = 2e5+5;
const int D = 20;

/*
DP인 거 같은데
각 위치를 정점으로 보고
a에서 b로 갈 수 있다면 반대방향으로 간선을 그어준다
초기에 바깥으로 나갈 수 있는 애들을 보고 걔들에서부터 시작을 해서
위상정렬 하듯이 DP를 하면 될 것 같다
일단 바깥으로 나갈 수 있는 애들한테 다 bx만큼의 초기값을 부여를 하자
다익을 돌려도 될 것 같다
*/

vector<pii> graph[200005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A;
    vector<int> B;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        A.push_back(a);
    }
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        B.push_back(a);
    }
    vector<int> dis(N+1, 1e18);
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    for(int i=0; i<N; i++){
        int a=i-A[i];
        int b=i+A[i];
        if(a>=0&&a<N){
            graph[a].push_back({i, B[i]});
        }
        if(b>=0&&b<N){
            graph[b].push_back({i, B[i]});
        }
        if(a<0||a>=N||b<0||b>=N){
            dis[i]=B[i];
            PQ.push({dis[i], i});
        }
    }
    while(!PQ.empty()){
        int curtime=PQ.top().first;
        int curnode=PQ.top().second;
        PQ.pop();
        if(dis[curnode]!=curtime) continue;
        for(auto p : graph[curnode]){
            int nxtnode=p.first;
            int nxttime=p.second;
            if(dis[nxtnode]>nxttime+curtime){
                dis[nxtnode]=nxttime+curtime;
                PQ.push({dis[nxtnode], nxtnode});
            }
        }
    }

    for(int i=0; i<N; i++) cout << dis[i] << " ";

    return 0;
}