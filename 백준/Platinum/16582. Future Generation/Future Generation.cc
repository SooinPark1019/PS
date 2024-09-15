#include <ext/rope>
#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
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
const int debug = 1;
const int MAX = 1<<15+5;

vector<pair<int, int>> V[20][20];
vector<string> L;
map<string, int> M;
vector<string> X;
int DP[20][MAX];
ll maxlength[MAX];

void preprocess(int a, string& S, string& T){
    if(a==S.length()){
        X.push_back(T);
        return;
    }
    string T1=T+S[a];
    string T2=T;
    preprocess(a+1, S, T1);
    preprocess(a+1, S, T2);
}

string cut(string A, int j){
    //if(debug) cout << "i : " << i << " j : " << j << "\n";
    string temp="";
    for(int k=0; k<A.length(); k++){
        if((j&(1ll<<k))!=0) temp+=A[k];
    }
    return temp;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        string S;
        cin >> S;
        L.push_back(S);
        string temp="";
        preprocess(0, S, temp);
    }

    sort(all(X));
    X.erase(unique(all(X)), X.end());

    for(int i=0; i<X.size(); i++){
        M[X[i]]=i;
    }

    memset(DP, -1, sizeof(DP));

    for(int i=1; i<(1ll<<L[0].length()); i++){
        string temp=cut(L[0], i);
        DP[0][M[temp]]=temp.length();
    }

    for(int i=1; i<N; i++){
        //if(debug) cout << "i : " << i << " " << (1ll<<L[i].length()) << "\n";
        //memset(maxlength, -1, sizeof(maxlength));
        for(int j=0; j<X.size(); j++){
            if(j==0) maxlength[j]=DP[i-1][j];
            else maxlength[j]=max(maxlength[j-1], DP[i-1][j]);
            //cout << maxlength[j] << "\n";
        }
        //cout << "\n";
        for(int j=1; j<(1ll<<L[i].length()); j++){
            string temp=cut(L[i], j);
            int a=M[temp];
            if(a==0||maxlength[a-1]<=0) continue;
            DP[i][a]=maxlength[a-1]+temp.length();
        }
    }

    int ans=-1;
    for(int i=0; i<X.size(); i++){
        //cout << DP[N-1][i] << "\n";
        ans=max(ans, DP[N-1][i]);
    }
    cout << ans;
    return 0;
}