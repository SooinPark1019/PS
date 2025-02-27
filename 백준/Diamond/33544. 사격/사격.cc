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
사격 짜기 전에 정리를 좀 하면
Y좌표 내림차순으로 정렬, X좌표는 좌압
점들을 차례대로 보면서
seg[i]=지금까지 Y축 방향으로 먹은 애들 중 X좌표가 제일 작은 놈이 i일 때 가능한 최대 점수
현재 점의 좌표가 (x, y)일 때

해당 점을 Y축 방향으로 먹는 경우
a=seg[x+1...N]의 최댓값. seg[x]=max(seg[x], a+y)
seg[1...x-1]까지에 y 값만큼 lazy 구간 덧셈 업데이트

해당 점을 X축 방향으로 먹는 경우
seg[X+1..N]에다가 값 X만큼 lazy 구간 덧셈 업데이트
*/

vector<int> seg(500005*4);
vector<int> lazy(500005*4);

void lazyupdate(int node, int start, int end){
    if(lazy[node]!=0){
        seg[node]+=lazy[node];
        if(start!=end){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    return;
}

void rangeupdate(int node, int start, int end, int left, int right, int value){
    //cout << "node : " << node << " start : " << start << " end : " << end << endl;
    lazyupdate(node, start, end);
    if(right<start||end<left) return;
    if(left<=start&&end<=right){
        lazy[node]+=value;
        lazyupdate(node, start, end);
        return;
    }
    int mid=(start+end)>>1;
    rangeupdate(node*2, start, mid, left, right, value);
    rangeupdate(node*2+1, mid+1, end, left, right, value);
    seg[node]=max(seg[node*2], seg[node*2+1]);
}

void pointupdate(int node, int start, int end, int index, int value){
    lazyupdate(node, start, end);
    if(index<start||end<index) return;
    if(start==end){
        seg[node]=max(seg[node], value);
        return;
    }
    int mid=(start+end)>>1;
    pointupdate(node*2, start, mid, index, value);
    pointupdate(node*2+1, mid+1, end, index, value);
    seg[node]=max(seg[node*2], seg[node*2+1]);
}   

int rangemax(int node, int start, int end, int left, int right){
    lazyupdate(node, start, end);
    if(right<start||end<left) return 0;
    if(left<=start&&end<=right){
        return seg[node];
    }
    int mid=(start+end)>>1;
    return max(rangemax(node*2, start, mid, left, right), rangemax(node*2+1, mid+1, end, left, right));
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pii> V;
    vector<int> X;
    map<int, int> M;
    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        V.push_back({a, b});
        X.push_back(b);
    }

    sort(V.rbegin(), V.rend());
    zip(X);

    for(int i=0; i<X.size(); i++){
        M[X[i]]=i+1;
    }

    vector<int> index(N);

    for(int i=0; i<N; i++){
        index[i]=M[V[i].second];
    }

    for(int i=0; i<N; i++){
        int a=rangemax(1, 1, N+1, index[i], N+1)+V[i].first;
        pointupdate(1, 1, N+1, index[i], a);
        if(index[i]>1) rangeupdate(1, 1, N+1, 1, index[i]-1, V[i].first);
        rangeupdate(1, 1, N+1, index[i]+1, N+1, V[i].second);
        //for(int i=1; i<=N+1; i++){
            //cout << rangemax(1, 1, N+1, i, i) << " ";
        //}
        //cout << "\n";
    }

    cout << rangemax(1, 1, N+1, 1, N+1);

    return 0;
}