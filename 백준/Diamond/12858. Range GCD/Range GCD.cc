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
#define int long long

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;
const int MAXN = (1<<18)+5;

/*
*/

vector<int> GCDseg(400005);
vector<int> seg(400005);
vector<int> lazy(400005);

void gcdupdate(int node, int start, int end, int index, int value){
    if(index<start||end<index) return;
    if(start==end){
        GCDseg[node]+=value;
    }
    else{
        int mid=(start+end)/2;
        gcdupdate(node*2, start, mid, index, value);
        gcdupdate(node*2+1, mid+1, end, index, value);
        GCDseg[node]=__gcd(GCDseg[node*2], GCDseg[node*2+1]);
    }
}

int sumgcd(int node, int start, int end, int left, int right){
    if(end<left||right<start) return 0;
    else if(left<=start&&end<=right) return GCDseg[node];
    int mid=(start+end)/2;
    int a=sumgcd(node*2, start, mid, left, right);
    int b=sumgcd(node*2+1, mid+1, end, left, right);
    return __gcd(a, b);
}

void lazyupdate(int node, int start, int end){
    if(lazy[node]!=0){
        seg[node]+=lazy[node]*(end-start+1);
        if(start!=end){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
}

void update(int node, int start, int end, int left, int right, int value){
    //cout << node << " " << start << " " << end << endl;
    lazyupdate(node, start, end);
    if(end<left||right<start) return;
    else if(left<=start&&end<=right){
        lazy[node]+=value;
        lazyupdate(node, start, end);
    }
    else{
        int mid=(start+end)/2;
        update(node*2, start, mid, left, right, value);
        update(node*2+1, mid+1, end, left, right, value);
        seg[node]=seg[node*2]+seg[node*2+1];
    } 
}

int sum(int node, int start, int end, int left, int right){
    lazyupdate(node, start, end);
    if(end<left||right<start) return 0;
    else if(left<=start&&end<=right){
        return seg[node];
    }
    int mid=(start+end)/2;
    return sum(node*2, start, mid, left, right)+sum(node*2+1, mid+1, end, left, right);
}


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<int> V;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        V.push_back(a);
    }

    for(int i=0; i<N; i++){
        if(i!=N-1){
            gcdupdate(1, 0, N-1, i, V[i+1]-V[i]);
        }
        update(1, 0, N-1, i, i, V[i]);
    }
    int Q;
    cin >> Q;
    while(Q--){
        int T;
        cin >> T;
        if(T==0){
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            if(a==b) cout << sum(1, 0, N-1, b, b) << "\n";
            else{
                int x=sum(1, 0, N-1, a, a);
                int y=sumgcd(1, 0, N-1, a, b-1);
                //cout << x << " " << y << "\n";
                cout << abs(__gcd(x, y)) << "\n";
            }
        }
        else{
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            if(a-1>=0) gcdupdate(1, 0, N-1, a-1, T);
            gcdupdate(1, 0, N-1, b, -T);
            update(1, 0, N-1, a, b, T);
        }
    }


    return 0;
}