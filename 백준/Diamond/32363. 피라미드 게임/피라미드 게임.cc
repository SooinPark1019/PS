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
#define int long long

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 1e9+7;
const int MAXN = 1e9+7;
const int D = 20;

int arr[1005][1005];
int DP[1005][1005];
int check[1005][1005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--){
        int N, K;
        cin >> N >> K;
        for(int i=0; i<=N+1; i++){
            for(int j=0; j<=N+1; j++){
                DP[i][j]=0;
                check[i][j]=0;
            }
        }
        for(int i=N; i>=1; i--){
            for(int j=1; j<=N-i+1; j++){
                cin >> arr[i][j];
            }
        }
        int ans=0;
        for(int i=K; i<=N; i++){
            //cout << i << endl;
            for(int j=1; j<=N-i+1; j++){
                //cout << j << endl;
                int cnt=DP[i-1][j];
                for(int k=0; k<K; k++){
                    if(check[i-K][j+k]==1) cnt--;
                }
                //cout << "!" << endl;
                for(int k=0; k<K; k++){
                    //cout << i-k << " " << j+k << endl;
                    if(check[i-k][j+k]==1) cnt++;
                }
                if(cnt%2==0&&arr[i][j]>=0){
                    check[i][j]=1;
                    ans^=arr[i][j];
                }
                DP[i][j]=cnt+check[i][j];
                //cout << DP[i][j] << " ";
            }
            //cout << endl;
        }
        if(ans==0) cout << "Second\n";
        else cout << "First\n";
    }
    
    return 0;
}