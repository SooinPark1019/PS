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

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;

struct st{
    ll left, right, maxinter;
    int isempty;
};

vector<st> seg(4*500000+5);

st mergest(st A, st B){
    if(A.isempty&&B.isempty){
        return {A.maxinter+B.maxinter, A.maxinter+B.maxinter, max({A.right+B.left, A.maxinter, B.maxinter}), 1};
    }
    else if(A.isempty){
        return {A.maxinter+B.left, B.right, max({A.right+B.left, A.maxinter, B.maxinter}), 0};
    }
    else if(B.isempty){
        return {A.left, A.right+B.maxinter, max({A.right+B.left, A.maxinter, B.maxinter}), 0};
    }
    else{
        return {A.left, B.right, max({A.right+B.left, A.maxinter, B.maxinter}), 0};
    }
}

void init(int node, int start, int end){
    if(start==end){
        seg[node]={1, 1, 1, 1};
    }
    else{
        int mid=(start+end)/2;
        init(node*2, start, mid);
        init(node*2+1, mid+1, end);
        seg[node]=mergest(seg[node*2], seg[node*2+1]);
    }
}

int index(int node, int start, int end, ll P){
     if(seg[node].left>=P) return start;
     int mid=(start+end)/2;
     if(seg[node*2].maxinter>=P) return index(node*2, start, mid, P);
     else if(seg[node*2].right+seg[node*2+1].left>=P) return mid-seg[node*2].right+1;
     else return index(node*2+1, mid+1, end, P);
}

void update(int node, int start, int end, int left ,int right, int val){
    //cout << node << " " << start << " " << end << " " << left << " " << right << " " << val << "\n";
    if(right<start||end<left) return;
    else if(left<=start&&end<=right){
        seg[node]={val*(end-start+1), val*(end-start+1), val*(end-start+1), val};
        //cout << node << " " << seg[node].left << " " << seg[node].right << " " << seg[node].maxinter << "\n";
    }
    else{
        int mid=(start+end)/2;
        if(seg[node].maxinter==0){
            seg[node*2]={0, 0, 0, 0};
            seg[node*2+1]={0, 0, 0, 0};
        }
        else if(seg[node].maxinter==end-start+1){
            seg[node*2]={mid-start+1, mid-start+1, mid-start+1, 1};
            seg[node*2+1]={end-mid, end-mid, end-mid, 1};
        }
        update(node*2, start, mid, left, right, val);
        update(node*2+1, mid+1, end, left, right, val);
        seg[node]=mergest(seg[node*2], seg[node*2+1]);
        //cout << node << " " << seg[node].left << " " << seg[node].right << " " << seg[node].maxinter << "\n";
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    cin >> N >> Q;
    init(1, 0, N-1);
    ll ans=0;
    while(Q--){
        char type;
        cin >> type;
        if(type=='A'){
            ll a;
            cin >> a;
            //cout << seg[1].maxinter << "\n";
            if(seg[1].maxinter<a) ans++;
            else{
                int i=index(1, 0, N-1, a);
                //cout << i << "\n";
                update(1, 0, N-1, i, i+a-1, 0);
            }
        }
        else{
            ll l, r;
            cin >> l >> r;
            l--;
            r--;
            update(1, 0, N-1, l, r, 1);
        }
        //cout << seg[1].maxinter << "\n";
    }
    cout << ans;
}