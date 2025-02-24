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

struct node{
    int len, sum, simplesum, evenmin, evenmax, oddmin, oddmax;
};

node merge(node A, node B){
    node ret;
    ret.len=A.len+B.len;
    ret.simplesum=A.simplesum+B.simplesum;
    if(A.len%2){
        ret.sum=A.sum-B.sum;
        ret.evenmin=min(A.evenmin, A.sum-B.oddmax);
        ret.evenmax=max(A.evenmax, A.sum-B.oddmin);
        ret.oddmin=min(A.oddmin, A.sum-B.evenmax);
        ret.oddmax=max(A.oddmax, A.sum-B.evenmin);
    }
    else{
        ret.sum=A.sum+B.sum;
        ret.evenmin=min(A.evenmin, A.sum+B.evenmin);
        ret.evenmax=max(A.evenmax, A.sum+B.evenmax);
        ret.oddmin=min(A.oddmin, A.sum+B.oddmin);
        ret.oddmax=max(A.oddmax, A.sum+B.oddmax);
    };
    return ret;
}

vector<node> seg(800005);

void update(int n, int start, int end, int index, int value){
    if(index<start||end<index){
        return;
    }
    if(start==end){
        seg[n].len=1;
        seg[n].sum=value;
        seg[n].simplesum=value;
        seg[n].oddmin=value;
        seg[n].oddmax=value;
        seg[n].evenmin=1e18;
        seg[n].evenmax=-1e18;
    }
    else{
        int mid=(start+end)>>1;
        update(2*n, start, mid, index, value);
        update(2*n+1, mid+1, end, index, value);
        seg[n]=merge(seg[n*2], seg[n*2+1]);
    }
    return;
}

node sum_query(int n, int start, int end, int left, int right){
    if(right<start||end<left){
        node ret;
        ret.len=0;
        ret.sum=0;
        ret.simplesum=0;
        ret.oddmin=1e18;
        ret.oddmax=-1e18;
        ret.evenmax=-1e18;
        ret.evenmin=1e18;
        return ret;
    }
    if(left<=start&&end<=right){
        return seg[n];
    }
    int mid=(start+end)>>1;
    return merge(sum_query(n*2, start, mid, left, right), sum_query(n*2+1, mid+1, end, left, right));
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        update(1, 0, N-1, i, a);
    }

    int Q;
    cin >> Q;

    while(Q--){
        int type;
        cin >> type;
        if(type==1){
            int i, v;
            cin >> i >> v;
            i--;
            update(1, 0, N-1, i, v);
        }
        else{
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            node n=sum_query(1, 0, N-1, l, r);
            //cout << n.evenmax << " " << n.evenmin << " " << n.oddmax << " " << n.oddmin << "\n";
            int a=min(-n.evenmax, n.oddmin);
            if(a<0) cout << -1 << "\n";
            else{
                if((r-l+1)%2){
                    if(n.sum!=n.oddmin) cout << -1 << "\n";
                    else cout << (n.simplesum-(r-l+1)*n.oddmin)/2 << "\n";
                }
                else{
                    if(n.sum!=0) cout << -1 << "\n";
                    else cout << (n.simplesum-(r-l+1)*n.oddmin)/2 << "\n";
                }
            }
        }
    }

    return 0;
}
