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
각 서브그리드마다 최대 하나의 constraint만 포함 가능

왼쪽위의 서브그리드부터 생각한다고 하자

*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int TC;
    cin >> TC;
    int t=0;
    while(TC--){
        t++;
        cout << "Case #" << t << ": ";
        int G;
        cin >> G;
        int ans=0;
        int cur=1;
        int nxt=2;
        while(cur<=G){
            if((G-cur)%(nxt-1)==0) ans++;
            cur+=nxt;
            nxt++;
        }
        cout << ans << "\n";
    }
    return 0;
}
