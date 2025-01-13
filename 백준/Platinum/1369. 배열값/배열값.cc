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
const int mod = 1e9+7;
const int mod2 = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
인접한 두 수가 서로소 -> 자명하게 추가할 필요가 없다
*/

pii arr[1005][1005];
pii DP[1005][1005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int a;
            cin >> a;
            if(a==0){
                arr[i][j]={-1, -1};
                continue;
            }
            int two=0, five=0;
            while(a%2==0){
                two++;
                a/=2;
            }
            while(a%5==0){
                five++;
                a/=5;
            }
            arr[i][j]={two, five};
        }
    }

    for(int i=0; i<=N; i++){
        for(int j=0; j<=N; j++){
            DP[i][j]={1e18, 1e18};
        }
    }

    DP[0][0]=arr[0][0];

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j].first<0) continue;
            if(i<N-1){
                if(DP[i+1][j].first>DP[i][j].first+arr[i+1][j].first){
                    DP[i+1][j].first=DP[i][j].first+arr[i+1][j].first;
                    DP[i+1][j].second=DP[i][j].second+arr[i+1][j].second;
                }
            }
            if(j<N-1){
                if(DP[i][j+1].first>DP[i][j].first+arr[i][j+1].first){
                    DP[i][j+1].first=DP[i][j].first+arr[i][j+1].first;
                    DP[i][j+1].second=DP[i][j].second+arr[i][j+1].second;
                }
            }
        }
    }

    int ans=min(DP[N-1][N-1].first, DP[N-1][N-1].second);

    for(int i=0; i<=N; i++){
        for(int j=0; j<=N; j++){
            DP[i][j]={1e18, 1e18};
        }
    }

    DP[0][0]=arr[0][0];

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j].first<0) continue;
            if(i<N-1){
                if(DP[i+1][j].second>DP[i][j].second+arr[i+1][j].second){
                    DP[i+1][j].first=DP[i][j].first+arr[i+1][j].first;
                    DP[i+1][j].second=DP[i][j].second+arr[i+1][j].second;
                }
            }
            if(j<N-1){
                if(DP[i][j+1].second>DP[i][j].second+arr[i][j+1].second){
                    DP[i][j+1].first=DP[i][j].first+arr[i][j+1].first;
                    DP[i][j+1].second=DP[i][j].second+arr[i][j+1].second;
                }
            }
        }
    }

    int ans2=min(DP[N-1][N-1].first, DP[N-1][N-1].second);

    cout << min(ans, ans2);
    
    return 0;
}
