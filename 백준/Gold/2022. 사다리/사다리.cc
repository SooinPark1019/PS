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
    
    double a, b, c;
    cin >> a >> b >> c;

    double left=0;
    double right=min(a, b);
    double ans=0;
    while(left<=right){
        double mid=(left+right)/2;
        //cout << (double)1/sqrt((a-mid)*(a+mid))+(double)1/sqrt((b-mid)*(b+mid)) << " " << (double)1/c << "\n";
        if((double)1/sqrt((a-mid)*(a+mid))+(double)1/sqrt((b-mid)*(b+mid))>=(double)1/c){
            right=mid-(double)1/10000;
        }
        else{
            ans=max(ans, mid);
            left=mid+(double)1/10000;
        }
    }
    cout << fixed;
    cout.precision(12);
    cout << ans;
    return 0;
}
