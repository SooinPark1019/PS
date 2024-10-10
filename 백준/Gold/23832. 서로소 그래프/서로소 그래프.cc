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

int fastmul(int a, int b){
    if(b==0) return 1;
    else if(b==1) return a;
    else if(b%2==0){
        int temp=fastmul(a, b/2);
        return temp*temp%mod;
    }
    return a*fastmul(a, b-1)%mod;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> prime;
    vector<int> isprime(N+1);
    for(int i=2; i*i<=N; i++){
        if(isprime[i]!=0) continue;
        for(int j=2; j*i<=N; j++){
            isprime[j*i]=1;
        }
    }

    for(int i=2; i<=N; i++){
        if(isprime[i]==0) prime.push_back(i);
    }
    vector<int> ans(N+1);
    for(int i=2; i<=N; i++){
        if(isprime[i]==0) ans[i]=i-1;
        else{
            int temp=1;
            int a=i;
            for(auto j : prime){
                if(j*j>i) continue;
                int cnt=0;
                while(a%j==0){
                    cnt++;
                    a/=j;
                }
                if(cnt>0) temp*=fastmul(j, cnt)-fastmul(j, cnt-1);
            }
            if(a>1) temp*=a-1;
            ans[i]=temp;
        }
    }
    int res=0;
    for(int i=2; i<=N; i++){
        //cout << ans[i] << " ";
        res+=ans[i];
    }
    //cout << "\n";
    cout << res;
    
    return 0;
}