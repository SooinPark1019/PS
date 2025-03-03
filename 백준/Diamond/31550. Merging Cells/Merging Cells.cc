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
//#define sz(x) (int)x.size()
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#define int long long

using namespace std;

//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
/*#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>//이걸 코드의 윗부분에 추가
void m_erase(ordered_set &OS, int val){
    int index = OS.order_of_key(val);
    ordered_set::iterator it = OS.find_by_order(index);
    if(*it == val) OS.erase(it);
}*/
//다른 건 통상적인 PBDS처럼 사용하면 되지만 erase는 반드시!!! 이 함수를 통해서만 해야 함
//m_erase(OS, 지울 원소)처럼 사용하면 된다. 꼭 주의하자.
//얘네 쓰려면 define int long long 꺼라.

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
ll fac[5005];
ll inv_fac[5005];
ll DP[5005][5005];
int V[5005];
ll prefix[5005];
ll temp1[5005];
ll temp2[5005];
queue<pair<ll, ll>> Q1[5005], Q2[5005];
int inv[5005];
ll fastmul(int a, int b){
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0){
        ll temp=fastmul(a, b/2);
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
    fac[0]=1;
    for(int i=1; i<=N; i++){
        fac[i]=fac[i-1]*i%mod;
    }
    inv_fac[N]=fastmul(fac[N], mod-2);
    for(int i=N-1; i>=0; i--){
        inv_fac[i]=inv_fac[i+1]*(i+1)%mod;
    }

    for(int i=0; i<N; i++){
        cin >> V[i];
        prefix[i]=V[i];
        if(i>0) prefix[i]+=prefix[i-1];
    }

    for(int i=1; i<N; i++){
        inv[i]=fastmul(i, mod-2);
    }

    DP[0][N-1]=1;

    for(int sz=N-1; sz>=0; sz--){
        for(int st=0; st+sz<N; st++){
            //cout << "l : " << st << " r : " << st+sz << "\n";
            while(!Q1[st+sz].empty()){
                int a=prefix[st+sz];
                if(st>0) a-=prefix[st-1];
                int b=prefix[st-1];
                if(Q1[st+sz].front().second>0) b-=prefix[Q1[st+sz].front().second-1];
                if(a>=b) break;
                temp1[st+sz]=(temp1[st+sz]-Q1[st+sz].front().first+mod)%mod;
                Q1[st+sz].pop();
            }
            while(!Q2[st].empty()){
                int a=prefix[st+sz];
                if(st>0) a-=prefix[st-1];
                int b=prefix[Q2[st].front().second]-prefix[st+sz];
                if(a>b) break;
                temp2[st]=(temp2[st]-Q2[st].front().first+mod)%mod;
                Q2[st].pop();
            }
            DP[st][st+sz]+=temp1[st+sz];
            DP[st][st+sz]%=mod;
            DP[st][st+sz]+=temp2[st];
            DP[st][st+sz]%=mod;
            ll a=DP[st][st+sz]*inv[sz]%mod;
            temp1[st+sz]+=a;
            //temp1[st+sz]%=mod;
            Q1[st+sz].push({a, st});
            temp2[st]+=a;
            //temp2[st]%=mod;
            Q2[st].push({a, st+sz});
            //cout << DP[st][sz] << "\n";
        }
    }

    for(int i=0; i<N; i++){
        cout << DP[i][i] << "\n";
    }

    return 0;
}