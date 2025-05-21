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

struct st{
    int left_sum, right_sum, max_sum, total;
};

st merge_node(st A, st B){
    st ret;
    //cout << "A : " << A.left_sum << " " << A.right_sum << " " << A.max_sum << " " << A.total << "\n";
    //cout << "B : " << B.left_sum << " " << B.right_sum << " " << B.max_sum << " " << B.total << "\n";
    ret.left_sum=max(A.left_sum, A.total+B.left_sum);
    ret.right_sum=max(B.right_sum, B.total+A.right_sum);
    ret.max_sum=max({A.max_sum, B.max_sum, A.right_sum+B.left_sum});
    ret.total=A.total+B.total;
    //cout << "ret : " << ret.left_sum << " " << ret.right_sum << " " << ret.max_sum << " " << ret.total << "\n";
    return ret;
};

vector<st> seg;

void update(int node, int start, int end, int index, int value){
    //cout << "node : " << node << " start : " << start << " end : " << end << " index : " << index << endl;
    if(index<start||end<index) return;
    if(start==end){
        seg[node].left_sum+=value;
        seg[node].right_sum+=value;
        seg[node].max_sum+=value;
        seg[node].total+=value;
    }
    else{
        int mid=(start+end)>>1;
        //cout << "mid : " << mid << endl;
        update(node*2, start, mid, index, value);
        //cout << "node : " << node << endl;
        update(node*2+1, mid+1, end, index, value);
        //cout << "node : " << node << endl;
        //cout << "merge : " << node*2 << " " << node*2+1 << " " << node << "\n";
        seg[node]=merge_node(seg[node*2], seg[node*2+1]);
        //cout << "node : " << node << endl;
    }
}

st max_query(int node, int start, int end, int left, int right){
    if(right<start||end<left) return {0, 0, 0, 0};
    if(left<=start&&end<=right) return seg[node];
    int mid=(start+mid)>>1;
    return merge_node(max_query(node*2, start, mid, left, right), max_query(node*2+1, mid+1, end, left, right));
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<array<int, 3>> V;
    vector<int> Y;
    map<int, int> dict;
    for(int i=0; i<N; i++){
        int x, y;
        cin >> x >> y;
        V.push_back({x, y, 0});
        Y.push_back(y);
    }
    int M;
    cin >> M;
    for(int i=0; i<M; i++){
        int x, y;
        cin >> x >> y;
        V.push_back({x, y, 1});
        Y.push_back(y);
    }
    zip(Y);
    for(int i=0; i<Y.size(); i++){
        dict[Y[i]]=i;
    }
    for(auto& a : V){
        a[1]=dict[a[1]];
    }
    sort(all(V));

    //for(auto a : V) cout << a[0] << " " << a[1] << " " << a[2] << endl;

    int arr[2];
    cin >> arr[0] >> arr[1];
    arr[1]*=-1;
    int i=0;
    int ans=0;
    while(i<V.size()){
        //cout << "i : " << i << endl;
        int j=i;
        seg.clear();
        seg.resize(4*Y.size()+5, {0, 0, 0, 0});
        while(j<V.size()){
            //cout << V[j][0] << " " << V[j][1] << " " << V[j][2] << " " << arr[V[j][2]] << endl;
            update(1, 0, Y.size(), V[j][1], arr[V[j][2]]);
            j++;
            while(j<V.size()&&V[j-1][0]==V[j][0]){
                //cout << V[j][0] << " " << V[j][1] << " " << V[j][2] << " " << arr[V[j][2]] << endl;
                update(1, 0, Y.size(), V[j][1], arr[V[j][2]]);
                j++;
            }
            //cout << "j : " << j << endl;
            ans=max(ans, max_query(1, 0, Y.size(), 0, Y.size()).max_sum);
            //cout << "ans : " << ans << "\n";
        }
        i++;
        while(i<V.size()&&V[i-1][0]==V[i][0]) i++;
    }

    cout << ans;
    return 0;
}
