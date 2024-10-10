#include <ext/rope>
#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
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
*/

pair<int,pair<int,int>> xGCD(int a, int b) {    // it returns {g, {x,y}}, ax+by=g
    if(b == 0) return {a,{1,0}};
    pair<int,pair<int,int>> ret = xGCD(b, a%b);
    int g, x, y;
    g = ret.first;
    tie(x,y) = ret.second;
    return {g,{y,x-(a/b)*y}};   
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, A;
    cin >> N >> A;
    cout << (N-A)%N << " ";
    if(__gcd(N, A)!=1) cout << -1;
    else cout << (xGCD(N, A).second.second+N)%N;

    return 0;
}