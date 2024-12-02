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
int DP[2005][2005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, P, Q;
    cin >> N >> P >> Q;
    vector<int> V;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        V.push_back(a);
    }
    sort(all(V));
    if(P+Q>=N){
        cout << 1;
        return 0;
    }

    int left=1;
    int right=1e9;
    int ans=1e9;
    while(left<=right){
        int mid=(left+right)>>1;
        memset(DP, INF, sizeof(DP));
        DP[0][0]=0;
        for(int i=0; i<N; i++){
            int a=V[i]+mid-1;
            int b=V[i]+2*mid-1;
            int sh=upper_bound(all(V), a)-V.begin();
            int lo=upper_bound(all(V), b)-V.begin();
            for(int j=0; j<N; j++){
                if(DP[i][j]==INF) continue;
                DP[sh][j+1]=min(DP[sh][j+1], DP[i][j]);
                DP[lo][j]=min(DP[lo][j], DP[i][j]+1);
            }
        }
        int flag=0;
        for(int i=0; i<=P; i++){
            if(DP[N][i]<=Q){
                flag=1;
                break;
            }
        }
        if(flag==1){
            ans=min(ans, mid);
            right=mid-1;
        }
        else left=mid+1;
    }
    cout << ans;

    return 0;
}
