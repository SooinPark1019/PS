#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

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
const ll MAX = 1e5+5;

signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--){
        int N, M;
        cin >> N >> M;
        int maxred=0;
        int maxwhite=0;
        for(int i=0; i<M; i++){
            int a, b;
            cin >> a >> b;
            maxred=max(maxred, a);
            maxwhite=max(maxwhite, b);
        }
        if(maxred+maxwhite>N) cout << "IMPOSSIBLE\n";
        else{
            for(int i=0; i<maxred; i++) cout << "R";
            for(int i=0; i<N-maxred; i++) cout << "W";
            cout << "\n";
        }
    }

    return 0;
}
