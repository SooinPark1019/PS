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
const ll mod = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
바꾸는 쿼리가 없다고 생각을 해보자

어떤 l, r이 주어졌을 때
최댓값을 어떻게 찾을까?
하나의 연속합형태로 나타난다면
양 끝의 b와 내부에서 붙어있는 b 두개

금광+최댓값 세그로 할 수 있는데
문제는 하나의 연속합 형태로 나타나지 않는 경우
*/
vector<pii> graph[300005];
int DP[300005];
int ans[300005];

int DFS(int cur_node, int par){
    int& ret=DP[cur_node];
    for(auto i : graph[cur_node]){
        if(i.first==par) continue;
        int a=DFS(i.first, cur_node);
        if(a==0) ret++;
    }
    //cout << cur_node << " " << DP[cur_node] << "\n";
    return ret;
}

void reroot(int cur_node, int par){
    ans[cur_node]=DP[cur_node];
    for(auto i : graph[cur_node]){
        if(i.first==par) continue;
        if(DP[i.first]==0) DP[cur_node]--;
        if(DP[cur_node]==0) DP[i.first]++;
        reroot(i.first, cur_node);
        if(DP[cur_node]==0) DP[i.first]--;
        if(DP[i.first]==0) DP[cur_node]++;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for(int i=0; i<N-1; i++){
        int x, y, a;
        cin >> x >> y >> a;
        graph[x].push_back({y, a});
        graph[y].push_back({x, a});
    }
    DFS(1, -1);
    reroot(1, -1);
    for(int i=1; i<=N; i++){
        //cout << ans[i] << "\n";
        if(ans[i]==0) cout << "Portuga\n";
        else cout << "Zeze\n";
    }
    return 0;
}
