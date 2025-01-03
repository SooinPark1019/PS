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
#define int long long
#define sz(x) (int)x.size()

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
typedef complex<double> cpx;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 1e9+7;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
먼저 각 간선들에 대해 간선의 양 끝점과 모두 인접한 정점이 존재하는지를 검사한다

존재한다면 해당 세 점을 처음의 삼각형으로 생각하고 해당 삼각형 내부에서 지역을 생성한다

여기서 대충 간선 세 개씩 사이클 안 생기게 잘 고르고
이후 얘네랑 인접한 점들 중에서 두번 이상 등장하는 놈들을 고른다

그렇게 정점하나씩 추가하면서 인접한 간선 하나씩을 트리에 추가하고 이거를 반복
*/

vector<int> graph[100005];
int fac[100005];
int inv_fac[100005];
int DP[100005];
int depth[100005];
int depthcnt[100005];

int fastmul(int a, int b){
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0){
        int temp=fastmul(a, b/2);
        return temp*temp%mod;
    }
    return a*fastmul(a, b-1)%mod;
}

int bino(int a, int b){
    if(b>a) return 0;
    return fac[a]*inv_fac[a-b]%mod*inv_fac[b]%mod;
}

void sol(int curnode, int par){
    //cout << curnode << "\n";
    DP[curnode]=1;
    for(auto i : graph[curnode]){
        if(i==par) continue;
        depth[i]=depth[curnode]+1;
        depthcnt[depth[i]]++;
        sol(i, curnode);
        DP[curnode]+=DP[i];
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, K;
    cin >> N >> K;

    fac[0]=1;
    for(int i=1; i<=N; i++){
        fac[i]=fac[i-1]*i%mod;
    }
    inv_fac[N]=fastmul(fac[N], mod-2);
    for(int i=N-1; i>=0; i--){
        //cout << inv_fac[i+1] << "\n";
        inv_fac[i]=inv_fac[i+1]*(i+1)%mod;
    }

    for(int i=0; i<N-1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    sol(1, -1);

    int ans=0;

    //for(int i=1; i<=N; i++) cout << depth[i] << " ";
    //cout << "\n";

    for(int i=2; i<=N; i++){
        ans+=2*(bino(N-1, K)-bino(N-1-DP[i], K)+mod)%mod;
        ans%=mod;
        //cout << ans << "\n";
    }

    //cout << ans << "\n";

    int prefixsum=0;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=depthcnt[i]; j++){
            if(K-j>prefixsum) continue;
            int temp=i*bino(depthcnt[i], j)%mod;
            temp*=bino(prefixsum, K-j)%mod;
            temp%=mod;
            ans-=temp;
            ans+=mod;
            ans%=mod;
        }
        prefixsum+=depthcnt[i];
    }

    cout << ans;
    
    return 0;
}
