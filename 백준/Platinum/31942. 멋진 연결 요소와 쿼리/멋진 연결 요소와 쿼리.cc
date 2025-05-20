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
const ll mod = 998244353;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);
const int FLAG_DEBUG = 0;

/*
결국 적절한 구간합을 통해서 모든 항에 더해지는 횟수가 홀수가 되도록 해야 함

다 더한 상태에서 시작해서 적절히 빼준다?
역방향으로 생각해보는 것도 괜찮을 것 같다.
아 이건 오히려 좀 돌아가는 것 같네
잘못 생각했다 역방향으로 생각할 이유가 없음
*/

int p[100005];
vector<int> group[100005];
int color[100005];
int impossible[100005];
int flipped[100005];
int red_cnt[100005], blue_cnt[100005];

set<pii> red;
set<pii> blue;

int find_p(int a){
    return (p[a]==a) ? a : (p[a]=find_p(p[a]));
}

void rollback(int x){
    red.erase({red_cnt[x], x});
    blue.erase({blue_cnt[x], x});
}

void refresh(int x){
    red.insert({red_cnt[x], x});
    blue.insert({blue_cnt[x], x});
}

void merge_group(int x, int y, int flip){
    //cout << "flipped_x : " << flipped[x] << " flipped_y : " << flipped[y] << "\n";
    for(auto i : group[x]){
        group[y].push_back(i);
        color[i]^=flipped[x]^flipped[y]^flip;
        if(color[i]^flipped[y]) blue_cnt[y]++;
        else red_cnt[y]++;
    }
    if(x>y){
        p[x]=y;
        impossible[y]|=impossible[x];
    }
    else{
        p[y]=x;
        swap(group[x], group[y]);
        flipped[x]=flipped[y];
        impossible[x]|=impossible[y];
        red_cnt[x]=red_cnt[y];
        blue_cnt[x]=blue_cnt[y];
    }
}

void add_edge(int a, int b){
    //same_component
    if(find_p(a)==find_p(b)){
        if((color[a]^flipped[find_p(a)])==(color[b]^flipped[find_p(b)])){
            impossible[find_p(a)]=1;
            //cout << "impossible : " << find_p(a) << "\n";
            rollback(find_p(a));
        }
    }
    //different component
    else{
        int x=find_p(a);
        int y=find_p(b);
        if(group[x].size()>group[y].size()){
            swap(a, b);
            swap(x, y);
        }
        rollback(x);
        rollback(y);
        //At least one impossible
        if((impossible[x]||impossible[y])){
            merge_group(x, y, 0);
            return;
        }
        //connect different color
        else if((color[a]^flipped[x])!=(color[b]^flipped[y])){
            //cout << "a : " << a << " b : " << b << "\n";
            merge_group(x, y, 0);
        }
        else merge_group(x, y, 1);
        refresh(find_p(x));
    }
}

void flip_color(int a){
    a=find_p(a);
    flipped[a]^=1;
    rollback(a);
    swap(red_cnt[a], blue_cnt[a]);
    if(!impossible[a]) refresh(a);
}

int sol(int a){
    if(a==0){
        return prev(red.end())->second;
    }
    else return prev(blue.end())->second;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    for(int i=1; i<=N; i++){
        cin >> color[i];
        p[i]=i;
        group[i].push_back(i);
        if(color[i]==0){
            red_cnt[i]=1;
        } 
        else blue_cnt[i]=1;
        refresh(i);
    }

    while(Q--){
        int type;
        cin >> type;
        if(type==1){
            int a, b;
            cin >> a >> b;
            add_edge(a, b);
        }
        else if(type==2){
            int a;
            cin >> a;
            flip_color(a);
        }
        else{
            int a;
            cin >> a;
            cout << sol(a) << "\n";
        }
        //for(int i=1; i<=N; i++) cout << (color[i]^flipped[find_p(i)]) << " ";
        //cout << "\n";
        // cout << "---------red-----------\n";
        // for(auto p : red) cout << p.first << " " << p.second << "\n"; 
        // cout << "---------blue-----------\n";
        // for(auto p : blue) cout << p.first << " " << p.second << "\n";
        // cout << "\n";
    }

    return 0;
}