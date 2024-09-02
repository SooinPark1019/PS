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
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define debug1(x,y) cout << x << " :: " << y << " "
#define coutn cout << "\n"
#define debug2 puts("--@222%--")
#define debug3 puts("--@333%--")

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;

vector<int> failure(string& s){
    vector<int> f(s.length());
    int j=0;
    for(int i=1; i<s.length(); i++){
        while(j>0&&s[i]!=s[j]) j=f[j-1];
        if(s[i]==s[j]) f[i]=++j;
    }
    return f;
}

int DP[100005]={};
int curindex[505]={};
vector<string> V;
vector<int> f[505];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string S;
    cin >> S;
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        string T;
        cin >> T;
        f[i]=failure(T);
        V.push_back(T);
    }
    for(int i=0; i<S.length()+1; i++){
        DP[i]=987654321;
    }
    DP[0]=0;
    for(int i=0; i<S.length(); i++){
        if(i!=0) DP[i]=min(DP[i], DP[i-1]+1);
        for(int j=0; j<N; j++){
            int &k=curindex[j];
            while(k>0&&S[i]!=V[j][k]) k=f[j][k-1];
            if(S[i]==V[j][k]) k++;
            if(k==V[j].length()){
                int a=i-V[j].length()+1;
                DP[i+1]=min(DP[i+1],DP[a]);
                k=f[j][k-1];
            }
        }
    }
    DP[S.length()]=min(DP[S.length()], DP[S.length()-1]+1);
    cout << S.length()-DP[S.length()];
    return 0;
}