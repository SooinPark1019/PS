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
1이 쓰여 있는 칸은 홀수번
0이 쓰여 있는 칸은 짝수번 뒤집어야 함

어떤 칸을 뒤집으면
i+j가 같은 칸 또는 i-j가 같은 칸을 모두 뒤집게 됨

i+j=i+j
i-j=N+M+max(N+M)+i-j
*/

int arr[1005][1005];
int weight[20005];
vector<int> graph[20005];
int N, M;
int sol(int parity){
    //cout << "parity : " << parity << "\n";
    for(int i=0; i<=20000; i++){
        graph[i].clear();
    }
    int ans=1e18;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if((i+j)%2==parity){
                graph[i+j].push_back(2*N+2*M+i-j);
                graph[2*N+2*M+i-j].push_back(i+j);
            }
        }
    }
    for(int i=0; i<2; i++){
        int temp=0;
        memset(weight, 0, sizeof(weight));
        queue<int> Q;
        vector<int> vis(10005);
        
        int flag=0;

        for(int x=0; x<N; x++){
            for(int y=0; y<M; y++){
                if((x+y)%2==parity&&vis[x+y]==0){
                    Q.push(x+y);
                    weight[x+y]=i;
                    temp+=i;
                    vis[x+y]=1;
                    while(!Q.empty()){
                        int x=Q.front();
                        //cout << "x : " << x << " weight : " << weight[x] << "\n";
                        Q.pop();
                        for(auto j : graph[x]){
                            //cout << "j : " << j << "\n";
                            if(vis[j]!=0) continue;
                            int plus=min(x, j);
                            int minus=max(x, j)-2*N-2*M;
                            int nx=(plus+minus)/2;
                            int ny=(plus-minus)/2;
                            assert(nx>=0&&nx<N&&ny>=0&&ny<M&&(nx+ny)%2==parity);
                            //cout << nx << " " << ny << "\n";
                            weight[j]=(weight[x]+arr[nx][ny])%2;
                            temp+=(weight[x]+arr[nx][ny])%2;
                            //cout << "temp : " << temp << "\n";
                            vis[j]=1;
                            Q.push(j);
                        }
                    }
                }
            }
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if((i+j)%2==parity&&(arr[i][j]+weight[i+j]+weight[2*N+2*M+i-j])%2){
                    flag=1;
                    break;
                }
            }
            if(flag==1) break;
        }
        if(flag==0) ans=min(ans, temp);
        //cout << "ans : " << ans << "\n";
    }
    if(ans==1e18) return -1;
    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> arr[i][j];
        }
    }

    int a=sol(0);
    int b=sol(1);
    if(a<0||b<0) cout << -1;
    else cout << a+b;

    return 0;
}
