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

mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
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

using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>//이걸 코드의 윗부분에 추가
void m_erase(ordered_set &OS, ll val){
    ll index = OS.order_of_key(val);
    ordered_set::iterator it = OS.find_by_order(index);
    if(*it == val) OS.erase(it);
}
//다른 건 통상적인 PBDS처럼 사용하면 되지만 erase는 반드시!!! 이 함수를 통해서만 해야 함
//m_erase(OS, 지울 원소)처럼 사용하면 된다. 꼭 주의하자.

/*
DP[i]=첫번째 재료의 가치가 i일 때 두번째 재료의 가능한 최대 가치

두 차원 모두 양수인 거는 당연히 그대로 합치고
그렇지 않을 경우 취할 차원을 선택

나머지는 취할 차원만 취하거나 아니면 둘다 취해야 함
*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> PQ;
    for(int i=1; i<=1000000; i++){
        if(i%3&&i%5) PQ.push(i);
    }

    set<int> S;
    while(S.size()<=100000){
        S.insert(PQ.top());
        PQ.push(PQ.top()*15);
        PQ.push(PQ.top()*27);
        PQ.push(PQ.top()*125);
        PQ.pop();
    }

    vector<int> V;
    for(auto i : S) V.push_back(i);

    //for(auto i : V) cout << i << " ";
    //cout << "\n";

    //sort(all(V));

    /*for(int i=1; i<=100000; i++){
        int cnt=0;
        if(S.find(i)!=S.end()) cnt++;
        if(S.find(3*i)!=S.end()) cnt++;
        if(S.find(5*i)!=S.end()) cnt++;
        if(cnt!=1){
            cout << i << " " << cnt << "\n";
        }
    }*/
    
    int TC;
    cin >> TC;
    while(TC--){
        int a;
        cin >> a;
        a--;
        cout << V[a] << "\n";
    }

    return 0;
}
