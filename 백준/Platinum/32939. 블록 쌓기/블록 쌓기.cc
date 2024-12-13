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
    vector<int> V(N+2, 0);
    for(int i=1; i<=N; i++){
        cin >> V[i];
    }
    deque<pii> D;
    int ans=0;
    int time=0;
    for(int i=0; i<=N; i++){
        if(V[i]<V[i+1]){
            time+=V[i+1]-V[i];
            D.push_back({i+1, V[i+1]-V[i]});
        }
        else if(V[i]>V[i+1]){
            int a=V[i]-V[i+1];
            //cout << "a : " << a << "\n";
            while(a>0){
                if(a<D.front().second){
                    //cout << i << " " << D.front().first << "\n";
                    ans+=(i-D.front().first+1)*(i-D.front().first+1)*a;
                    D.front().second-=a;
                    a=0;
                }
                else{
                    ans+=(i-D.front().first+1)*(i-D.front().first+1)*D.front().second;
                    a-=D.front().second;
                    D.pop_front();
                }
            }
            //cout << ans << "\n";
        }
    }
    cout << time << " " << ans;
    return 0;
}
