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

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;
const ll MAX = 1e6;

pll DP[MAX+5][2];
vector<ll> V[2];

void backtrack(int a, int b, int c){
    //cout << a << " " << b << " " << c << "\n";
    if(a>0){
        if(DP[a-1][0].first<=c&&c<=DP[a-1][0].second&&V[0][a-1]<=V[b][a]) backtrack(a-1, 0, c);
        else backtrack(a-1, 1, c-1);
    }
    if(b==0) cout << "A";
    else cout << "B";
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for(int i=0; i<2; i++){
        for(int j=0; j<2*N; j++){
            ll a;
            cin >> a;
            V[i].push_back(a);
        }
    }
    DP[0][0]={0, 0};
    DP[0][1]={1, 1};
    for(int i=1; i<2*N; i++){
        //cout << "i : " << i << endl;
        for(int j=0; j<2; j++){
            //cout << "j : " << j << " ";
            ll lastA=V[0][i-1];
            ll lastB=V[1][i-1];
            //cout << lastA << " " << lastB << endl;
            ll cur=V[j][i];
            if(max(lastA, lastB)<=cur){
                ll left=min(DP[i-1][0].first, DP[i-1][1].first)+j;
                ll right=max(DP[i-1][0].second, DP[i-1][1].second)+j;
                DP[i][j]={left, right};
            }
            else if(lastA<=cur){
                ll left=DP[i-1][0].first+j;
                ll right=DP[i-1][0].second+j;
                DP[i][j]={left, right};
            }
            else if(lastB<=cur){
                ll left=DP[i-1][1].first+j;
                ll right=DP[i-1][1].second+j;
                DP[i][j]={left, right};
            }
            else{
                DP[i][j]={1e18, -1};
            }
            //cout << DP[i][j].first << " " << DP[i][j].second << " ";
        }
        //cout << "\n";
    }
    if(DP[2*N-1][0].first<=N&&DP[2*N-1][0].second>=N){
        backtrack(2*N-1, 0, N);
    }
    else if(DP[2*N-1][1].first<=N&&DP[2*N-1][1].second>=N){
        backtrack(2*N-1, 1, N-1);
    }
    else cout << -1;
}