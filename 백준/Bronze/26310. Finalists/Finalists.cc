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
const double EPS = 1e-7;
const ll LNF = 1e18;
const ll mod = 998244353;
const int MAXN = (1<<18)+5;
const int D = 20;

/*
sum(V)/sum(W)>=K
sum(V)>=K*sum(W)
sum(V)>=sum(K*W)
sum(V)-sum(K*W)>=0
sum(V-k*W)>=0
*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<pair<int, string>> V;
    for(int i=0; i<N; i++){
        string S;
        int a, b, c, d, e;
        cin >> S >> a >> b >> c >> d >> e;

        int temp=0;
        temp+=a*6;
        temp+=b*14;
        temp+=c*24;
        temp+=d*56;
        temp+=e*30;
        V.push_back({temp, S});
    }
    sort(all(V), greater<>());
    int index;
    for(int i=0; i<N; i++){
        if(V[i].second=="Taiwan"){
            index=i+1;
            break;
        }
    }
    int ans=N/6;
    if(index<=N%6) ans++;
    cout << ans;
    return 0;
}