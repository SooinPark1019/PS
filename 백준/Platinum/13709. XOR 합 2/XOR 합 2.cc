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

*/

int reduce(vector<int>& b, int x){
    for(int i=60; i>=0; i--){
        if(x&(1ll<<i)){
            x=x^b[i];
        }
    }
    return x;
}

bool add(vector<int>& b, int x){
    x=reduce(b, x);
    if(x!=0){
        for(int i=60; i>=0; i--){
            if(x&(1ll<<i)){
                b[i]=x;
                return true;
            }
        }
    }
    return false;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<int> V(61);

    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        add(V, a);
    }

    int ans=0;
    for(int i=60; i>=0; i--){
        if((ans&(1ll<<i))==0) ans=ans^V[i];
    }

    cout << ans;

    return 0;
}
