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

/*
사이클
방향그래프를 생각해보자

나올 수 있는 모든 사이클의 크기를 생각을 해야 하는데
길이가 2인 사이클이 존재한다면 2의 배수는 모두 안된다
이런 식으로 가야 하나

DP[i][j]=i번째 정점을 j번의 이동으로 갈 수 있으면 1, 아니면 0
*/

vector<int> prime;

void filldivisor(int x, vector<int>& divisors){
    for(auto i : prime){
        if(x%i) continue;
        divisors.push_back(i);
        while(x%i==0){
            x/=i;
        }
    }
    if(x!=1) divisors.push_back(x);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, A, B;
    cin >> N >> A >> B;

    for(int i=2; i<=10000; i++){
        int flag=0;
        for(int j=2; j*j<=i; j++){
            if(i%j==0){
                flag=1;
                break;
            }
        }
        if(flag==0) prime.push_back(i);
    }

    vector<int> divisors;
    vector<int> V;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        V.push_back(a);
    }
    filldivisor(V[0]-1, divisors);
    filldivisor(V[0], divisors);
    filldivisor(V[0]+1, divisors);
    filldivisor(V[N-1]-1, divisors);
    filldivisor(V[N-1], divisors);
    filldivisor(V[N-1], divisors);

    sort(all(divisors));
    divisors.erase(unique(all(divisors)), divisors.end());

    int ans=1e18;
    for(auto i : divisors){
        //cout << i << endl;
        vector<vector<int>> DP(N+1, vector<int>(3, 1e18));
        DP[0][0]=0;
        for(int j=0; j<N; j++){
            //cout << j << endl;
            if(V[j]%i==0){
                DP[j+1][0]=min(DP[j+1][0], DP[j][0]);
                DP[j+1][2]=min({DP[j+1][2], DP[j][1], DP[j][2]});
            }
            if((V[j]-1)%i==0||(V[j]+1)%i==0){
                DP[j+1][0]=min(DP[j+1][0], DP[j][0]+B);
                DP[j+1][2]=min({DP[j+1][2], DP[j][1]+B, DP[j][2]+B});
            }
            DP[j+1][1]=min({DP[j+1][1], DP[j][0]+A, DP[j][1]+A});
        }
        ans=min({ans, DP[N][0], DP[N][1], DP[N][2]});
        //cout << ans << endl;
    }

    cout << ans;
    
    return 0;
}