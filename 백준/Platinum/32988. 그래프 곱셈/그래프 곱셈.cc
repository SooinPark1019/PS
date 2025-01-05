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
vector<int> graphA[200005];
vector<int> graphB[200005];
int disA[200005][2];
int disB[200005][2];
void input_and_calc_dis(vector<int> graph[200005], int dis[200005][2]){
    int N, M;
    cin >> N >> M;
    for(int i=0; i<=200000; i++){
        for(int j=0; j<2; j++){
            dis[i][j]=LNF;
        }
    }
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dis[1][0]=0;
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    PQ.push({0, 1});
    while(!PQ.empty()){
        int x=PQ.top().second;
        int cur_cost=PQ.top().first;
        int parity=cur_cost%2;
        PQ.pop();
        if(dis[x][parity]!=cur_cost) continue;
        for(auto i : graph[x]){
            if(dis[i][1-parity]>cur_cost+1){
                dis[i][1-parity]=cur_cost+1;
                PQ.push({dis[i][1-parity], i});
            }
        }
    }
    /*for(int i=1; i<=N; i++){
        cout << dis[i][0] << " " << dis[i][1] << "\n";
    }
    cout << "\n";*/
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input_and_calc_dis(graphA, disA);
    input_and_calc_dis(graphB, disB);
    //cout << "!" << endl;

    int Q;
    cin >> Q;
    while(Q--){
        int type, a, b;
        cin >> type >> a >> b;
        if(type==1){
            int ans=min(disA[a][0], disA[a][1])+min(disB[b][0], disB[b][1]);
            if(ans>=INF) cout << -1 << "\n";
            else cout << ans << "\n";
        }
        else if(type==2){
            if(graphA[1].size()==0||graphB[1].size()==0){
                if(a==1&&b==1) cout << 0 << "\n";
                else cout << -1 << "\n";
                continue;
            }
            int ans=min(max(disA[a][0], disB[b][0]), max(disA[a][1], disB[b][1]));
            if(ans>=INF) cout << -1 << "\n";
            else cout << ans << "\n";
        }
        else{
            int ans=max(min(disA[a][0], disA[a][1]), min(disB[b][0], disB[b][1]));
            if(ans>=INF) cout << -1 << "\n";
            else cout << ans << "\n";
        }
    }

    return 0;
}
