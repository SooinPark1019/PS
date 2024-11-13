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
const int MAXN = (1<<18)+5;
const int D = 20;

/*
1을 루트로 하는 트리를 생각하자
엘리스는 부모로 올라갈 것이고
퀸은 리프와의 최단 경로로 끌어내릴 것이다
각 정점마다 부모와의 거리, 리프와의 최단 경로를 적어 두자
*/

int DP[505][255][365];
int previous[505][255][365];

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

    if(N%2){
        cout << "NO\n";
        return 0;
    }

    DP[0][0][0]=1;
    for(int i=0; i<N; i++){
        for(int j=0; j<=N/2; j++){
            for(int k=0; k<360; k++){
                if(DP[i][j][k]==0) continue;
                if(j<N/2){
                    DP[i+1][j+1][(k+2*V[i])%360]=1;
                    previous[i+1][j+1][(k+2*V[i])%360]=1;
                    //cout << i+1 << " " << j+1 << " " << (k+V[i])%360 << "\n";
                }
                DP[i+1][j][(k-2*V[i]+360)%360]=1;
                previous[i+1][j][(k-2*V[i]+360)%360]=0;
                //cout << i+1 << " " << j << " " << (k-V[i]+360)%360 << "\n";
            }
        }
    }
    if(DP[N][N/2][0]==0) cout << "NO\n";
    else{
        cout << "YES\n";
        int curi=N;
        int curj=N/2;
        int curk=0;
        vector<int> ans(N+1);
        int oddindex=1;
        int evenindex=0;
        while(curi!=0){
            //cout << curi << " " << curj << " " << curk << endl;
            if(previous[curi][curj][curk]==0){
                curi--;
                curk+=2*V[curi];
                curk%=360;
                ans[evenindex]=curi;
                evenindex+=2;
            }
            else{
                curi--;
                curj--;
                curk-=2*V[curi];
                curk+=360;
                curk%=360;
                ans[oddindex]=curi;
                oddindex+=2;
            }
        }
        for(int i=0; i<N; i++) cout << ans[i]+1 << " ";
    }

    return 0;
}
