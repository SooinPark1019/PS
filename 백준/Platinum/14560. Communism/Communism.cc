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

vector<int> merge_vectors(vector<int>& A, int cur){
    int p1=0, p2=0, p3=0;
    vector<int> ret;
    while(p1<A.size()||p2<A.size()||p3<A.size()){
        int a=1e18, b=1e18, c=1e18;
        if(p1<A.size()) a=A[p1]+cur;
        if(p2<A.size()) b=A[p2];
        if(p3<A.size()) c=A[p3]-cur;
        if(a==min({a, b, c})){
            ret.push_back(a);
            p1++;
        }
        else if(b==min({a, b, c})){
            ret.push_back(b);
            p2++;
        }
        else{
            ret.push_back(c);
            p3++;
        }
    }
    return ret;
}

vector<int> make_vector(vector<int>& V){
    vector<int> ret;
    ret.push_back(0);
    for(auto i : V){
        ret=merge_vectors(ret, i);
    }
    return ret;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> A, B;
    for(int i=0; i<N/2; i++){
        int a;
        cin >> a;
        A.push_back(a);
    }
    for(int i=N/2; i<N; i++){
        int a;
        cin >> a;
        B.push_back(a);
    }
    A=make_vector(A);
    B=make_vector(B);

    //cout << "-----------A-----------\n";
    //for(auto i : A) cout << i << " ";
    //cout << "\n";

    //cout << "-----------B-----------\n";
    //for(auto i : B) cout << i << " ";
    //cout << "\n";

    int D;
    cin >> D;

    int left=A.size(), right=A.size()-1;
    int ans=0;
    for(auto i : B){
        while(left>0&&A[left-1]+i>=-D) left--;
        while(right>=0&&A[right]+i>D) right--;
        //cout << "left : " << left << " right : " << right << "\n";
        ans+=max(0ll, right-left+1);
    }

    cout << ans;

    return 0;
}
