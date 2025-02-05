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

char arr[105][105];
int DP[105][105][100];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }

    string S;
    cin >> S;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j]==S[0]) DP[i][j][0]=1;
        }
    }

    int dx[4]={0, 0, -1, 1};
    int dy[4]={-1, 1, 0, 0};

    for(int a=0; a<S.length()-1; a++){
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(DP[i][j][a]==0) continue;
                //cout << "i : " << i << " j : " << j << " a : " << a << " DP : " << DP[i][j][a] << "\n";
                for(int k=1; k<=K; k++){
                    for(int d=0; d<4; d++){
                        int nx=i+dx[d]*k;
                        int ny=j+dy[d]*k;
                        if(nx<0||nx>=N||ny<0||ny>=M||arr[nx][ny]!=S[a+1]) continue;
                        DP[nx][ny][a+1]+=DP[i][j][a];
                    }
                }
            }
        }
    }

    int ans=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            ans+=DP[i][j][S.length()-1];
        }
    }
    cout << ans;

    return 0;
}
