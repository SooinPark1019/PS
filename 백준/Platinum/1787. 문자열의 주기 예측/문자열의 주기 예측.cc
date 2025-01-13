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

    string S;
    cin >> S;

    vector<int> Z;
    Z.push_back(S.length());
    int L=0, R=0;
    for(int i=1; i<S.length(); i++){
        if(i>R){
            L=i;
            R=i;
            while(R<N&&S[R]==S[R-L]) R++;
            Z.push_back(R-L);
            R--;
        }
        else{
            if(Z[i-L]<=R-i){
                Z.push_back(Z[i-L]);
            }
            else{
                L=i;
                while(R<N&&S[R]==S[R-L]) R++;
                Z.push_back(R-L);
                R--;
            }
        }
    }
    stack<int> St;
    int ans=0;
    for(int i=0; i<N; i++){
        St.push(i);
        while(St.top()+Z[St.top()]-1<i) St.pop();
        if(St.top()>=(i+1)/2) ans+=St.top();
    }

    cout << ans;

    return 0;
}
