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

int fastmul(int a, int b, int P){
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0){
        int temp=fastmul(a, b/2, P);
        return temp*temp%P;
    }
    return a*fastmul(a, b-1, P)%P;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, P;
    cin >> N >> P;
    vector<int> V(P, 0);
    for(int i=N; i>0; i--){
        int a;
        cin >> a;
        V[i%(P-1)]+=a%P;
        V[i%(P-1)]%=P;
    }
    int a;
    cin >> a;
    vector<int> ans;
    ans.push_back(a%P);
    V[0]+=a%P;
    for(int i=1; i<P; i++){
        int temp=0;
        for(int j=0; j<P-1; j++){
            temp+=V[j]*fastmul(i, j, P)%P;
            temp%=P;
        }
        ans.push_back(temp);
    }  
    for(auto i : ans) cout << i << "\n";

    return 0;
}