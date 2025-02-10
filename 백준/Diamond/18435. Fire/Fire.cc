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
DP[i]=첫번째 재료의 가치가 i일 때 두번째 재료의 가능한 최대 가치

두 차원 모두 양수인 거는 당연히 그대로 합치고
그렇지 않을 경우 취할 차원을 선택

나머지는 취할 차원만 취하거나 아니면 둘다 취해야 함
*/

vector<int> Fenwick1(400005);
vector<int> Fenwick2(400005);
vector<int> Fenwick3(400005);
vector<int> Fenwick4(400005);

void update(int index, int v, vector<int>& Fenwick){
    //cout << index << " " << v << "\n";
    index+=200002;
    while(index<=400004){
        Fenwick[index]+=v;
        index+=index&(-index);
    }
}

int sum(int index, vector<int>& Fenwick){
    int ret=0;
    index+=200002;
    while(index>0){
        ret+=Fenwick[index];
        index-=index&(-index);
    }
    return ret;
}

int leftbigger[200005];
int rightbigger[200005];

vector<pii> Query[5][200005];

void add_triangle(int l, int r, int v){
    //cout << "l : " << l << " r : " << r << " v : " << v << "\n";
    Query[0][0].push_back({l+1, v});
    Query[1][0].push_back({l+1, -l*v});
    Query[2][0].push_back({r, -v});
    Query[3][0].push_back({r, (r-1)*v});
    Query[0][r-l].push_back({l+1, -v});
    Query[1][r-l].push_back({l+1, l*v});
    Query[2][r-l].push_back({r, v});
    Query[3][r-l].push_back({r, -(r-1)*v});
}

struct query{
    int t, l, r, i;
};

bool compare(query A, query B){
    return A.t<B.t;
}

int ans[200005];

void do_queries(int cur_time){
    //cout << "Fenwick1 : " << "\n";
    for(auto p : Query[0][cur_time]) update(p.first, p.second, Fenwick1);
    //cout << "Fenwick2 : " << "\n";
    for(auto p : Query[1][cur_time]) update(p.first, p.second, Fenwick2);
    //cout << "Fenwick3 : " << "\n";
    for(auto p : Query[2][cur_time]) update(p.first, p.second, Fenwick3);
    //cout << "Fenwick4 : " << "\n";
    for(auto p : Query[3][cur_time]) update(p.first, p.second, Fenwick4);
}

int cal_query(int t, int i){
    //cout << "t : " << t << " i : " << i << " " << (i-t)*sum(i-t, Fenwick1) << " " << sum(i-t, Fenwick2) << " " << i*sum(i, Fenwick3) << " " << sum(i, Fenwick4) << "\n";
    return (i-t)*sum(i-t, Fenwick1)+sum(i-t, Fenwick2)+i*sum(i, Fenwick3)+sum(i, Fenwick4);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    vector<int> V;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        V.push_back(a);
    }

    stack<pii> S;
    S.push({1e18, -N-1});
    for(int i=0; i<N; i++){
        while(S.top().first<=V[i]) S.pop();
        leftbigger[i]=S.top().second;
        S.push({V[i], i});
    }

    while(!S.empty()) S.pop();

    S.push({1e18, N+1});
    for(int i=N-1; i>=0; i--){
        while(S.top().first<V[i]) S.pop();
        rightbigger[i]=S.top().second;
        S.push({V[i], i});
    }

    //for(int i=0; i<N; i++){
        //cout << "i : " << i << " left : " << leftbigger[i] << " right : " << rightbigger[i] << "\n";
    //}

    for(int i=0; i<N; i++){
        add_triangle(leftbigger[i], rightbigger[i], V[i]);
        add_triangle(leftbigger[i], i, -V[i]);
        add_triangle(i, rightbigger[i], -V[i]);
    }

    vector<query> Queries;
    for(int i=0; i<Q; i++){
        int t, l, r;
        cin >> t >> l >> r;
        l--;
        r--;
        Queries.push_back({t, l, r, i});    
    }

    sort(all(Queries), compare);

    int cur_time=-1;

    for(auto q : Queries){ 
        while(cur_time<q.t){
            cur_time++;
            do_queries(cur_time);
        }
        ans[q.i]=cal_query(q.t, q.r)-cal_query(q.t, q.l-1);
    }

    for(int i=0; i<Q; i++) cout << ans[i] << "\n";

    return 0;
}
