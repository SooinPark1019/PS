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

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    vector<int> V;
    vector<int> prefix;
    int total=0;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        V.push_back(a);
        total+=a;
        if(prefix.size()>0) prefix.push_back(prefix.back()+a);
        else prefix.push_back(a);
    }

    int left=0;
    int right=total/3;
    int ans=0;
    while(left<=right){
        int mid=(left+right)>>1;
        int firstsum=0;
        int secondsum=0;
        int pointer1=0, pointer2=0;
        int flag=0;
        for(int i=0; i<N; i++){
            while(pointer1<N){
                int a=prefix[pointer1];
                if(i>0) a-=prefix[i-1];
                if(a>=mid) break;
                pointer1++;
            }
            if(pointer1==N) break;
            pointer2=max(pointer1, pointer2);
            while(pointer2<N){
                int a=prefix[pointer2]-prefix[pointer1];
                if(a>=mid) break;
                pointer2++;
            }
            if(pointer2==N) break;
            int sum1=prefix[pointer1];
            if(i>0) sum1-=prefix[i-1];
            int sum2=prefix[pointer2]-prefix[pointer1];
            int sum3=total-sum1-sum2;
            if(sum1>=mid&&sum2>=mid&&sum3>=mid){
                flag=1;
                break;
            }
        }   
        if(flag==1){
            ans=max(ans, mid);
            left=mid+1;
        }
        else right=mid-1;
    }

    cout << ans;

    return 0;
}
