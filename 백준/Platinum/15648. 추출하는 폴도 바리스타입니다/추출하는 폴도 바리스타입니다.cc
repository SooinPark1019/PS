#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-12;
const ll LNF = 1e18;
const ll mod = 998244353;

int N, K, D;
vector<long long> seg;
vector<long long> V;

void update_seg(int node, int start, int end, int index, long long diff){
    if(index<start||index>end) return;
    if(start!=end){
        int mid=(start+end)/2;
        update_seg(node*2, start, mid, index, diff);
        update_seg(node*2+1, mid+1, end, index, diff);
        seg[node]=max(seg[node*2], seg[node*2+1]);
    }
    else{
        seg[node]=diff;
    }
    return;
}

long long sum_seg(int node, int start, int end, int left, int right){
    if(left>end||right<start) return 0;
    if(left<=start&&end<=right) return seg[node];
    int mid=(start+end)/2;
    return max(sum_seg(node*2, start, mid, left, right), sum_seg(node*2+1, mid+1, end, left, right));
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K >> D;
    seg.resize(500005*4);
    ll ans=0;
    ll temp[500005]={};
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        ll b=max(sum_seg(1, 1, 500000, max(1, a-D), min(500000, a+D)), temp[a%K]);
        b++;
        ans=max(ans, b);
        temp[a%K]=b;
        update_seg(1, 1, 500000, a, b);
    }
    cout << ans;
    return 0;
}
