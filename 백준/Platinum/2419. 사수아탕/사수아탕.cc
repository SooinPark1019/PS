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
int DP[305][305][305][2];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for(int i=0; i<=N+1; i++){
        for(int j=0; j<=N+1; j++){
            for(int k=0; k<=N+1; k++){
                for(int l=0; l<2; l++){
                    DP[i][j][k][l]=-1e18;
                }
            }
        }
    }

    vector<int> V;
    V.push_back(0);
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        V.push_back(a);
    }

    sort(all(V));

    int zeropos;
    for(int i=0; i<=N; i++){
        if(V[i]==0){
            zeropos=i;
            break;
        }
    }

    for(int i=0; i<=N+1; i++){
        DP[zeropos][zeropos][i][0]=0;
        DP[zeropos][zeropos][i][1]=0;
    }

    for(int i=0; i<N; i++){
        for(int j=max(0ll, zeropos-i); j<=min(N, zeropos+i); j++){
            int s=j, e=j+i;
            //cout << "s : " << s << " e : " << e << "\n";
            for(int k=i+1; k<=N; k++){
                //cout << "k : " << k << "\n";
                //cout << "DP : " << DP[s][e][k][0] << " " << DP[s][e][k][1] << "\n";
                if(s>0){
                    DP[s-1][e][k][0]=max({DP[s-1][e][k][0], DP[s][e][k][0]+M-abs(V[s]-V[s-1])*(k-(e-s)), DP[s][e][k][1]+M-abs(V[e]-V[s-1])*(k-(e-s))});
                }
                if(e<N){
                    DP[s][e+1][k][1]=max({DP[s][e+1][k][1], DP[s][e][k][0]+M-abs(V[s]-V[e+1])*(k-(e-s)), DP[s][e][k][1]+M-abs(V[e]-V[e+1])*(k-(e-s))});
                }
            }
        }
    }

    int ans=0;

    for(int i=0; i<=N+1; i++){
        for(int j=0; j<=N+1; j++){
            for(int k=0; k<=N+1; k++){
                for(int l=0; l<2; l++){
                    if(DP[i][j][k][l]<0) continue;
                    //cout << i << " " << j << " " << k << " " << l << "\n";
                    //cout << DP[i][j][k][l] << "\n";
                    ans=max(ans, DP[i][j][k][l]);
                }
            }
        }
    }

    cout << ans;

    return 0;
}
