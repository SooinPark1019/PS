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
const ll mod = 1e9+9;
const int MAXN = 1e9+7;
const int D = 20;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    priority_queue<int, vector<int>, greater<int>> PQ;
    queue<int> Q;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        Q.push(a);
    }
    while(!Q.empty()){
        while(!Q.empty()&&PQ.size()<=K){
            PQ.push(Q.front());
            Q.pop();
        }
        cout << PQ.top() << " ";
        PQ.pop();
    }
    while(!PQ.empty()){
        cout << PQ.top() << " ";
        PQ.pop();
    }
    return 0;
}