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
*/

double cal_dis(int x0, int x1, int y0, int y1){
    return sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1));
}

vector<int> graph[1005];
vector<array<int, 3>> V;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        int x, y, a;
        cin >> x >> y >> a;
        V.push_back({x, y, a});
    }

    int flag=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i==j) continue;
            double dis = cal_dis(V[i][0], V[j][0], V[i][1], V[j][1]);
            if(abs(dis-(V[i][2]+V[j][2]))<EPS){
                graph[i].push_back(j);
            }
        }
    }
    int ans=0;
    for(int i=0; i<N; i++){
        vector<int> color(N, -1);
        queue<int> Q;
        int color0=0, color1=0;
        Q.push(i);
        color0++;
        color[i]=0;
        int flag=0;
        while(!Q.empty()){
            int x=Q.front();
            //cout << "x : " << x << "\n";
            Q.pop();
            for(auto j : graph[x]){
                //cout << "j : " << j << " color[j] : " << color[j] << "\n";
                if(color[j]==-1){
                    color[j]=(color[x]^1);
                    if(color[j]) color1++;
                    else color0++;
                    Q.push(j);
                }
                else if(color[x]==color[j]){
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
        //cout << flag << " " << color0 << " " << color1 << "\n";
        if(flag||color0==color1) continue;
        ans=1;
        break;
    }

    if(ans) cout << "YES";
    else cout << "NO";

    return 0;
}
