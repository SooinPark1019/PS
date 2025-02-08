#include <ext/rope>
#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define debug1(x,y) cout << x << " :: " << y << " "
#define coutn cout << "\n"
#define debug2 puts("--@222%--")
#define debug3 puts("--@333%--")
using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 1e9+9;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;
    cin >> S;
    crope r;
    for(auto c : S){
        r.push_back(c);
    }
    int Q;
    cin >> Q;
    while(Q--){
        int a;
        cin >> a;
        if(a==1){
            int x, y;
            cin >> x >> y;
            crope r2=r.substr(x, y-x+1);
            //cout << r2 << "\n";
            r.erase(x, y-x+1);
            r.insert(0, r2);
            //cout << r << "\n";
        }
        else if(a==2){
            int x, y;
            cin >> x >> y;
            crope r2=r.substr(x, y-x+1);
            //cout << r2 << "\n";
            r.erase(x, y-x+1);
            r.insert(r.size(), r2);
            //cout << r << "\n";
        }
        else{
            int x;
            cin >> x;
            cout << r.substr(x, 1) << "\n";
        }
    }
    return 0;
}
