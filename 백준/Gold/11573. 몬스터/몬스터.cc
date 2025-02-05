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
long double DP[105][105][105]={};
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--){
        int A, B, C;
        cin >> A >> B >> C;
        for(int i=0; i<=A; i++){
            for(int j=0; j<=B; j++){
                for(int k=0; k<=C; k++) DP[i][j][k]=0;
            }
        }
        DP[A][B][C]=1;
        for(int i=A+B+C; i>1; i--){
            for(int b=B; b>=0; b--){
                for(int c=C; c>=0; c--){
                    int a=i-b-c;
                    if(a>A||b>B||c>C||a<0||b<0||c<0) continue;
                    //cout << "a : " << a << " b : " << b << " c : " << c << " DP : " << DP[a][b][c]  << "\n";
                    long double total=a*b+b*c+a*c;
                    if(a>0&&b>0) DP[a][b-1][c]+=DP[a][b][c]*a*b/total;
                    if(b>0&&c>0) DP[a][b][c-1]+=DP[a][b][c]*b*c/total;
                    if(a>0&&c>0) DP[a-1][b][c]+=DP[a][b][c]*a*c/total;
                }
            }
        }
        cout << fixed;
        cout.precision(12);
        double ans1=0, ans2=0, ans3=0;
        for(int i=1; i<=A; i++) ans1+=DP[i][0][0];
        for(int i=1; i<=B; i++) ans2+=DP[0][i][0];
        for(int i=1; i<=C; i++) ans3+=DP[0][0][i];
        cout << ans1 << " " << ans2 << " " << ans3 << "\n";
    }    

    return 0;
}
