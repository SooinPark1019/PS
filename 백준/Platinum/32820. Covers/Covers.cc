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
//#define sz(x) (int)x.size()

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
typedef complex<double> cpx;
//typedef __int128 i128;
typedef long double ld;
typedef pair<double, int> pdl;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 1e9+7;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
DP[i]=첫번째 재료의 가치가 i일 때 두번째 재료의 가능한 최대 가치

두 차원 모두 양수인 거는 당연히 그대로 합치고
그렇지 않을 경우 취할 차원을 선택

나머지는 취할 차원만 취하거나 아니면 둘다 취해야 함
*/

vector<int> failure(string& s){
    vector<int> f(s.length());
    for(int i=1, j=0; i<s.length(); i++){
        while(j>0&&s[i]!=s[j]) j=f[j-1];
        if(s[i]==s[j]) f[i]=++j;
    }
    return f;
}

vector<int> V(200005);
int DP[200005][2];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> M >> N;

    string T, P;
    cin >> P >> T;

    vector<int> f=failure(P);

    vector<int> V(N);

    for(int i=0, j=0; i<T.length(); i++){
        while(j>0&&P[j]!=T[i]) j=f[j-1];
        if(P[j]==T[i]) j++;
        V[i]=j;
        if(j==T.length()){
            j=f[j-1];
        }
        V[i]=j;
        //cout << j << " ";
    }

    //cout << endl;

    for(int i=0; i<=T.length(); i++){
        DP[i][0]=1e18;
        DP[i][1]=1e18;
    }

    DP[N][0]=0;
    for(int i=N; i>0; i--){
        DP[i-1][0]=min({DP[i-1][0], DP[i][0]+1, DP[i][1]+1});
        if(V[i-1]==M){
            DP[i-M][1]=min({DP[i-M][1], DP[i][0], DP[i][1]});
        }
        else if(V[i-1]>0){
            DP[i-V[i-1]][1]=min({DP[i][1]+M-V[i-1], DP[i-V[i-1]][1]});
        }
    }

    cout << min(DP[0][0], DP[0][1]);

    return 0;
}
