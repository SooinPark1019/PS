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

int A[105][2];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    int t=1;

    while(TC--){
        cout << "Case #" << t << ": ";
        t++;
        int N, M;
        cin >> N >> M;
        if(M==1){
            int total=0;
            for(int i=0; i<N; i++){
                int a;
                cin >> a;
                if(a>0) total+=a;
            }
            cout << total << "\n";
        }
        else{
            for(int i=0; i<N; i++){
                for(int j=0; j<M; j++){
                    cin >> A[i][j];
                }
            }
            int ans=0;
            for(int j=0; j<M; j++){
                int temp=0;
                for(int i=0; i<N; i++){
                    //cout << A[i][j] << " " << A[i][0] << " " << A[i][1] << "\n";
                    temp+=max({A[i][j], A[i][0]+A[i][1], 0ll});
                }
                //cout << temp << "\n";
                ans=max(ans, temp);
            }
            cout << ans << "\n";
        }
    }

    return 0;
}
