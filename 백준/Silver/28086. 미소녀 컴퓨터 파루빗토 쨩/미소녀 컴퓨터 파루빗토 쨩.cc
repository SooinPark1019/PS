#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
/*#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")*/
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

using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;
    cin >> S;
    int flag1=0;
    int flag2=0;
    if(S[0]=='-'){
        flag1++;
        S=S.substr(1, S.length()-1);
    }
    int opindex;
    for(int i=0; i<S.length(); i++){
        if(S[i]=='+'||S[i]=='-'||S[i]=='*'||S[i]=='/'){
            opindex=i;
            break;
        }
    }
    string A=S.substr(0, opindex);
    char c=S[opindex];
    string B=S.substr(opindex+1, S.length()-1-opindex);
    if(B[0]=='-'){
        flag2++;
        B=B.substr(1, B.length()-1);
    }
    ll a10=0;
    ll b10=0;
    ll adecimal=1;
    ll bdecimal=1;
    for(int i=A.length()-1; i>=0; i--){
        a10+=(A[i]-'0')*adecimal;
        adecimal*=8;
    }
    for(int i=B.length()-1; i>=0; i--){
        b10+=(B[i]-'0')*bdecimal;
        bdecimal*=8;
    }
    if(flag1==1) a10*=-1;
    if(flag2==1) b10*=-1;
    ll ans10;
    if(c=='+'){
        ans10=a10+b10;
    }
    else if(c=='-'){
        ans10=a10-b10;
    }
    else if(c=='*'){
        ans10=a10*b10;
    }
    else{
        if(b10==0){
            cout << "invalid";
            return 0;
        }
        ans10=floor((double)a10/b10);
    }
    int flag=0;
    if(ans10<0){
        flag=1;
        ans10*=-1;
    }
    ll ans8=0;
    ll decimal=1;
    while(ans10>0){
        ans8+=(ans10%8)*decimal;
        ans10/=8;
        decimal*=10;
    }
    if(flag==1) ans8*=-1;
    cout << ans8;
}
