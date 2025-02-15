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
vector<int> Fenwick(300005);
vector<int> cnt(300005);

void update(int index, int value, vector<int>& Fenwick){
    while(index<=300000){
        Fenwick[index]+=value;
        index+=index&(-index);
    }
}
int sum_fenwick(int index, vector<int>& Fenwick){
    int ret=0;
    while(index>0){
        ret+=Fenwick[index];
        index-=index&(-index);
    }
    return ret;
}

int find_index(int val){
    int left=1;
    int right=300000;
    int ret=300000;
    while(left<=right){
        int mid=(left+right)>>1;
        if(sum_fenwick(mid, cnt)>=val){
            ret=min(ret, mid);
            right=mid-1;
        }
        else left=mid+1;
    }
    return ret;
}

bool compare(pii A, pii B){
    if(A.second==B.second) return A.first<B.first;
    return A.second>B.second;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pii> V;
    vector<pii> X;

    for(int i=0; i<N; i++){
        int a, b;
        cin >> a >> b;
        V.push_back({a, b});
    }
    sort(all(V), compare);

    for(int i=0; i<N; i++){
        X.push_back({V[i].first, i});
    }
    sort(all(X));
    map<int, int> M;
    for(int i=0; i<N; i++){
        M[X[i].second]=i+1;
    }
    int ans=0;
    for(int i=0; i<N; i++){
        update(M[i], 1, cnt);
        update(M[i], V[i].first, Fenwick);
        //cout << "first : " << V[i].first << " second : " << V[i].second << "\n";
        int left=1;
        int right=i+1;
        int res=0;
        while(left<=right){
            int mid=(left+right)>>1;
            int a=find_index(mid);
            int b=sum_fenwick(a, Fenwick);
            //cout << "mid : " << mid << " a : " << a << " b : " << b << "\n";
            if(b<=V[i].second*(mid)){
                res=max(res, mid);
                left=mid+1;
            }
            else right=mid-1;
        }
        ans=max(ans, res);
    }

    cout << ans;

    return 0;
}
