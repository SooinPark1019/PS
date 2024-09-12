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
const int debug = 1;

vector<int> graph[500005];
int DP[500005];
int ans[500005];
multiset<int> MS[500005];

int sol(int cur_node, int par){
    int& val=DP[cur_node];
    if(val!=-1) return val;
    val=0;
    vector<int> temp;
    for(auto i : graph[cur_node]){
        if(i==par) continue;
        temp.push_back(sol(i, cur_node));
        MS[cur_node].insert(temp.back());
    }
    if(temp.size()==0) return val;
    sort(all(temp));
    //cout << "curnode : " << cur_node << "\n";
    //for(auto i : temp) cout << i << " ";
    //cout << "\n";
    val=temp.back();
    temp.pop_back();
    if(temp.size()==0) return val;
    val=max(val, temp.back()+1);
    //cout << "cur node : " << cur_node << " val : " << val << "\n";
    return val;
}

void val(int cur_node){
    if(MS[cur_node].size()==0){
        DP[cur_node]=0;
    }
    else if(MS[cur_node].size()==1){
        DP[cur_node]=*prev(MS[cur_node].end());
    }
    else{
        DP[cur_node]=max(*prev(MS[cur_node].end()), *prev(prev(MS[cur_node].end()))+1);
    }
}

void dfs(int cur_node, int par){
    ans[cur_node]=DP[cur_node];
    for(auto i : graph[cur_node]){
        if(i==par) continue;
        MS[cur_node].erase(MS[cur_node].find(DP[i]));
        val(cur_node);
        MS[i].insert(DP[cur_node]);
        val(i);
        dfs(i, cur_node);
        MS[i].erase(MS[i].find(DP[cur_node]));
        val(i);
        MS[cur_node].insert(DP[i]);
        val(cur_node);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(DP, -1, sizeof(DP));
    sol(1, -1);
    dfs(1, -1);
    int flag=0;
    for(int i=1; i<=N; i++){
        //cout << "i : " << i << " " << "ans : " << ans[i] << "\n";
        if(ans[i]<3){
            flag=1;
            break;
        }
    }
    if(flag==0) cout << "NO\n";
    else cout << "YES\n";
    return 0;
}