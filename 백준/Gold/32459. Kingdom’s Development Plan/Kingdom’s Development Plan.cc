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

vector<int> graph[100005];
int indegree[100005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> PQ;
    for(int i=1; i<=N; i++){
        if(indegree[i]==0){
            PQ.push(i);
        }
    }
    while(!PQ.empty()){
        int x=PQ.top();
        PQ.pop();
        ans.push_back(x);
        for(auto i : graph[x]){
            indegree[i]--;
            if(indegree[i]==0){
                PQ.push(i);
            }
        }
    }
    if(ans.size()==N){
        for(auto i : ans) cout << i << " ";
    }
    else cout << "IMPOSSIBLE";
    return 0;
}