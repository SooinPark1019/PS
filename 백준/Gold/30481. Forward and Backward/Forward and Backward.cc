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
const int MAXN = 2e5+5;
const int D = 20;

vector<int> transbase(int N, int b){
    vector<int> V;
    while(N>0){
        V.push_back(N%b);
        N/=b;
    }
    return V;
}

bool ispalindrome(vector<int>& V){
    for(int i=0; i<(int)V.size()/2; i++){
        if(V[i]!=V[V.size()-1-i]){
            return false;
        }
    }
    return true;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    if(N==2){
        cout << "*";
        return 0;
    }
    vector<int> ans;
    for(int i=2; i*i<=N; i++){
        vector<int> V=transbase(N, i);
        if(ispalindrome(V)){
            ans.push_back(i);
        }
    }
    for(int i=1; i*i<=N; i++){
        int a=N-i;
        if(a%i!=0) continue;
        int b=(N-i)/i;
        if(b>i) ans.push_back(b);
    }
    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());
    for(auto i : ans){
        vector<int> V=transbase(N, i);
        assert(ispalindrome(V));
    }
    for(auto i : ans) cout << i << " ";
    return 0;
}