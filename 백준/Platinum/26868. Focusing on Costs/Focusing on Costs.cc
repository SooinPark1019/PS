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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a, b;
    cin >> a >> b;

    int c=__gcd(a, b);
    a/=c;
    b/=c;

    a*=a;
    b*=b;

    int flipped=0;

    if(a>b){
        flipped=1;
        swap(a, b);
    }

    vector<string> ans;

    while(a!=1||b!=1){
        if(a*2<=b){
            ans.push_back("sin");
        }
        else{
            ans.push_back("cos");
        }
        ans.push_back("atan");
        int c=b-a;
        int d=a;
        b=max(c, d);
        a=min(c, d);
    }

    ans.push_back("cos");

    reverse(all(ans));

    if(flipped) cout << ans.size()+4 << "\n";
    else cout << ans.size() << "\n";

    for(auto s : ans) cout << s << " ";
    if(flipped){
        cout << "atan sin acos tan";
    }
    
    return 0;
}

