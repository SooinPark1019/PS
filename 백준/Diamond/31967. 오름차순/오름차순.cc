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
int debug=0;
vector<pii> seg(4*250005, {0, 0});
vector<int> lazy(4*250005, 0);

void lazyupdate(int node, int start, int end){
    if(lazy[node]!=0){
        seg[node].first+=lazy[node];
        seg[node].second+=lazy[node]*(end-start+1);
        if(start!=end){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
}

void updateseg(int node, int start, int end, int left, int right, int value){
    lazyupdate(node, start, end);
    if(end<left||right<start){
        return;
    }
    if(left<=start&&end<=right){
        lazy[node]+=value;
        lazyupdate(node, start, end);
    }
    else{
        int mid=(start+end)>>1;
        updateseg(node*2, start, mid, left, right, value);
        updateseg(node*2+1, mid+1, end, left, right, value);
        seg[node].first=min(seg[node*2].first, seg[node*2+1].first);
        seg[node].second=seg[node*2].second+seg[node*2+1].second;
    }
}

int min_query(int node, int start, int end, int left, int right){
    lazyupdate(node, start, end);
    if(end<left||right<start){
        return 1e18;
    }
    if(left<=start&&end<=right){
        return seg[node].first;
    }
    int mid=(start+end)>>1;
    return min(min_query(node*2, start, mid, left, right), min_query(node*2+1, mid+1, end, left, right));
}

int sum_query(int node, int start, int end, int left, int right){
    lazyupdate(node, start, end);
    if(end<left||right<start){
        return 0;
    }
    if(left<=start&&end<=right){
        //if(debug) cout << "node : " << node << " start : " << start << " end : " << end << " left : " << left << " right : " << right << " value : " << seg[node].second << "\n";
        return seg[node].second;
    }
    int mid=(start+end)>>1;
    int ret = sum_query(node*2, start, mid, left, right)+sum_query(node*2+1, mid+1, end, left, right);
    //if(debug)cout << "node : " << node << " start : " << start << " end : " << end << " left : " << left << " right : " << right << " value : " << ret << "\n";
    return ret;
}

int find_index(int node, int start, int end, int value, int index){
    lazyupdate(node, start, end);
    //cout << "start : " << start << " end : " << end << " seg : " << seg[node].first << "\n"; 
    if(seg[node].first>=value) return end;
    if(start==end) return -1;
    int mid=(start+end)>>1;
    if(index>mid) return find_index(node*2+1, mid+1, end, value, index);
    int a=find_index(node*2, start, mid, value, index);
    //if(debug) cout << "node : " << node << " start : " << start << " end : " << end << " value : " << value << " index : " << index << " " << a << "\n";
    if(a==mid){
        int b=find_index(node*2+1, mid+1, end, value, index);
        if(b==-1) return a;
        else return b;
    }
    return a;
}
struct q{
    int l, r, i;
};
bool compare(q A, q B){
    return A.l<B.l;
}
int ans[250005];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    cin >> N >> Q;
    vector<int> V;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        V.push_back(a);
    }

    vector<q> query;
    for(int i=0; i<Q; i++){
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        query.push_back({l, r, i});
    }

    sort(all(query), compare);

    int curl=0;
    int cure=0;
    for(int i=1; i<N; i++){
        if(V[i]>V[i-1]){
            int a=V[i-1];
            int b=V[i];
            int c=0;
            while(1){
                a<<=1;
                if(a>b) break;
                c++;
            }
            cure=max(0ll, cure-c);
        }
        else{
            int a=V[i-1];
            int b=V[i];
            int c=0;
            while(b<a){
                c++;
                b<<=1;
            }
            cure=max(0ll, cure+c);
        }
        updateseg(1, 0, N-1, i, i, cure);
    }

    /*for(int i=0; i<N; i++){
        cout << sum_query(1, 0, N-1, i, i) << " ";
    }
    cout << "\n";*/

    for(int i=0; i<Q; i++){
        while(curl<query[i].l){
            int curpos=curl+1;
            while(curpos<N){
                int a=min_query(1, 0, N-1, curpos, curpos);
                if(curpos==7) debug=1;
                int b=find_index(1, 0, N-1, a, curpos);
                debug=0;
                //cout << "curpos : " << curpos << " a : " << a << " b : " << b << "\n";
                updateseg(1, 0, N-1, curpos, b, -a);
                curpos=b+1;
                //for(int j=0; j<N; j++){
                    //cout << min_query(1, 0, N-1, j, j) << " ";
                //}
                //cout << "\n";
            }
            curl++;
        }
        //cout << "curl : " << curl << "\n";
        //for(int j=0; j<N; j++){
            //cout << sum_query(1, 0, N-1, j, j) << " ";
        //}
        //cout << "\n";
        //cout << "l : " << query[i].l << " r : " << query[i].r << "\n";
        if(query[i].l==2) debug=1;
        //cout << sum_query(1, 0, N-1, query[i].l, query[i].r) << "\n";
        debug=0;
        ans[query[i].i]=sum_query(1, 0, N-1, query[i].l, query[i].r);
    }

    for(int i=0; i<Q; i++){
        cout << ans[i] << "\n";
    }

    return 0;
}