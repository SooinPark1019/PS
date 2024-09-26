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

int stringtoint(string& S){
    int a=0;
    for(int i=0; i<S.length(); i++){
        if(S[i]=='1'){
            a+=(1<<(S.length()-1-i));
        }
    }
    return a;
}

vector<int> makegraycode(int N){
    vector<int> res;
    for(int i=0; i<(1<<N); i++){
        res.push_back(i^(i>>1));
    }
    return res;
}

string inttostring(int a, int b){
    //cout << "a : " << a << "\n";
    string res="";
    for(int i=0; i<b; i++){
        if(a%2) res+='1';
        else res+='0';
        a/=2;
    }
    reverse(all(res));
    return res;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    string P;
    cin >> P;

    int A=stringtoint(P);
    vector<int> graycode=makegraycode(N-1);
    int flag=0;
    if(A>=(1<<(N-1))){
        flag=1;
        A=(1<<N)-1-A;
    }
    int startpos;
    for(int i=0; i<graycode.size(); i++){
        if(graycode[i]==A){
            startpos=i;
            break;
        }
    }
    for(int i=0; i<graycode.size(); i++){
        string A=inttostring(graycode[(startpos+i)%graycode.size()], N);
        string B=inttostring((1<<N)-1-graycode[(startpos+i)%graycode.size()], N);
        if(flag==0) cout << A << "\n" << B << "\n";
        else cout << B << "\n" << A << "\n";
    }

    return 0;
}