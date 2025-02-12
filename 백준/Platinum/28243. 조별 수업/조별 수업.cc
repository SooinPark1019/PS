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
//#define sz(x) (int)x.size()

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
typedef complex<double> cpx;
//typedef __int128 i128;
typedef long double ld;
typedef pair<double, int> pdl;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 1e9+7;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
DP[i]=첫번째 재료의 가치가 i일 때 두번째 재료의 가능한 최대 가치

두 차원 모두 양수인 거는 당연히 그대로 합치고
그렇지 않을 경우 취할 차원을 선택

나머지는 취할 차원만 취하거나 아니면 둘다 취해야 함
*/

int DP[1005][1005][55];
int fac[1005];
int inv_fac[1005];

int fastmul(int a, int b){
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0){
        int temp=fastmul(a, b/2);
        return temp*temp%mod;
    }
    return a*fastmul(a, b-1)%mod;
}

int bino(int a, int b){
    return fac[a]*inv_fac[a-b]%mod*inv_fac[b]%mod;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    fac[0]=1;
    for(int i=1; i<=N; i++){
        fac[i]=fac[i-1]*i%mod;
    }

    inv_fac[N]=fastmul(fac[N], mod-2);

    for(int i=N-1; i>=0; i--){
        inv_fac[i]=inv_fac[i+1]*(i+1)%mod;
    }

    DP[N][0][0]=1;

    for(int i=N; i>=1; i--){
        for(int j=0; j<=N; j++){
            for(int k=0; k*(k+1)/2<=N; k++){
                if(DP[i][j][k]==0) continue;
                DP[i-1][j][k]+=DP[i][j][k];
                DP[i-1][j][k]%=mod;
                if(N-i+1-j>=i){
                    DP[i-1][i+j][k+1]+=DP[i][j][k]*bino(N-i-j, i-1)%mod*fac[i]%mod;
                    DP[i-1][i+j][k+1]%=mod;
                }
            }
        }
    }

    int ans=0;

    for(int i=1; i*(i+1)/2<=N; i++){
        ans+=DP[0][N][i]*fac[i]%mod;
        ans%=mod;
    }

    cout << ans;

    return 0;
}
