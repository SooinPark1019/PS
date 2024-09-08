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

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;

vector<int> graph[100005];
ll cost[100005], lvl[100005];
ll ans=0, N, M;
ll val[100005];

priority_queue<ll> dfs(int cur_node){
    //cout << cur_node << endl;
    priority_queue<ll> PQ;
    ll total=0;
    PQ.push(cost[cur_node]);
    total+=cost[cur_node];
    //cout << "cur : " << cur_node << " total : " << total << "\n";
    for(auto i : graph[cur_node]){
        //cout << "i : " << i << "\n";
        priority_queue<ll> temp=dfs(i);
        total+=val[i];
        if((ll)PQ.size()<(ll)temp.size()) swap(PQ, temp);
        while(!temp.empty()){
            PQ.push(temp.top());
            //cout << "cur : " << cur_node << " temp.top : " << temp.top() << " total : " << total << "\n";
            temp.pop();
        }
    }
    //if(cur_node==1) cout << total << " " << PQ.size() << "\n";
    while(!PQ.empty()&&total>M){
        //cout << cur_node << " " << PQ.top() << " " << total << "\n";
        total-=PQ.top();
        PQ.pop();
    }
    ans=max(ans, lvl[cur_node]*(ll)PQ.size());
    val[cur_node]=total;
    return PQ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int root;

    for(int i=1; i<=N; i++){
        int a;
        cin >> a >> cost[i] >> lvl[i];
        if(a==0) root=i;
        graph[a].push_back(i);
    }

    dfs(root);

    cout << ans;

    return 0;
}