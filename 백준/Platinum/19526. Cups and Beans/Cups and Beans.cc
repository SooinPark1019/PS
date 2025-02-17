#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define int long long
#define ll long long

using namespace std;

//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
//#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>//이걸 코드의 윗부분에 추가
/*void m_erase(ordered_set &OS, ll val){
    ll index = OS.order_of_key(val);
    ordered_set::iterator it = OS.find_by_order(index);
    if(*it == val) OS.erase(it);
}*/
//다른 건 통상적인 PBDS처럼 사용하면 되지만 erase는 반드시!!! 이 함수를 통해서만 해야 함
//m_erase(OS, 지울 원소)처럼 사용하면 된다. 꼭 주의하자.
//얘네 쓰려면 define int long long 꺼라.

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
vector<int> Seg(100005*4, -1);

void update(int node, int start, int end, int index, int value){
    if(index<start||end<index) return;
    if(start==end) Seg[node]=value;
    else{
        int mid=(start+end)>>1;
        update(node*2, start, mid, index, value);
        update(node*2+1, mid+1, end, index, value);
        Seg[node]=min(Seg[node*2], Seg[node*2+1]);
    }
}
int find_index(int node, int start, int end, int value){
    if(start==end) return start;
    int mid=(start+end)>>1;
    if(Seg[node*2]<value) return find_index(node*2, start, mid, value);
    return find_index(node*2+1, mid+1, end, value);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    update(1, 0, N, 0, 0);

    int res=0;

    for(int i=1; i<N; i++){
        int C, A;
        cin >> C >> A;
        int ans=find_index(1, 0, N, i-C);
        //cout << ans << "\n";
        update(1, 0, N, ans, i);
        if(A%2) res^=ans;
    }

    if(res==0) cout << "Second";
    else cout << "First";

    return 0;
}
