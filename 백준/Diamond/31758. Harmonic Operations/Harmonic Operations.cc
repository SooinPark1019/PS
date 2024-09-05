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
const ll mod = 1e9+7;

vector<int> failure(string &s){
    vector<int> f(s.length());
    int j=0;
    for(int i=1; i<s.length(); i++){
        while(j>0&&s[i]!=s[j]) j=f[j-1];
        if(s[i]==s[j]) f[i]=++j;
    }
    return f;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;
    cin >> S;
    int N=S.length();
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
            if(Z[i-L]<=R-i) Z.push_back(Z[i-L]);
            else{
                L=i;
                while(R<N&&S[R]==S[R-L]) R++;
                Z.push_back(R-L);
                R--;
            }
        }
    }
    int sublength=S.length();
    for(int i=1; i<=S.length()-1; i++){
        if(S.length()%i!=0) continue;
        int flag=0;
        for(int j=i; j<S.length(); j+=i){
            if(Z[j]!=S.length()-j){
                flag=1;
                break;
            }
        }
        if(flag==0){
            sublength=i;
            break;
        }
    }
    //cout << "sublength : " << sublength << "\n";
    string T=S.substr(0, sublength);
    string A=T+T;
    reverse(all(T));
    vector<int> f=failure(T);
    int index=-1;
    for(int i=0, j=0; i<A.length(); i++){
        while(j>0&&A[i]!=T[j]) j=f[j-1];
        if(A[i]==T[j]) j++;
        if(j==T.length()){
            index=i-T.length()+1;
            break;
        }
    }
    if(index!=-1) index=(T.length()-index)%T.length();
    //cout << "index : " << index << "\n";
    int curI=0;
    int curR=0;
    map<pair<int, int>, ll> M;
    M[{0, 0}]=1;
    int Q;
    cin >> Q;
    ll ans=0;
    while(Q--){
        //cout << T.length() << "\n";
        char c;
        cin >> c;
        if(c=='I'){
            curI++;
            curI%=2;
            curR=(T.length()-curR)%T.length();
            //if(index==0) ans++;
        }
        else if(c=='R'){
            int a;
            cin >> a;
            curR=(curR+a)%T.length();
        }
        else{
            int a;
            cin >> a;
            curR=(curR+T.length()*(ll)(a/T.length()+1)-a)%T.length();
        }
        //cout << "curI : " << curI << " curR : " << curR << "\n";
        //cout << M[{curI, curR}] << "\n";
        if(M.find({curI, curR})!=M.end()) ans+=M[{curI, curR}];
        if(index!=-1){
            pair<int, int> temp;
            temp.first=(curI+1)%2;
            temp.second=(T.length()-curR+T.length()-index)%T.length();
            //cout << temp.first << " " << temp.second << "\n";
            if(M.find(temp)!=M.end()) ans+=M[temp];
            //cout << M[temp] << "\n";
        }
        //cout << "ans : " << ans << "\n";
        //if(curI==0&&curR==0) ans++;
        M[{curI, curR}]++;
    }
    //if(index==0&&sublength>1) ans*=2;
    cout << ans;
    return 0;
}