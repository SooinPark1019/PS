#include <ext/rope>
#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
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
const int MAXN = (1<<20)+5;
const double PI = acos(-1);

/*
반드시 앞에 오는게 뒤에 오는거의 submask여야 함
더하는 게 아니라 곱한다?
일리가 있는 거 같은데

해야 하는 걸 다시 생각
DP2[i]=i의 서브마스크로 끝나는 애들의 개수
DP3[i][j]=DP2[state]의 합, state는 SOS DP에 맞게 생각
*/

ll DP1[100005];
ll DP2[MAXN];
ll DP3[MAXN][25];
int cnt[MAXN];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    DP1[1]=1;
    for(int i=1; i<=N; i++){
        DP1[i+1]=(i+1)*(DP1[i]+1)%mod;
    }

    vector<string> V;
    for(int i=0; i<M; i++){
        string S;
        cin >> S;
        V.push_back(S);
    }

    for(int j=0; j<N; j++){
        int a=0;
        for(int i=0; i<M; i++){
            if(V[i][j]=='H') a+=(1<<i);
        }
        cnt[a]++;
    }
    for(int i=0; i<(1<<M); i++){
        DP2[i]=1;
        for(int j=0; j<M; j++){
            if((i&(1<<j))){
                DP2[i]+=DP3[(i^(1<<j))][j];
                DP2[i]%=mod;
            } 
        }
        DP2[i]*=DP1[cnt[i]];
        DP2[i]%=mod;
        DP3[i][0]=DP2[i];
        for(int j=0; j<M; j++){
            DP3[i][j+1]+=DP3[i][j];
            if(i&(1<<j)){
                DP3[i][j+1]+=DP3[(i^(1<<j))][j];
                DP3[i][j+1]%=mod;
            }
        }
    }
    int ans=0;
    for(int i=0; i<(1<<M); i++){
        ans+=DP2[i];
        ans%=mod;
    }

    cout << ans;
    return 0;
}
