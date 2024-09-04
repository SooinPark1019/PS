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

vector<pii> graph[1005][1005];
ll DP[1005][1005][2][8];
ll indegree[1005][1005];
ll arr[1005][1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        ll temp=abs(a)+abs(b)+abs(c);
        if(temp%2==0) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}