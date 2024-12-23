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
int DP[1000005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    for(int i=1; i<=N; i++){
        DP[i]=1e18;
    }
    DP[1]=0;
    int p=0;
    for(int i=1; i<=N; i++){
        int a;
        cin >> a;
        if(a==1){
            int b;
            cin >> b;
            p++;
            DP[b]=-p;
        }
        else{
            int a, b;
            cin >> a >> b;
            DP[b]=min(DP[b], DP[a]);
            DP[a]++;
        }
    }

    for(int i=1; i<=N; i++){
        if(DP[i]==1e18) cout << -1 << " ";
        else cout << DP[i]+p << " ";
    }
    
    return 0;
}
