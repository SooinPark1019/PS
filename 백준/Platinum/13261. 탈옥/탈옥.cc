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

int DP[805][8005];
int prefix[8005];
vector<int> V;

void sol(int t, int s, int e, int l, int r){
    if(s>e) return;
    int mid=(s+e)/2;
    DP[t][mid]=-1;
    int opt=-1;
    for(int i=l; i<=min(r, mid); i++){
        int temp=prefix[mid];
        if(i>0) temp-=prefix[i-1];
        temp*=(mid-i+1);
        if(i>0) temp+=DP[t-1][i-1];
        if(DP[t][mid]==-1||DP[t][mid]>temp){
            DP[t][mid]=temp;
            opt=i;
        }
    }
    sol(t, s, mid-1, l, opt);
    sol(t, mid+1, e, opt ,r);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int L, G;
    cin >> L >> G;
    for(int i=0; i<L; i++){
        int a;
        cin >> a;
        V.push_back(a);
    }

    for(int i=0; i<L; i++){
        prefix[i]=V[i];
        if(i>0) prefix[i]+=prefix[i-1];
        DP[1][i]=prefix[i]*(i+1);
    }

    for(int i=2; i<=G; i++){
        sol(i, 0, L-1, 0, L-1);
    }

    cout << DP[G][L-1];

    return 0;
}