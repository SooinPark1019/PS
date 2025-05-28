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
const ll mod = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);
const int FLAG_DEBUG = 0;

/*
*/
int left_nearest[4005][4005], right_nearest[4005][4005], up_nearest[4005][4005], down_nearest[4005][4005], tree[4005][4005];
int H, W, L, P;
void fill_left(){
    for(int i=1; i<=H; i++){
        int last_tree=0;
        for(int j=1; j<=W; j++){
            if(tree[i][j]) last_tree=j;
            left_nearest[i][j]=abs(j-last_tree);
        }
    }
}
void fill_right(){
    for(int i=1; i<=H; i++){
        int last_tree=W+1;
        for(int j=W; j>=1; j--){
            if(tree[i][j]) last_tree=j;
            right_nearest[i][j]=abs(j-last_tree);
        }
    }
}
void fill_up(){
    for(int j=1; j<=W; j++){
        int last_tree=0;
        for(int i=1; i<=H; i++){
            if(tree[i][j]) last_tree=i;
            up_nearest[i][j]=abs(i-last_tree);
        }
    }
}
void fill_down(){
    for(int j=1; j<=W; j++){
        int last_tree=H+1;
        for(int i=H; i>=1; i--){
            if(tree[i][j]) last_tree=i;
            down_nearest[i][j]=abs(i-last_tree);
        }
    }
}
void print_nearest(int arr[4005][4005]){
    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}
vector<int> Fenwick;
void update(int index, int value){
    while(index<=4000){
        Fenwick[index]+=value;
        index+=index&(-index);
    }
}
int query(int index){
    int ret=0;
    while(index>0){
        ret+=Fenwick[index];
        index-=index&(-index);
    }
    return ret;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> H >> W >> L >> P;

    for(int i=0; i<P; i++){
        int x, y;
        cin >> x >> y;
        tree[x][y]=1;
    }

    fill_left();
    fill_right();
    fill_up();
    fill_down();

    if(FLAG_DEBUG){
        print_nearest(left_nearest);
        print_nearest(right_nearest);
        print_nearest(up_nearest);
        print_nearest(down_nearest);
        cout << endl;
    }
    ll ans=0;
    for(int k=-H+1; k<=W-1; k++){
        //cout << "k : " << k << "\n";
        Fenwick.clear();
        Fenwick.resize(4005, 0);
        vector<pii> temp;
        for(int i=1; i<=H; i++){
            int j=i+k;
            //cout << "i : " << i << " j : " << j << "\n";
            if(j<=0||j>W) continue;
            temp.push_back({j-min(left_nearest[i][j], up_nearest[i][j]), j});
            //cout << "temp.back : " << temp.back().first << " " << temp.back().second << "\n";
        }
        sort(all(temp));
        int curpointer=0;
        for(int i=1; i<=H; i++){
            int j=i+k;
            //cout << "i : " << i << " j : " << j << "\n";
            if(j<=0||j>W) continue;
            while(curpointer<temp.size()&&temp[curpointer].first<j){
                //cout << "add : " << temp[curpointer].second << "\n";
                update(temp[curpointer].second, 1);
                curpointer++;
            }
            int left=j+L-2;
            int right=min(j+min(right_nearest[i][j], down_nearest[i][j])-1, 4000);
            if(left>=right) continue;
            //cout << "left : " << left << " right : " << right << "\n";
            ans+=query(right)-query(left);
            //cout << "ans : " << ans << "\n";
        }
    }

    cout << ans;

    return 0;
}