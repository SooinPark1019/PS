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
int imos[100005];
int imosval[100005];
vector<int> seg(100005*4);
void update(int node, int start, int end, int index, int value){
    if(index<start||end<index) return;
    if(start==end) seg[node]+=value;
    else{
        int mid=(start+end)>>1;
        update(node*2, start, mid, index, value);
        update(node*2+1, mid+1, end, index, value);
        seg[node]=seg[node*2]+seg[node*2+1];
    }
}
int query(int node, int start, int end, int left, int right){
    if(right<start||end<left) return 0;
    if(left<=start&&end<=right) return seg[node];
    int mid=(start+end)>>1;
    return query(node*2, start, mid, left, right)+query(node*2+1, mid+1, end, left, right);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pii> V;

    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        update(1, 0, 100000, b, 1);
        V.push_back({a, b});
        imos[a]++;
        imos[b]--;
    }

    int p1=0, p2=0;
    int cur=0;

    for(int i=0; i<=100000; i++){
        cur+=imos[i];
        imosval[i]=cur;
        p2=max(p2, cur);
    }

    for(auto p : V){
        int a=0;
        if(p.first+1<=p.second-1) a=query(1, 0, 100000, p.first+1, p.second-1);
        //cout << p.first << " " << p.second << " " << a << "\n";
        a+=imosval[p.second-1];
        p1=max(p1, a);
    }

    cout << p1 << " " << p2 << "\n";
    
    return 0;
}
