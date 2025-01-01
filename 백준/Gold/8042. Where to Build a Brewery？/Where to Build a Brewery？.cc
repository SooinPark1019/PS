#include <ext/rope>
#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
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
DP[i][k]=j의 인덱스
이때 최대한 많은 인덱스를 가는 것이 이득인가?

끝까지 남은 거리가 K 차이 이하인 애들만 검사
*/
int pos[10005];
int vis[10005];
int need[10005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    int totallength=0;
    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        need[i]=a;
        pos[i+1]=pos[i]+b;
        totallength+=b;
    }
    int ans=1e18;
    for(int i=0; i<N; i++){
        int temp=0;
        for(int j=0; j<N; j++){
            int a=abs(pos[i]-pos[j]);
            a=min(a, totallength-a);
            temp+=a*need[j];
        }
        ans=min(ans, temp);
    }
    cout << ans;
    return 0;
}
