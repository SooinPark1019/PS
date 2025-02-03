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
#define int long long
//#define sz(x) (int)x.size()

using namespace __gnu_cxx;
using namespace std;

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
Z로 생각을 해보자
먼저 첫번째 두 배열을 그대로 붙인 상태로 시작을 해서
Z값을 계산
접두사=접미사 되는 곳을 찾아가지고 비용계산
남은 것을 다음 문자열로 이월
*/

vector<int> seg(200005*4);

void update_seg(int node, int start, int end, int index, int value){
    if(index<start||end<index) return;
    if(start==end) seg[node]+=value;
    else{
        int mid=(start+end)>>1;
        update_seg(node*2, start, mid, index, value);
        update_seg(node*2+1, mid+1, end, index, value);
        seg[node]=seg[node*2]+seg[node*2+1];
    }
    return;
}

int sum_seg(int node, int start, int end, int left, int right){
    if(end<left||right<start) return 0;
    if(left<=start&&end<=right) return seg[node];
    int mid=(start+end)>>1;
    return sum_seg(node*2, start, mid, left, right)+sum_seg(node*2+1, mid+1, end, left, right);
}

vector<int> V(200005);

int sol(int total, int N){
    int left=0;
    int right=N;
    int ans=1e18;
    while(left<=right){
        int mid=(left+right)>>1;
        int a=sum_seg(1, 0, N, 0, mid);
        ans=min(ans, abs(total-2*a));
        if(a>total/2) right=mid-1;
        else left=mid+1;
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int total=0;

    for(int i=1; i<N; i++){
        int a;
        cin >> a;
        V[i]=a;
        update_seg(1, 0, N, i, a);
        total+=a;
    }

    cout << sol(total, N) << "\n";

    int Q;
    cin >> Q;
    while(Q--){
        int i, a;
        cin >> i >> a;
        int diff=a-V[i];
        V[i]=a;
        total+=diff;
        update_seg(1, 0, N, i, diff);
        cout << sol(total, N) << "\n";
    }

    return 0;
}
