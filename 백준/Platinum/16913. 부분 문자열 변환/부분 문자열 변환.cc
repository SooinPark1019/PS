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

/*
DP[i][j]=i번째 까지 봤을 때 j번째까지 같다면 그때의 최대 횟수
*/

vector<int> failure(string& s){
    vector<int> f(s.length());
    int j=0;
    for(int i=1; i<s.length(); i++){
        while(j>0&&s[i]!=s[j]) j=f[j-1];
        if(s[i]==s[j]) f[i]=++j;
    }
    return f;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string S, T;
    cin >> S >> T;
    cin >> S >> T;
    
    int N=S.length();
    int M=T.length();

    vector<vector<int>> DP(N+1, vector<int>(M+1, -1));

    DP[0][0]=0;

    vector<int> f=failure(T);

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(DP[i][j]==-1) continue;
            int a=i;
            int b=j;
            if(S[a]!='?'){
                while(b>0&&S[a]!=T[b]) b=f[b-1];
                if(S[a]==T[b]) b++;
                if(b==M) DP[a+1][f[b-1]]=max(DP[a+1][f[b-1]], DP[i][j]+1);
                else DP[a+1][b]=max(DP[a+1][b], DP[i][j]);
            }
            else{
                while(1){
                    if(b==M-1) DP[a+1][f[M-1]]=max(DP[a+1][f[M-1]], DP[i][j]+1);
                    else{
                        DP[a+1][b+1]=max(DP[a+1][b+1], DP[i][j]);
                    } 
                    if(b==0) break;
                    b=f[b-1];
                }
            }
        }
    }

    int ans=0;

    for(int i=0; i<M; i++){
        ans=max(ans, DP[N][i]);
    }

    cout << ans;

    return 0;
}
