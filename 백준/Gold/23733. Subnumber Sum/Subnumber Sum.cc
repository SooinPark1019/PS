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
각 서브그리드마다 최대 하나의 constraint만 포함 가능

왼쪽위의 서브그리드부터 생각한다고 하자

*/
int DP[20][20];

int fastmul(int a, int b){
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0){
        int temp=fastmul(a, b/2);
        return temp*temp;
    }
    return a*fastmul(a, b-1);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int TC;
    cin >> TC;
    while(TC--){
        int N, K;
        cin >> N >> K;
        memset(DP, -1, sizeof(DP));
        DP[0][0]=0;
        string S;
        cin >> S;
        reverse(all(S));
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(DP[i][j]==-1) continue;
                int a=fastmul(10, j);
                int b=fastmul(10, i-j);
                DP[i+1][j]=max(DP[i+1][j], DP[i][j]+b*(S[i]-'0'));
                DP[i+1][j+1]=max(DP[i+1][j+1], DP[i][j]+a*(S[i]-'0'));
            }
        }
        cout << DP[N][K] << "\n";
    }
    return 0;
}
