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

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int Q;
    cin >> Q;
    ll cur=0;
    int flag=0;
    while(Q--){
        int type;
        cin >> type;
        if(type==1){
            int a;
            cin >> a;
            cur+=a;
        }
        else{
            int a;
            cin >> a;
            if(cur<a){
                flag=1;
                break;
            }
            cur-=a;
        }
    }
    if(flag==1) cout << "Adios";
    else cout << "See you next month";
    return 0;
}