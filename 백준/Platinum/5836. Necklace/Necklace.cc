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
const int MAXN = 1e5+5;
const int D = 18;

vector<int> failure(string& s){
    vector<int> f(s.length());
    int j=0;
    for(int i=1; i<s.length(); i++){
        while(j>0&&s[i]!=s[j]) j=f[j-1];
        if(s[i]==s[j]) f[i]=++j;
    }
    return f;
}//실패함수 반환

int DP[10005][1005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string N, M;
    cin >> N >> M;
    vector<int> f=failure(M);
    memset(DP, -1, sizeof(DP));
    DP[0][0]=0;
    for(int i=0; i<N.length(); i++){
        for(int j=0; j<M.length(); j++){
            if(DP[i][j]==-1) continue;
            DP[i+1][j]=max(DP[i+1][j], DP[i][j]);
            int temp=j;
            while(temp>0&&N[i]!=M[temp]){
                temp=f[temp-1];
            }
            if(N[i]==M[temp]) temp++;
            if(temp==M.length()) continue;
            DP[i+1][temp]=max(DP[i+1][temp], DP[i][j]+1);
        }
    }
    int ans=0;
    for(int i=0; i<M.length(); i++){
        ans=max(ans, DP[N.length()][i]);
    }
    cout << N.length()-ans;

    return 0;
}