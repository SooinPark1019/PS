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

int sol(double angle, double length, int flag){
    angle=angle/180*PI;
    //cout << "angle : " << angle << " cos : " << cos(angle) << " sin : " << sin(angle) << "\n";
    double x=cos(angle)*length*flag;
    double y=sin(angle)*length;
    x=x+y/sqrt(3);
    y=y*2/sqrt(3);
    //cout << "x : " << x << " y : " << y << "\n";
    while(x<0) x+=2;
    int a=x;
    int b=y;
    double c=x-a;
    double d=y-b;
    //cout << a << " " << b << " " << c << " " << d << "\n";
    if(a%2==0){
        if(b%2==0){
            if(c>d) return 4;
            else return 3;
        }   
        else{
            if(c>d) return 1;
            else return 2;
        }
    }
    else{
        if(b%2==0){
            if(c>d){
                return 2;
            }
            return 1;
        }
        else{
            if(c>d){
                return 3;
            }
            return 4;
        }
    }
}

int pre_cal(string S, double angle, double length){
    if(S=="CD") return sol(angle, length, -1);
    else if(S=="DB"){
        angle+=60;
        if(angle==0){
            double a=sqrt(3);
            while(length>a) length-=a;
            //cout << length << "\n";
            if(length<a/2) return 3;
            else return 1;
        }
        if(angle<90) return sol(angle, length, -1);
        else return sol(180-angle, length, 1);
    }
    else{
        angle+=120;
        angle=180-angle;
        return sol(angle, length, 1);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S1, S2;
    int a1, a2;
    double l1, l2;
    cin >> S1 >> a1 >> l1;
    cin >> S2 >> a2 >> l2;

    if(pre_cal(S1, a1, l1)==pre_cal(S2, a2, l2)) cout << "YES";
    else cout << "NO";

    return 0;
}
