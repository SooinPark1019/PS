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
#define zip(v) sort(all(v)); v.erase(unique(all(v)), v.end());
#define int long long
//#define sz(x) (int)x.size()

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
typedef complex<double> cpx;
//typedef __int128 i128;
typedef long double ld;
typedef pair<double, int> pdl;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 1e9+7;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
DP[i]=첫번째 재료의 가치가 i일 때 두번째 재료의 가능한 최대 가치

두 차원 모두 양수인 거는 당연히 그대로 합치고
그렇지 않을 경우 취할 차원을 선택

나머지는 취할 차원만 취하거나 아니면 둘다 취해야 함
*/

pair<int,pair<int,int>> xGCD(int a, int b) {    // it returns {g, {x,y}}, ax+by=g
    if(b == 0) return {a,{1,0}};
    pair<int,pair<int,int>> ret = xGCD(b, a%b);
    int g, x, y;
    g = ret.first;
    tie(x,y) = ret.second;
    return {g,{y,x-(a/b)*y}};   
}

int mod_inverse(int a, int mod) {
    auto res = xGCD(a,mod);
    if(res.first > 1) return -1;
    return (res.second.first + mod) % mod;
}

int fastmul(int a, int b, int mod){
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0){
        int temp=fastmul(a, b/2, mod);
        return temp*temp%mod;
    }
    return a*fastmul(a, b-1, mod)%mod;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    string S;
    
    cin >> S;

    int twocnt=0;
    while(K%2==0){
        twocnt++;
        K/=2;
    }

    vector<int> V(K);

    int cur=0;
    int ans=0;

    /*for(auto c : S){
        if(c=='0') ans++;
    }*/

    int zerostreak=0;
    int inverse=mod_inverse(2, K);
    queue<int> Q;

    for(int i=0; i<N; i++){
        cur<<=1;
        if(S[i]=='1'){
            zerostreak=0;
            cur++;
        }
        else{
            zerostreak++;
            if(twocnt>1) ans+=min(zerostreak, twocnt-1);
        }
        cur%=K;
        int a=cur*fastmul(inverse, i, K)%K;
        if(zerostreak>=twocnt){
            if(cur==0) ans++;
            ans+=V[a];
        }
        //cout << "a : " << a << "\n";
        Q.push(a);
        while(!Q.empty()&&Q.size()>=twocnt){
            V[Q.front()]++;
            Q.pop();
        }
        //cout << ans << "\n";
    }

    cout << ans;

    return 0;
}
