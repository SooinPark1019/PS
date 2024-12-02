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
typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
*/
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<pii> V;
    int ans=N;
    int onestreak=0;
    i128 total=0;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        total+=a;
        if(a==1) onestreak++;
        else{
            V.push_back({onestreak, a});
            onestreak=0;
        }
    }
    V.push_back({onestreak, 0});

    for(int i=0; i<V.size(); i++){
        i128 product=V[i].second;
        i128 sum=V[i].second;
        for(int j=i+1; j<V.size()-1; j++){
            if(product*V[j].second>total) break;
            product*=V[j].second;
            sum+=V[j].first+V[j].second;
            int a=product-sum;
            int b=V[i].first;
            int c=V[j+1].first;
            //cout << a << "\n";
            if(a<0||b+c<a) continue;
            if(b>c) swap(b, c);
            if(a>=b){
                ans+=min(b+1, c-(a-b)+1);
            }
            else{
                ans+=a+1;
            }
        }
        //cout << ans << "\n";
    }
    cout << ans;
    return 0;
}
