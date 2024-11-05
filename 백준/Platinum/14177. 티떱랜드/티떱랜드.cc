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

/*
*/

int DP[805][4005];
int arr[4005][4005];
int prefix[4005][4005];
int opt[805][4005];

void dnc(int t, int s, int e, int l, int r){
    if(s>e) return;
    int mid=(s+e)/2;
    DP[t][mid]=opt[t][mid]=-1;
    for(int i=l; i<=(mid, r); i++){
        int temp=prefix[mid][mid]-prefix[i-1][mid]-prefix[mid][i-1]+prefix[i-1][i-1];
        temp>>=1;
        temp+=DP[t-1][i-1];
        if(DP[t][mid]==-1||DP[t][mid]>temp){
            DP[t][mid]=temp;
            opt[t][mid]=i;
        }
    }
    dnc(t, s, mid-1, l, opt[t][mid]);
    dnc(t, mid+1, e, opt[t][mid], r);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, K;
    cin >> N >> K;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> arr[i][j];
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            prefix[i][j]=arr[i][j]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
        }
    }

    for(int i=1; i<=N; i++){
        opt[1][i]=1;
        DP[1][i]=prefix[i][i]/2;
    }

    for(int i=2; i<=K; i++){
        dnc(i, 1, N, 1, N);
    }
    cout << DP[K][N];
    return 0;
}