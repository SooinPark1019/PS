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

/*
*/

int T[100005];
int V[100005];
int N, D;

int sol(int s, int e, int l, int r){
    if(s>e) return 0;
    int mid=(s+e)/2;
    int opt;
    int a=0;
    for(int i=max(mid, l); i<=min(r, mid+D); i++){
        if(a<V[mid]+(i-mid)*T[i]){
            a=V[mid]+(i-mid)*T[i];
            opt=i;
        }
    }
    //cout << mid << " " << opt << " " << a << "\n";
    a=max({a, sol(s, mid-1, l, opt), sol(mid+1, e, opt, r)});
    return a;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> D;
    for(int i=1; i<=N; i++){
        cin >> T[i];
    }
    for(int i=1; i<=N; i++){
        cin >> V[i];
    }

    cout << sol(1, N, 1, N);
    return 0;
}