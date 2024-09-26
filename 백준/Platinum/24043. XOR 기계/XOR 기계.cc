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
const ll mod = 1e9+7;
const int MAXN = 1e5+5;

int K=20;

int reduce(vector<int>& b, int x){
    for(int i=K-1; i>=0; i--){
        if(x&(1<<i)){
            x=x^b[i];
        }
    }
    return x;
}

bool add(vector<int>& b, int x){
    x=reduce(b, x);
    if(x!=0){
        for(int i=K-1; i>=0; i--){
            if(x&(1<<i)){
                b[i]=x;
                return true;
            }
        }
    }
    return false;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> b(20);
    vector<int> basis;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        if(add(b, a)) basis.push_back(i);
    }
    cout << (1<<basis.size())-1 << "\n";
    vector<int> graycode;
    for(int i=1; i<(1<<basis.size()); i++){
        int a=i^(i>>1);
        graycode.push_back(a);
    }
    int cur=0;
    for(int i=0; i<graycode.size(); i++){
        for(int j=0; j<basis.size(); j++){
            if((cur&(1<<j))!=(graycode[i]&(1<<j))){
                cout << basis[j]+1 << "\n";
                cur=graycode[i];
                break;
            }
        }
    }
    return 0;
}