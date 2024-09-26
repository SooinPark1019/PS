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
const ll mod = 1e9+7;
const int MAXN = 1e5+5;

vector<int> makebasis(vector<int> A){
    vector<int> temp;
    for(auto i : A){
        for(auto j : temp){
            i=min(i, i^j);
        }
        if(i!=0) temp.push_back(i);
    }
    return temp;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> V;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        V.push_back(a);
    }

    vector<int> A;
    for(int i=0; i<N-1; i++){
        A.push_back(V[i]^V[i+1]);
    }

    vector<int> basis=makebasis(A);

    int cur=0;
    for(auto i : basis){
        cur=max(cur, cur^i);
    }
    cout << cur;

    return 0;
}