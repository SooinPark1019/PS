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
const ll mod = 998244353;
const int MAXN = (1<<18)+5;
const int D = 20;

int DP[MAXN][105];
pii previous[MAXN][105];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> V;
    for(int i=0; i<N-1; i++){
        int a;
        cin >> a;
        V.push_back(a);
    }
    for(int i=1; i<=100; i++) DP[0][i]=1;
    for(int i=0; i<(1<<(N-1)); i++){
        for(int j=1; j<=100; j++){
            if(DP[i][j]==0) continue;
            for(int k=0; k<N-1; k++){
                if((i&(1<<k))!=0||V[k]%j!=0||V[k]/j>100) continue;
                //cout << i+(1<<k) << " " << V[k]/j << "\n";
                DP[i+(1<<k)][V[k]/j]=1;
                previous[i+(1<<k)][V[k]/j]={i, j};
            }
        }
    }
    int flag=0;
    for(int i=1; i<=100; i++){
        if(DP[(1<<(N-1))-1][i]==1){
            flag=1;
            cout << "Yes\n";
            int state=(1<<(N-1))-1;
            int ans=i;
            int t=0;
            while(state!=0){
                t++;
                //cout << state << " " << ans << "\n";
                cout << ans << " ";
                pii temp=previous[state][ans];
                state=temp.first;
                ans=temp.second;
            }
            cout << ans << " ";
            break;
        }
    }
    if(flag==0) cout << "No";
    return 0;
}