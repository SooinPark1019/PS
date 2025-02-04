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
Z로 생각을 해보자
먼저 첫번째 두 배열을 그대로 붙인 상태로 시작을 해서
Z값을 계산
접두사=접미사 되는 곳을 찾아가지고 비용계산
남은 것을 다음 문자열로 이월
*/
int DP[205][205][205][2];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    cin >> N >> L;

    memset(DP, -1, sizeof(DP));

    vector<pii> X(N+1, {0, 0});

    for(int i=1; i<=N; i++){
        int a;
        cin >> a;
        X[i].first=a;
    }
    
    for(int i=1; i<=N; i++){
        int a;
        cin >> a;
        X[i].second=a;
    }

    sort(all(X));
    DP[0][0][0][0]=0;
    DP[0][0][0][1]=0;
    for(int left=0; left<=N; left++){
        for(int j=N+1; j>=0; j--){
            for(int cnt=0; cnt<=N; cnt++){
                for(int isleft=0; isleft<2; isleft++){
                    int right=j%(N+1);
                    if(DP[left][right][cnt][isleft]<0) continue;
                    //cout << "left : " << left << " right : " << right << " cnt : " << cnt << " isleft : " << isleft << " DP : " << DP[left][right][cnt][isleft] << "\n";
                    int curpos=left;
                    if(isleft==0) curpos=right;
                    if(left+1<j){
                        int nxttime=(X[left+1].first-X[curpos].first+L)%L+DP[left][right][cnt][isleft];
                        //cout << "curpos : " << X[curpos].first << " nxtpos : " << X[left+1].first << " nxttime : " << nxttime << "\n";
                        if(DP[left+1][right][cnt+(nxttime<=X[left+1].second)][1]==-1) DP[left+1][right][cnt+(nxttime<=X[left+1].second)][1]=nxttime;
                        else DP[left+1][right][cnt+(nxttime<=X[left+1].second)][1]=min(DP[left+1][right][cnt+(nxttime<=X[left+1].second)][1], nxttime);
                    }
                    if(j-1>left){
                        int nxttime=(X[curpos].first-X[j-1].first+L)%L+DP[left][right][cnt][isleft];
                        if(DP[left][j-1][cnt+(nxttime<=X[j-1].second)][0]==-1) DP[left][j-1][cnt+(nxttime<=X[j-1].second)][0]=nxttime;
                        else DP[left][j-1][cnt+(nxttime<=X[j-1].second)][0]=min(DP[left][j-1][cnt+(nxttime<=X[j-1].second)][0], nxttime);
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=0; i<=N; i++){
        for(int j=0; j<=N; j++){
            for(int k=0; k<=N; k++){
                for(int l=0; l<2; l++){
                    if(DP[i][j][k][l]<0) continue;
                    ans=max(ans, k);
                }
            }
        }
    }
    cout << ans;
    return 0;
}
