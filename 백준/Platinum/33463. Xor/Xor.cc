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

using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>//이걸 코드의 윗부분에 추가
void m_erase(ordered_set &OS, int val){
    int index = OS.order_of_key(val);
    ordered_set::iterator it = OS.find_by_order(index);
    if(*it == val) OS.erase(it);
}
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
두 개를 더했을 때 i번째 자리가 1

둘 다 0일 때 carry가 중요할듯?

결국 각 합에 대해서 i번째 자리가 몇개가 나오는지를 알아야 하는데
합들의 XOR
PBDS?

내 앞에 있는 애들을 잘 뭉개면 되지 않을까?

2^(i+1)로 나눈 나머지를 생각
*/

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> V;
    int ans=0;

    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        V.push_back(a);
    }
    for(int i=0; i<=30; i++){
        //cout << "i : " << i << "\n";
        ordered_set OS;
        ll cnt=0;
        for(int j=0; j<N; j++){
            int a=V[j]%(1ll<<(i+1));
            //cout << "a : " << a << "\n";
            OS.insert(a);
            if((a&(1ll<<i))){
                cnt+=OS.order_of_key((1ll<<(i+1))-a);
                cnt+=OS.size()-OS.order_of_key((1ll<<(i+1))+(1ll<<(i))-a);
                //cout << cnt << "\n";
            }
            else{
                cnt+=OS.order_of_key((1ll<<(i+1))-a)-OS.order_of_key((1ll<<(i))-a);
                //cout << cnt << "\n";
            }
        }
        //cout << "cnt : " << cnt << "\n";
        ans+=(cnt%2)<<i;
    }

    cout << ans;
    
    return 0;
}
