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
const int MAXN = (1<<18)+5;
const int D = 20;

vector<pii> graph[100005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int H;
    cin >> H;
    int a, b, c;
    cin >> a >> b >> c;

    vector<int> dis(a, (ll)1e18+5);

    if(b>c) swap(b, c);
    if(a>b) swap(a, b);

    if(a==1){
        cout << H;
        return 0;
    }

    for(int i=0; i<a; i++){
        graph[i].push_back({(i+b)%a, b});
        graph[i].push_back({(i+c)%a, c});
    }
    dis[1]=1;
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    PQ.push({1, 1});
    while(!PQ.empty()){
        int cur_node=PQ.top().second;
        int cur_dis=PQ.top().first;
        //cout << "cur node : " << cur_node << " cur dis : " << cur_dis << "\n";
        PQ.pop();
        if(dis[cur_node]!=cur_dis) continue;
        for(auto i : graph[cur_node]){
            int nxt_node=i.first;
            int nxt_dis=i.second;
            //cout << "nxt node : " << nxt_node << " nxt_dis : " << nxt_dis << "\n";
            if(dis[nxt_node]>cur_dis+nxt_dis){
                dis[nxt_node]=cur_dis+nxt_dis;
                PQ.push({dis[nxt_node], nxt_node});
            }
        }
    }

    int ans=0;
    for(int i=0; i<a; i++){
        //cout << dis[i] << "\n";
        assert(dis[i]>0);
        if(H>=dis[i]) ans+=(H-dis[i])/a+1;
    }

    cout << ans;
    
    return 0;
}