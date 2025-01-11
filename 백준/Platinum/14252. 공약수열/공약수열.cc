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
인접한 두 수가 서로소 -> 자명하게 추가할 필요가 없다


*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    vector<int> V;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        V.push_back(a);
    }

    sort(all(V));

    int ans=0;

    for(int i=0; i<N-1; i++){
        if(__gcd(V[i], V[i+1])==1) continue;
        int flag=0;
        for(int j=V[i]+1; j<V[i+1]-1; j++){
            if(__gcd(V[i], j)==1&&__gcd(V[i+1], j)==1){
                flag=1;
                break;
            }
        }
        if(flag==1){
            ans++;
            continue;
        }
        vector<int> DP(V[i+1]-V[i]+1, 0);
        for(int j=1; j<=V[i+1]-V[i]; j++){
            int a=1e18;
            for(int k=0; k<j; k++){
                if(__gcd(V[i]+j, V[i]+k)==1){
                    //cout << V[i]+j << " " << V[i]+k << " " << DP[k]+1 << "\n";
                    a=min(a, DP[k]+1);
                }
            }
            DP[j]=a;
        }
        ans+=DP[V[i+1]-V[i]]-1;
    }

    cout << ans;
    
    return 0;
}
