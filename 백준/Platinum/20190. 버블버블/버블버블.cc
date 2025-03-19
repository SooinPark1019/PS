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

vector<int> seg(1000005*4, 0);
vector<int> lazy(1000005*4, 0);

void lazyupdate(int node, int start, int end){
    if(lazy[node]!=0){
        seg[node]+=lazy[node];
        if(start!=end){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
}

void updateseg(int node, int start, int end, int left, int right, int val){
    lazyupdate(node, start, end);
    if(right<start||end<left) return;
    if(left<=start&&end<=right){
        lazy[node]+=val;
        lazyupdate(node, start, end);
    }
    else{
        int mid=(start+end)>>1;
        updateseg(node*2, start, mid, left, right, val);
        updateseg(node*2+1, mid+1, end, left, right, val);
        seg[node]=min(seg[node*2], seg[node*2+1]);
    }
}

int min_query(int node, int start, int end, int left, int right){
    lazyupdate(node, start, end);
    if(right<start||end<left) return 1e18;
    if(left<=start&&end<=right) return seg[node];
    int mid=(start+end)>>1;
    return min(min_query(node*2, start, mid, left, right), min_query(node*2+1, mid+1, end, left, right));
}

vector<int> Fenwick(1000005);

void update_fenwick(int index, int val){
    while(index>0){
        Fenwick[index]+=val;
        index-=index&(-index);
    }
}

int sum_fenwick(int index){
    int ret=0;
    while(index<=1000000){
        ret+=Fenwick[index];
        index+=index&(-index);
    }
    return ret;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> V;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        V.push_back(a);
    }

    int totalinversion=0;
    vector<int> inversion;

    for(int i=0; i<N; i++){
        inversion.push_back(sum_fenwick(V[i]+1));
        totalinversion+=inversion.back();
        update_fenwick(V[i], 1);
    }

    Fenwick.clear();
    Fenwick.resize(1000005, 0);

    for(int i=N-1; i>=0; i--){
        inversion[i]+=sum_fenwick(1000000-V[i]+1);
        if(V[i]!=1000000) update_fenwick(1000000-V[i], 1);
    }

    for(int i=0; i<N; i++){
        if(V[i]!=1000000) updateseg(1, 0, 1000000, V[i]+1, 1000000, 1);
    }
    for(int i=0; i<N; i++){
        if(V[i]!=1000000) updateseg(1, 0, 1000000, V[i]+1, 1000000, -1);
        cout << totalinversion-inversion[i]+seg[1] << " ";
        updateseg(1, 0, 1000000, 0, V[i]-1, 1);
    }

    return 0;
}
