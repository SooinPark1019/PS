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
const ll mod = 987654321;
const int MAXN = (1<<18)+5;
const int D = 20;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);



    int TC;
    cin >> TC;
    while(TC--){
        int N, K;
        cin >> N >> K;
        double ans=0;
        double cur_prob=1;
        for(int i=1; i<=N/K; i++){
            cur_prob/=i;
            cur_prob/=K;
            for(int j=1; j<=K; j++){
                cur_prob/=(double)(N-1);
                cur_prob*=(double)(N-i*K+j);
            }
            if(i%2==0) ans-=cur_prob;
            else ans+=cur_prob;
        }
        cout << fixed;
        cout.precision(12);
        cout << ans << "\n";
    }
    
    return 0;
}