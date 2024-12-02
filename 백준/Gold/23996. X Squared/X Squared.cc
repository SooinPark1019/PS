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
const ll mod = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    int T=0;
    while(TC--){
        T++;
        int flag=0;
        int onerow;
        int onecol;
        int N;
        cin >> N;
        char arr[60][60];
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cin >> arr[i][j];
            }
        }
        for(int i=0; i<N; i++){
            int cnt=0;
            for(int j=0; j<N; j++){
                if(arr[i][j]=='X') cnt++;
            }
            if(cnt>=3) flag=1;
            if(cnt==1) onerow=i;
        }
        for(int i=0; i<N; i++){
            int cnt=0;
            for(int j=0; j<N; j++){
                if(arr[j][i]=='X') cnt++;
            }
            if(cnt>=3) flag=1;
            if(cnt==1) onecol=i;
        }
        for(int i=0; i<N; i++){
            if(i==onerow) continue;
            int samecnt=0;
            for(int j=0; j<N; j++){
                if(j==onerow||i==j) continue;
                int same=0;
                for(int k=0; k<N; k++){
                    if(arr[i][k]!=arr[j][k]){
                        same=1;
                        break;
                    }
                }
                if(same==0) samecnt++;
            }
            if(samecnt!=1) flag=1;
        }
        for(int i=0; i<N; i++){
            if(i==onecol) continue;
            int samecnt=0;
            for(int j=0; j<N; j++){
                if(j==onecol||i==j) continue;
                int same=0;
                for(int k=0; k<N; k++){
                    if(arr[k][i]!=arr[k][j]){
                        same=1;
                        break;
                    }
                }
                if(same==0) samecnt++;
            }
            if(samecnt!=1) flag=1;
        }
        if(flag==0&&arr[onerow][onecol]=='X') cout << "Case #" << T << ": POSSIBLE\n";
        else cout << "Case #" << T << ": IMPOSSIBLE\n";
    }
    
    return 0;
}
