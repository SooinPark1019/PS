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
const ll mod = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
5000까지의 카탈란 수 전처리
set으로 구간 관리

크기마다 카탈란 수 곱하기
*/
int edge[1005][1005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--){
        int N;
        cin >> N;
        for(int i=1; i<N; i++){
            for(int j=i+1; j<=N; j++){
                cin >> edge[i][j];
                edge[j][i]=edge[i][j];
            }
        }
        int ans=0;
        for(int i=1; i<=N; i++){
            int redcnt=0;
            int bluecnt=0;
            for(int j=1; j<=N; j++){
                if(i==j) continue;
                if(edge[i][j]==1) redcnt++;
                else bluecnt++;
            }
            ans+=redcnt*bluecnt;
        }
        cout << N*(N-1)*(N-2)/6-ans/2 << "\n";
    }

    return 0;
}
