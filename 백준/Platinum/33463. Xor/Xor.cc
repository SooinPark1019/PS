#include <ext/rope>
#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
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

// using namespace __gnu_pbds;
// using namespace __gnu_cxx;
// #define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>//이걸 코드의 윗부분에 추가
// void m_erase(ordered_set &OS, int val){
//     int index = OS.order_of_key(val);
//     ordered_set::iterator it = OS.find_by_order(index);
//     if(*it == val) OS.erase(it);
// }
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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    ll ans=0;
    vector<int> V(N);
    for(int i=0; i<N; i++){
        cin >> V[i];
    }
    for(int i=0; i<=30; i++){
        vector<int> temp1;
        vector<int> temp2;
        //cout << "i : " << i << "\n";
        ll cnt=0;
        for(int j=0; j<N; j++){
            if(V[j]&(1ll<<i)) temp2.push_back(V[j]);
            else temp1.push_back(V[j]);
        }
        vector<int> temp;
        for(auto i : temp1) temp.push_back(i);
        for(auto i : temp2) temp.push_back(i);
        int curpointer1=0;
        int curpointer2=0;
        int curpointer3=0;
        for(int j=0; j<N; j++){
            int a=temp[j]%(1ll<<(i+1));
            //cout << "a : " << a << "\n";
            //cout << (1ll<<i)-a << "\n";
            if(a<(1ll<<i)-a) curpointer1++;
            if(a<(1ll<<(i+1))-a) curpointer2++;
            if(a<(1ll<<(i+1))+(1<<(i))-a) curpointer3++;
            //cout << "cur1 : " << curpointer1 << "\n";
            while(curpointer1>0&&temp[curpointer1-1]%(1ll<<(i+1))>=(1ll<<(i))-a) curpointer1--;
            while(curpointer2>0&&temp[curpointer2-1]%(1ll<<(i+1))>=(1ll<<(i+1))-a) curpointer2--;
            while(curpointer3>0&&temp[curpointer3-1]%(1ll<<(i+1))>=(1ll<<(i+1))+(1ll<<(i))-a) curpointer3--;
            //cout << curpointer1 << " " << curpointer2 << " " << curpointer3 << "\n";
            if((a&(1<<i))){
                cnt+=curpointer2;
                cnt+=j+1-curpointer3;
                //cout << cnt << "\n";
            }
            else{
                cnt+=curpointer2;
                cnt-=curpointer1;
                //cout << cnt << "\n";
            }
        }
        //cout << "cnt : " << cnt << "\n";
        ans+=(cnt%2)<<i;
        V=temp;
    }

    cout << ans;
    
    return 0;
}
