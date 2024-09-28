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
const int MAXN = 3e5+5;
const int D = 20;

vector<int> child[MAXN];
int val[MAXN];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for(int i=2; i<=N; i++){
        int a;
        cin >> a;
        child[a].push_back(i);
    }
    for(int i=1; i<=N; i++){
        cin >> val[i];
    }

    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    PQ.push({val[1], 1});
    while(!PQ.empty()){
        cout << PQ.top().first << "\n";
        int a=PQ.top().second;
        PQ.pop();
        for(auto j : child[a]){
            PQ.push({val[j], j});
        }
    }
    
    return 0;
}