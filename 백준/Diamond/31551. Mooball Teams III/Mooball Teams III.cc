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

int fastmul(int a, int b){
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0){
        int temp=fastmul(a, b/2);
        return temp*temp%mod;
    }
    return a*fastmul(a, b-1)%mod;
}

int pow2[200005];
int inv_pow2[200005];

vector<int> seg(200005*4);
vector<int> seg2(200005*4);
vector<int> lazy(200005*4);
vector<int> lazy2(200005*4);

void lazyupdate(int node, int start, int end, vector<int>& seg, vector<int>& lazy){
    if(lazy[node]!=0){
        if(lazy[node]>0){
            seg[node]*=pow2[lazy[node]];
            seg[node]%=mod;
        }
        else{
            seg[node]*=inv_pow2[-lazy[node]];
            seg[node]%=mod;
        }
        if(start!=end){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
}

void update_mul(int node, int start, int end, int left, int right, int val, vector<int>& seg, vector<int>& lazy){
    lazyupdate(node, start, end, seg, lazy);
    if(right<start||end<left) return;
    if(left<=start&&end<=right){
        lazy[node]+=val;
        lazyupdate(node, start, end, seg, lazy);
    }
    else{
        int mid=(start+end)>>1;
        update_mul(node*2, start, mid, left, right, val, seg, lazy);
        update_mul(node*2+1, mid+1, end, left, right, val, seg, lazy);
        seg[node]=(seg[node*2]+seg[node*2+1]+mod)%mod;
    }
}

void update_plus(int node, int start, int end, int index, int val, vector<int>& seg, vector<int>& lazy){
    lazyupdate(node, start, end, seg, lazy);
    if(index<start||end<index) return;
    if(start==end){
        seg[node]+=val;
        seg[node]%=mod;
    }
    else{
        int mid=(start+end)>>1;
        update_plus(node*2, start, mid, index, val, seg, lazy);
        update_plus(node*2+1, mid+1, end, index, val, seg, lazy);
        seg[node]=(seg[node*2]+seg[node*2+1]+mod)%mod;
    }
}

int query_sum(int node, int start, int end, int left, int right, vector<int>& seg, vector<int>& lazy){
    lazyupdate(node, start, end, seg, lazy);
    if(right<start||end<left) return 0;
    if(left<=start&&end<=right) return seg[node];
    int mid=(start+end)>>1;
    return (query_sum(node*2, start, mid, left, right, seg, lazy)+query_sum(node*2+1, mid+1, end, left, right, seg, lazy)+mod)%mod;
}

vector<int> Fenwick(200005);

void update_Fenwick(int index, int value){
    while(index>0){
        Fenwick[index]+=value;
        index-=index&(-index);
    }
}

int sum_Fenwick(int index){
    int ret=0;
    while(index<=200000){
        ret+=Fenwick[index];
        index+=index&(-index);
    }
    return ret;
}

vector<int> Fenwick2(200005);

void update_Fenwick2(int index, int value){
    while(index<=200000){
        Fenwick2[index]+=value;
        index+=index&(-index);
    }
}

int sum_Fenwick2(int index){
    int ret=0;
    while(index>0){
        ret+=Fenwick2[index];
        index-=index&(-index);
    }
    return ret;
}

int calc(vector<pii>& V, int N){
    Fenwick.clear();
    Fenwick2.clear();
    seg.clear();
    seg2.clear();
    lazy.clear();
    lazy2.clear();

    Fenwick.resize(200005);
    Fenwick2.resize(200005);
    seg.resize(200005*4);
    seg2.resize(200005*4);
    lazy.resize(200005*4);
    lazy2.resize(200005*4);

    int ret=0;

    for(int i=0; i<N; i++){
        update_Fenwick(V[i].second, 1);
    }

    for(int i=0; i<N; i++){
        int y=V[i].second;
        update_Fenwick(V[i].second, -1);
        update_Fenwick2(V[i].second, 1);
        int biggery=sum_Fenwick(V[i].second+1);
        int smallery=sum_Fenwick2(V[i].second-1);
        update_plus(1, 0, N, V[i].second, pow2[biggery+smallery], seg, lazy);
        update_plus(1, 0, N, V[i].second, pow2[smallery], seg2, lazy2);
        ret+=query_sum(1, 0, N, V[i].second, N, seg, lazy);
        ret%=mod;
        ret-=query_sum(1, 0, N, V[i].second, N, seg2, lazy2);
        ret+=mod;
        ret%=mod;
        update_mul(1, 0, N, 0, V[i].second-1, -1, seg, lazy);
        update_mul(1, 0, N, V[i].second+1, N, 1, seg, lazy);
        update_mul(1, 0, N, V[i].second+1, N, 1, seg2, lazy2);
    }

    return ret;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pow2[0]=1;
    inv_pow2[0]=1;
    for(int i=1; i<=200000; i++){
        pow2[i]=pow2[i-1]*2%mod;
        inv_pow2[i]=inv_pow2[i-1]*fastmul(2, mod-2)%mod;
    }
    int N;
    cin >> N;
    vector<pii> V;
    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        V.push_back({a, b});
    }

    sort(all(V));

    int ans1=0;
    for(int i=0; i<N; i++){
        ans1+=pow2[i]*(pow2[N-1-i]-1+mod)%mod;
        ans1%=mod;
    }
    ans1*=2;
    ans1%=mod;
    
    int ans2=calc(V, N);
    reverse(all(V));
    ans2+=calc(V, N);
    ans2%=mod;
    cout << 2*(ans1-ans2+mod)%mod;
    return 0;
}
