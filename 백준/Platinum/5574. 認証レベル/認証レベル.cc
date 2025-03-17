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

struct st{
    int x, y, val;
};

struct comp{
    bool operator()(st A, st B){
        return B.val<A.val;
    }
};

int val1[250005];
int val2[250005];
int vis1[505][505];
int arr1[505][505];
int dx[4]={-1, 1, 0, 0};
int dy[4]={0, 0, -1, 1};
void fill_val(int val[250005]){
    int W1, H1, x1, y1;
    cin >> W1 >> H1 >> y1 >> x1;
    for(int i=1; i<=H1; i++){
        for(int j=1; j<=W1; j++){
            cin >> arr1[i][j];
            //cout << "i : " << i << " j : " << j << " arr : " << arr1[i][j] << "\n";
        }
    }
    priority_queue<st, vector<st>, comp> PQ1;
    PQ1.push({x1, y1, arr1[x1][y1]});
    //cout << x1 << " " << y1 << " " << arr1[x1][y1] << "\n";
    vis1[x1][y1]=1;
    int curmax=0;
    int curcnt=0;
    while(!PQ1.empty()){
        curcnt++;
        curmax=max(curmax, PQ1.top().val);
        //cout << "curmax : " << curmax << " curcnt : " << curcnt << "\n";
        val[curcnt]=curmax;
        int x=PQ1.top().x;
        int y=PQ1.top().y;
        //cout << "x : " << x << " y : " << y << "\n";
        PQ1.pop();
        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<=0||nx>H1||ny<=0||ny>W1||vis1[nx][ny]) continue;
            PQ1.push({nx, ny, arr1[nx][ny]});
            vis1[nx][ny]=1;
        }
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int R;
    cin >> R;

    for(int i=0; i<=250000; i++){
        val1[i]=1e18;
        val2[i]=1e18;
    }

    val1[0]=0;
    val2[0]=0;

    fill_val(val1);
    memset(arr1, 0, sizeof(arr1));
    memset(vis1, 0, sizeof(vis1));
    fill_val(val2);

    /*for(int i=0; i<=5; i++){
        cout << val1[i] << " " << val2[i] << "\n";
    }*/

    int ans=1e18;
    for(int i=0; i<=250000; i++){
        if(i+250000<R) continue;
        ans=min(ans, val1[i]+val2[R-i]);
    }

    cout << ans;

    return 0;
}
