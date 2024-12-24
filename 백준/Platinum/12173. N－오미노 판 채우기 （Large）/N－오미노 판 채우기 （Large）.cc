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
const ll mod = 10007;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
당연한 얘기지만 나누어떨어져야 하고
X가 7 이상이면 항상 가능

*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int TC;
    cin >> TC;
    int t=0;
    while(TC--){
        int X, R, C;
        cin >> X >> R >> C;
        if(R<C) swap(R, C);
        t++;
        cout << "Case #" << t << ": ";
        if(R*C%X||X>=7||X>=max(R, C)+1||X>=(min(R, C)+1)*2-1) cout << "RICHARD\n";
        else if(X==4&&C<=2) cout << "RICHARD\n";
        else if(X==5&&C==3&&R==5) cout << "RICHARD\n";
        else if(X==6&&C<=3) cout << "RICHARD\n";
        else cout << "GABRIEL\n";
    }

    return 0;
}
