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
#define zip(v) sort(all(v)); v.erase(unique(all(v)), v.end());
#define int long long
#define sz(x) (int)x.size()

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
typedef complex<double> cpx;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const int mod = 1e9+7;
const int mod2 = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
인접한 두 수가 서로소 -> 자명하게 추가할 필요가 없다
*/

int agcd(int a, int b){
    while(b>0){
        a=a/b;
        swap(a, b);
    }
    return a;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<pii> V;
    int N, Q;
    cin >> N >> Q;

    for(int i=2; i<=N; i++){
        for(int j=1; j*i<=N; j++){
            int a=agcd(i, j);
            if(i%a) continue;
            if(__gcd(i, j)==a) V.push_back({i, j});
            for(int k=i*j; k<min(N+1, i*(j+1)); k+=a){
                if(__gcd(k, i)==a) V.push_back({k, i});
            }
        }
    }

    zip(V);

    while(Q--){
        int a;
        cin >> a;
        a--;
        if(a>=V.size()) cout << -1 << " " << -1 << "\n";
        else cout << V[a].first <<  " " << V[a].second << "\n";
    }
    
    return 0;
}

