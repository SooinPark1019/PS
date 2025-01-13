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
const int mod = 1e9+7;
const int mod2 = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
인접한 두 수가 서로소 -> 자명하게 추가할 필요가 없다
*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<int> L;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        L.push_back(a);
    }
    vector<int> C;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        C.push_back(a);
    }

    map<int, int> M;

    for(int i=0; i<N; i++){
        map<int, int> temp;
        //cout << L[i] << " " << C[i] << endl;
        temp[L[i]]=C[i];
        //cout << temp[L[i]] << endl;
        for(auto j : M){
            int a=j.first;
            int b=j.second;
            //cout << a << " " << b << endl;
            if(temp[__gcd(a, L[i])]==0) temp[__gcd(a, L[i])]=b+C[i];
            else temp[__gcd(a, L[i])]=min(temp[__gcd(a, L[i])], b+C[i]);
        }
        for(auto j : temp){
            int a=j.first;
            int b=j.second;
            if(M[a]==0) M[a]=b;
            else M[a]=min(M[a], b);
        }
    }

    if(M[1]==0) cout << -1;
    else cout << M[1];
    
    return 0;
}
