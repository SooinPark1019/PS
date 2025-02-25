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
const ll mod = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
개 어려운데

그래프가 나뉜다는 것의 의미를 생각해보자
어떤 경계를 기준으로 왼쪽에서의 최솟값이 오른쪽에서의 최댓값보다 크다면, 그 곳을 기준으로 그래프는 나뉘게 된다

왼쪽부터 값을 정해나가는 DP일 것 같긴 한데
애초부터 각 연결요소들의 구간, 최대/최소를 구해놓자
각 -1들에 대해서 DP[현재 위치][왼쪽에 있는 연결요소 개수]

다시
-1들을 각각의 연결요소라고 생각해버리자
그러면 DP[현재 위치][왼쪽에 있는 연결요소 개수]=경우의 수로 DP식을 세웠을 때
각 연결요소들의 최댓값에 대해서 이 값보다 작은 애가 나올 때까지로 점프를 뛸 수 있다
최댓값은 -1을 제외하면 연결요소 사이에는 감소할 것이다
이분탐색으로 어디로 점프할지 알 수 있고
이거를 채워나가면 될 것 같은데
여기서 연결요소 안에 들어가 있는 -1들은 어떻게 처리하지?
점프하면서 지나치는 -1들의 개수를 세서 M^개수만큼 경우의 수에 곱해주면 된다

각 연결요소마다 -1의 개수로 하고
이걸 기준으로 DP를 한다고 생각을 해버리자
최댓값을 정하면
최댓값^개수-(최댓값-1)^개수

맨 끝에 나오는 -1 어떻게 처리하지?

다시 생각해야 하나
생각해보니까 왼쪽 거를 흡수하기도 해서

연결요소 별로 나눠서 생각하는 게 맞는 거 같은데

DP[현재 연결요소의 인덱스][왼쪽 연결요소의 개수]로 놓고
왼쪽으로 합쳐지는 경우를 왼쪽에서 계산해버리는 식으로 생각하자.

연결요소들을 최대/최소의 구간으로 표현했을 때
지금까지의 최솟값보다 오른쪽에서 더 큰 게 없으면 연결요소가 나누어진다

연결요소가 한 개일 경우의 수는 두 양 끝점이 합쳐지는 경우

이렇게 접근하면 안될 것 같고
DP를 어떻게 세워야 되지?

더블 카운팅?
각 연결요소 별로 합쳐지는 경우의 수를 세가지고
이걸로 비비는 건가?

서로 인접한 애들끼리 합쳐지지 않는 경우의 수?
*/

vector<int> graph[100005];
int level[100005];
vector<pii> backedge[100005];
int par[100005];
vector<int> A[100005];
vector<int> B[100005];

void dfs(int curnode){
    //cout << curnode << " " << level[curnode] << "\n";
    for(auto nxt : graph[curnode]){
        if(nxt==par[curnode]) continue;
        if(level[nxt]==-1){
            level[nxt]=level[curnode]+1;
            par[nxt]=curnode;
            dfs(nxt);
        }
        else if(level[nxt]<level[curnode]){
            //cout << "curnode : " << curnode << " nxt : " << nxt << endl;
            //cout << level[curnode]-level[nxt] << "\n";
            backedge[level[curnode]-level[nxt]].push_back({curnode, nxt});
            A[curnode].push_back(nxt);
            B[nxt].push_back(curnode);
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for(int i=0; i<2*N-3; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    memset(level, -1, sizeof(level));

    for(int i=1; i<=N; i++){
        if(level[i]==-1){
            level[i]=0;
            dfs(i);
        }
    }

    int flag=0;
    for(int i=2; i<=N; i++){
        /*for(auto p : backedge[i]){
            cout << p.first << " " << p.second << "\n";
        }
        cout << "\n";*/
        if(backedge[i].size()>=2){
            flag=1;
            cout << i+1 << "\n";
            for(int j=0; j<2; j++){
                int a=backedge[i][j].first;
                int b=backedge[i][j].second;
                while(a!=b){
                    cout << a << " ";
                    a=par[a];
                }
                cout << b;
                cout << "\n";
            }
            break;
        }
    }

    if(flag==0){
        for(int i=1; i<=N; i++){
            if(A[i].size()>=2){
                flag=1;
                int a=A[i][0];
                int b=A[i][1];
                int sz=abs(level[a]-level[b])+1;
                cout << sz+1 << "\n";
                //cout << a << " " << b << "\n";
                if(level[a]<level[b]) swap(a, b);
                while(a!=b){
                    cout << a << " ";
                    a=par[a];
                }
                cout << b << " " << i << "\n";
                a=backedge[sz][0].first;
                b=backedge[sz][0].second;
                //cout << a << " " << b << "\n";
                while(a!=b){
                    cout << a << " ";
                    a=par[a];
                }
                cout << b;
                cout << "\n";
                break;
            }
        }
        if(flag==0){
            for(int i=1; i<=N; i++){
                if(B[i].size()>=2){
                    int a=B[i][0];
                    int b=B[i][1];
                    if(level[a]<level[b]) swap(a, b);
                    int sz=abs(level[a]-level[b])+1;
                    cout << sz+1 << "\n";
                    while(a!=b){
                        cout << a << " ";
                        a=par[a]; 
                    }
                    cout << b << " " << i << "\n";
                    a=backedge[sz][0].first;
                    b=backedge[sz][0].second;
                    //cout << a << " " << b << "\n";
                    while(a!=b){
                        cout << a << " ";
                        a=par[a];
                    }
                    cout << b;
                    cout << "\n";
                    break;
                }
            }
        }
    }

    return 0;
}
