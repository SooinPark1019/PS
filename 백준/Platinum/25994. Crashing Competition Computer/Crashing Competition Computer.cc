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
//#define int long long
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
DP[i][j]=현재 인덱스가 i이고 마지막으로 저장한 위치가 j일 때 앞으로 필요한 기대횟수

아니면 DP[i]][j]=``일 때 i, j에 도달하기 위해 필요한 기대시간

2번으로 생각해보자

마지막으로 저장을 누르는 위치에 따라서 나눠볼까

DP[i][j]=현재 인덱스가 i이고 마지막으로 저장한 위치가 j일 때 마지막으로 저장한 위치에서 도달하가 위해 필요한 기댓값

걍 이거를
DP[i] 저장을 안하고 i칸을 가려면 필요한 기대횟수
*/

double DP1[2005];
double DP2[2005];

signed main(){
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    
    int c, t, r;
    cin >> c >> t >> r;
    double p;
    cin >> p;
    DP1[0]=0;
    for(int i=1; i<=c; i++){
        DP1[i]=DP1[i-1]/(1-p)+(1+r*p)/(1-p);
    }
    /*for(int i=1; i<=c; i++){
        cout << DP1[i] << " ";
    }*/
    //cout << "\n";
    for(int i=1; i<=c; i++){
        DP2[i]=1e18;
    }
    for(int i=0; i<=c; i++){
        double a=DP2[i];
        //cout << a << " ";
        if(i!=0) a+=t;
        for(int j=1; j+i<=c; j++){
            DP2[i+j]=min(DP2[i+j], a+DP1[j]);
        }
    }
    //cout << "\n";
    cout << fixed;
    cout.precision(12);
    cout << DP2[c]+t;
    return 0;
}
