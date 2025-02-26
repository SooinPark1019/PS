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
#define int long long

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

struct UnionFind{
    vector<int> p;
    UnionFind(int N){
        p.resize(N, 0);
        for(int i=0; i<N; i++) p[i]=i;
    }
    int findset(int i){
        return (p[i]==i) ? i : p[i]=findset(p[i]);
    }
    void unionset(int a, int b){
        if(findset(a)==findset(b)) return;
        int x=findset(a);
        int y=findset(b);
        p[x]=y;
    }
};

int arr[505][505];
vector<pii> nodes[1000005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int H, W, Q;
    cin >> H >> W >> Q;

    int maxval=0;

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin >> arr[i][j];
            nodes[arr[i][j]].push_back({i, j});
            maxval=max(maxval, arr[i][j]);
        }
    }

    vector<array<int, 4>> queries;
    for(int i=0; i<Q; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        queries.push_back({x1-1, y1-1, x2-1, y2-1});
    }

    vector<int> left(Q, 0);
    vector<int> right(Q, maxval);
    vector<int> ans(Q, 1e18);

    int dx[4]={1, -1, 0, 0};
    int dy[4]={0, 0, 1, -1};

    while(1){
        int flag=0;
        UnionFind UF(H*W+5);
        vector<vector<int>> G(maxval+5); 
        for(int i=0; i<Q; i++){
            if(left[i]<=right[i]){
                flag=1;
                int mid=(left[i]+right[i])>>1;
                G[mid].push_back(i);
            }
        }
        if(flag==0) break;
        for(int i=0; i<=maxval; i++){
            //cout << "i : " << i << endl;
            for(auto j : nodes[i]){
                int x=j.first;
                int y=j.second;
                //cout << "x : " << x << " y : " << y << endl;
                for(int k=0; k<4; k++){
                    int nx=x+dx[k];
                    int ny=y+dy[k];
                    if(nx>=H||nx<0||ny>=W||ny<0||arr[nx][ny]>arr[x][y]) continue;
                    //cout << "nx : " << nx << " ny : " << ny << endl;
                    UF.unionset(x*W+y, nx*W+ny);
                }
            }
            for(auto j : G[i]){
                int x1=queries[j][0];
                int y1=queries[j][1];
                int x2=queries[j][2];
                int y2=queries[j][3];
                //cout << "x1 : " << x1 << " y1 : " << y1 << " x2 : " << x2 << " y2 : " << y2 << endl; 
                if(UF.findset(x1*W+y1)==UF.findset(x2*W+y2)){
                    ans[j]=min(ans[j], i);
                    right[j]=i-1;
                }
                else left[j]=i+1;
            }
        }
    }

    for(int i=0; i<Q; i++){
        if(queries[i][0]==queries[i][2]&&queries[i][1]==queries[i][3]) cout << arr[queries[i][0]][queries[i][1]] << "\n";
        else cout << ans[i] << "\n";
    }

    return 0;
}
