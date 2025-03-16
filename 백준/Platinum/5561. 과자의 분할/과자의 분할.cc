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
//#define sz(x) (int)x.size()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long

using namespace std;

//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
/*#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>//이걸 코드의 윗부분에 추가
void m_erase(ordered_set &OS, int val){
    int index = OS.order_of_key(val);
    ordered_set::iterator it = OS.find_by_order(index);
    if(*it == val) OS.erase(it);
}*/
//다른 건 통상적인 PBDS처럼 사용하면 되지만 erase는 반드시!!! 이 함수를 통해서만 해야 함
//m_erase(OS, 지울 원소)처럼 사용하면 된다. 꼭 주의하자.
//얘네 쓰려면 define int long long 꺼라.

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
*/
int DP[2][5005][2];
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
    for(int i=0; i<2; i++){
        for(int j=0; j<=N/2; j++){
            for(int k=0; k<2; k++) DP[i][j][k]=1e18;
        }
    }
    DP[0][0][0]=0;
    DP[0][1][1]=0;
    for(int i=0; i<N-1; i++){
        for(int j=0; j<=min(i+1, N/2); j++){
            for(int k=0; k<2; k++){
                if(DP[0][j][k]==1e18) continue;
                if(k==0){
                    DP[1][j+1][1]=min(DP[1][j+1][1], DP[0][j][k]+V[i]);
                    DP[1][j][0]=min(DP[1][j][0], DP[0][j][k]);
                }
                else{
                    DP[1][j+1][1]=min(DP[1][j+1][1], DP[0][j][k]);
                    DP[1][j][0]=min(DP[1][j][0], DP[0][j][k]+V[i]);
                }
            }
        }
        for(int j=0; j<=N/2; j++){
            for(int k=0; k<2; k++){
                DP[0][j][k]=DP[1][j][k];
                DP[1][j][k]=1e18;
            }
        }
    }

    cout << min(DP[0][N/2][0], DP[0][N/2][1]);

    return 0;
}
