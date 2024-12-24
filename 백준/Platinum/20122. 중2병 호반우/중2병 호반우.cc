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
const ll mod = 10007;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);
const int MAX=1ll<<20;
/*
당연한 얘기지만 나누어떨어져야 하고
X가 7 이상이면 항상 가능
*/

int maxDP[MAX];//0~N-1:가로, N~(N+M-1): 세로
int minDP[MAX];
int arr[15][15];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M, a, b, c;
    cin >> N >> M >> a >> b >> c;

    vector<pii> muls;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
            if(arr[i][j]==3){
                muls.push_back({i, j});
            }
        }
    }

    for(int i=0; i<(1ll<<(N+M)); i++){
        minDP[i]=2e18;
    }
    for(int i=0; i<(1ll<<(N+M)); i++){
        maxDP[i]=-2e18;
    }

    minDP[0]=0;
    maxDP[0]=0;

    for(int i=0; i<(1ll<<(N+M)); i++){
        //cout << "i : " << i << "\n";
        //cout << maxDP[i] << " " << minDP[i] << "\n";
        int cur_mul=1;
        for(auto p : muls){
            if((i&(1ll<<p.first))||(i&(1ll<<(N+p.second)))) cur_mul*=c;
        }
        //cout << "curmul : " << cur_mul << "\n";
        for(int j=0; j<N; j++){
            if((i&(1ll<<j))) continue;
            int tempmul=cur_mul;
            int temp=0;
            for(int k=0; k<M; k++){
                if(i&(1ll<<(N+k))) continue;
                if(arr[j][k]==1) temp+=a*tempmul;
                else if(arr[j][k]==2) temp+=b*tempmul;
                else if(arr[j][k]==3) tempmul*=c;
            }
            //cout << "tempmul : " << tempmul << " temp : " << temp << "\n";
            maxDP[i+(1ll<<j)]=max({maxDP[i+(1ll<<j)], maxDP[i]+temp});
            minDP[i+(1ll<<j)]=min({minDP[i+(1ll<<j)], minDP[i]+temp});
        }
        for(int j=N; j<N+M; j++){
            if(i&(1ll<<j)) continue;
            int tempmul=cur_mul;
            int temp=0;
            for(int k=0; k<N; k++){
                if(i&(1<<k)) continue;
                if(arr[k][j-N]==1) temp+=a*tempmul;
                else if(arr[k][j-N]==2) temp+=b*tempmul;
                else if(arr[k][j-N]==3) tempmul*=c;
            }
            //cout << "tempmul : " << tempmul << " temp : " << temp << "\n";
            maxDP[i+(1ll<<j)]=max({maxDP[i+(1ll<<j)], maxDP[i]+temp});
            minDP[i+(1ll<<j)]=min({minDP[i+(1ll<<j)], minDP[i]+temp});
        }
    }

    int maxans=-2e18;
    int minans=2e18;

    for(int i=0; i<(1ll<<(N+M)); i++){
        maxans=max(maxans, maxDP[i]);
        minans=min(minans, minDP[i]);
    }

    cout << minans << " " << maxans << "\n";

    return 0;
}
