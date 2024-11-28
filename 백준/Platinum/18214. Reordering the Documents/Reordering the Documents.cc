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
DP[i]]=i번째 가로줄까지 먹는 비용?

삼각형은 겹치지 않는 게 최선
각 x좌표에 대해서 삼각형으로 먹을 가장 아래쪽의 줄을 선택한다?

그러면 N^2


*/
vector<int> graph[5005];
int arr[5005];
int check[5005];
pii A[5005];
int DP[5005][5005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<i; j++){
            if(arr[j]>arr[i]){
                graph[j].push_back(i);
                graph[i].push_back(j);
            }
        }
    }
    int flag=0;
    for(int i=0; i<N; i++){
        if(check[i]) continue;
        int onecnt=0;
        int twocnt=0;
        onecnt++;
        check[i]=1;
        queue<int> Q;
        Q.push(i);
        while(!Q.empty()){
            int x=Q.front();
            Q.pop();
            for(auto j : graph[x]){
                if(!check[j]){
                    check[j]=3-check[x];
                    if(check[j]==1) onecnt++;
                    else twocnt++;
                    Q.push(j);
                }
                else if(check[j]!=3-check[x]){
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1) break;
        A[i]={onecnt, twocnt};
    }
    if(flag==1){
        cout << 0;
    }
    else{
        DP[0][0]=1;
        for(int i=0; i<N; i++){
            if(A[i].first==0&&A[i].second==0) continue;
            for(int j=0; j<=i; j++){
                DP[j+A[i].first][i-j+A[i].second]+=DP[j][i-j];
                DP[j+A[i].first][i-j+A[i].second]%=mod;
                DP[j+A[i].second][i-j+A[i].first]+=DP[j][i-j];
                DP[j+A[i].second][i-j+A[i].first]%=mod;
            }
        }
        int ans=0;
        for(int i=0; i<=N; i++){
            if(i<=M&&N-i<=M){
                ans+=DP[i][N-i];
                ans%=mod;
            }
        }
        cout << ans;
    }

    return 0;
}
