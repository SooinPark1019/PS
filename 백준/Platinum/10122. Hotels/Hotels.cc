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

vector<int> graph[5005];
map<pair<int, int>, int> M;
int depthcnt[5005];

void cnt(int cur_node, int par, int cur_depth, int a){
    M[{a, cur_depth}]++;
    depthcnt[cur_depth]++;
    for(auto i : graph[cur_node]){
        if(i==par) continue;
        cnt(i, cur_node, cur_depth+1, a);
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
    int ans=0;
    for(int i=1; i<=N; i++){
        map<pii, int> temp;
        swap(temp, M);
        memset(depthcnt, 0, sizeof(depthcnt));
        for(int j=0; j<graph[i].size(); j++){
            cnt(graph[i][j], i, 1, j);
        }
        for(int j=1; j<N; j++){
            if(depthcnt[j]<3) break;
            vector<int> V;
            for(int k=0; k<graph[i].size(); k++){
                if(M[{k, j}]!=0) V.push_back(M[{k, j}]);
            }
            if(V.size()<3) continue;
            vector<vector<int>> DP(5, vector<int>(V.size()+1));
            for(int i=0; i<V.size(); i++){
                DP[1][i]=V[i];
                if(i!=0) DP[1][i]+=DP[1][i-1];
            }
            for(int i=2; i<=3; i++){
                for(int j=1; j<V.size(); j++){
                    DP[i][j]=DP[i][j-1]+DP[i-1][j-1]*V[j];
                }
            }
            ans+=DP[3][V.size()-1];
        }
    }
    cout << ans;
    return 0;
}