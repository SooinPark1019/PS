#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

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
const ll MAX = 2e6+5;
const int D=25;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N, W;
    cin >> N >> W;
    if(W>5000){
        for(int i=0; i<N/2; i++){
            cout << W-i << " " << i << "\n";
        }
        for(int i=N/2; i<N; i++){
            cout << W << " " << i << "\n";
        }
    }
    else{
        for(int i=0; i<N/2; i++){
            cout << W+i << " " << i << "\n";
        }
        for(int i=N/2; i<N; i++){
            cout << W << " " << i << "\n";
        }
    }
    return 0;
}