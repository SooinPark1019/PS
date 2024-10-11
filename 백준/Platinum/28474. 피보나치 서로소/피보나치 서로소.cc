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
const int MAXN = (1<<18)+5;
const int D = 20;

int check[100005];
int fastmul(int a, int b){
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0){
        int temp=fastmul(a, b/2);
        return temp*temp;
    }
    return a*fastmul(a, b-1);
}

int phi(int N){
    if(N==1) return 0;
    else{
        int ret=1;
        int temp=N;
        for(int i=2; i*i<=N; i++){
            if(check[i]!=0) continue;
            int cnt=0;
            while(temp%i==0){
                cnt++;
                temp/=i;
            }
            if(cnt>0) ret*=(i-1)*fastmul(i, cnt-1);
        }
        if(temp>1) ret*=temp-1;
        return ret;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    for(int i=2; i*i<=100000; i++){
        if(check[i]!=0) continue;
        for(int j=2; j*i<=100000; j++){
            check[j*i]=1;
        }
    }
    while(TC--){
        int N;
        cin >> N;
        if(N%2==0) cout << phi(N)+phi(N/2) << "\n";
        else cout << phi(N) << "\n";
    }
    return 0;
}