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
DP[i]=첫번째 재료의 가치가 i일 때 두번째 재료의 가능한 최대 가치

두 차원 모두 양수인 거는 당연히 그대로 합치고
그렇지 않을 경우 취할 차원을 선택

나머지는 취할 차원만 취하거나 아니면 둘다 취해야 함
*/

vector<int> minseg;
vector<int> minlazy;
vector<int> maxseg;
vector<int> maxlazy;
vector<int> sumseg;

int S[500005], T[500005];

void minlazy_update(int node, int start, int end){
    if(minlazy[node]!=1e18){
        minseg[node]=min(minseg[node], minlazy[node]);
        if(start!=end){
            minlazy[node*2]=min(minlazy[node*2], minlazy[node]);
            minlazy[node*2+1]=min(minlazy[node*2+1], minlazy[node]);
        }
        minlazy[node]=1e18;
    }
}

void maxlazy_update(int node, int start, int end){
    if(maxlazy[node]!=-1e18){
        maxseg[node]=max(maxseg[node], maxlazy[node]);
        if(start!=end){
            maxlazy[node*2]=max(maxlazy[node*2], maxlazy[node]);
            maxlazy[node*2+1]=max(maxlazy[node*2+1], maxlazy[node]);
        }
        maxlazy[node]=-1e18;
    }
}

void minseg_update(int node, int start, int end, int left, int right, int value){
    minlazy_update(node, start, end);
    if(right<start||end<left) return;
    else if(left<=start&&end<=right){
        minlazy[node]=min(minlazy[node], value);
        minlazy_update(node, start, end);
    }
    else{
        int mid=(start+end)>>1;
        minseg_update(node*2, start, mid, left, right, value);
        minseg_update(node*2+1, mid+1, end, left, right, value);
        minseg[node]=min(minseg[node*2], minseg[node*2+1]);
    }
}

int range_min(int node, int start, int end, int left, int right){
    minlazy_update(node, start, end);
    if(right<start||end<left) return 1e18;
    if(left<=start&&end<=right) return minseg[node];
    int mid=(start+end)>>1;
    return min(range_min(node*2, start, mid, left, right), range_min(node*2+1, mid+1, end, left, right));
}

void maxseg_update(int node, int start, int end, int left, int right, int value){
    maxlazy_update(node, start, end);
    if(right<start||end<left) return;
    else if(left<=start&&end<=right){
        maxlazy[node]=max(maxlazy[node], value);
        maxlazy_update(node, start, end);
    }
    else{
        int mid=(start+end)>>1;
        maxseg_update(node*2, start, mid, left, right, value);
        maxseg_update(node*2+1, mid+1, end, left, right, value);
        maxseg[node]=max(maxseg[node*2], maxseg[node*2+1]);
    }
}

int range_max(int node, int start, int end, int left, int right){
    maxlazy_update(node, start, end);
    if(right<start||end<left) return -1e18;
    if(left<=start&&end<=right) return maxseg[node];
    int mid=(start+end)>>1;
    return max(range_max(node*2, start, mid, left, right), range_max(node*2+1, mid+1, end, left, right));
}

void sumseg_update(int node, int start, int end, int index, int value){
    if(index<start||end<index) return;
    if(start==end) sumseg[node]+=value;
    else{
        int mid=(start+end)>>1;
        sumseg_update(node*2, start, mid, index, value);
        sumseg_update(node*2+1, mid+1, end, index, value);
        sumseg[node]=sumseg[node*2]+sumseg[node*2+1];
    }
}

int range_sum(int node, int start, int end, int left, int right){
    if(right<start||end<left) return 0;
    if(left<=start&&end<=right) return sumseg[node];
    int mid=(start+end)>>1;
    return range_sum(node*2, start, mid, left, right)+range_sum(node*2+1, mid+1, end, left, right);
}

struct query{
    int l, r, i;
};

bool compare(query A, query B){
    return A.l<B.l;
}

vector<int> Sval[1000005];
int ans[200005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N+1);
    vector<int> B(N+1);

    for(int i=1; i<=N; i++){
        cin >> A[i];
    }

    for(int i=1; i<=N; i++){
        cin >> B[i];
    }

    minseg.resize(8*N+5, 1e18);
    minlazy.resize(8*N+5, 1e18);
    maxseg.resize(8*N+5, -1e18);
    maxlazy.resize(8*N+5, -1e18);
    sumseg.resize(4*N+5, 0);

    for(int i=1; i<=N; i++){
        int a=range_max(1, 0, 2*N, B[i], A[i]);
        if(a==-1e18) S[i]=0;
        else S[i]=a;
        Sval[S[i]].push_back(i);
        maxseg_update(1, 0, 2*N, B[i], A[i], i);
    }

    for(int i=N; i>=1; i--){
        int a=range_min(1, 0, 2*N, B[i], A[i]);
        if(a==1e18) T[i]=N+1;
        else T[i]=a;
        minseg_update(1, 0, 2*N, B[i], A[i], i);
    }

    //for(int i=1; i<=N; i++) cout << S[i] << " ";
    //cout << "\n";
    //for(int i=1; i<=N; i++) cout << T[i] << " ";
    //cout << "\n";

    int Q;
    cin >> Q;
    vector<query> V;
    for(int i=0; i<Q; i++){
        int l, r;
        cin >> l >> r;
        V.push_back({l, r, i});
    }
    sort(all(V), compare);
    
    int curl=0;
    for(auto q : V){
        int l=q.l;
        int r=q.r;
        int i=q.i;

        //cout << "l : " << l << " r : " << r << " i : " << i << "\n";

        while(curl<l){
            if(curl>0){
                //cout << "curl : " << curl << " T[curl] : " << T[curl] << "\n";
                sumseg_update(1, 0, N, curl, -1);
                sumseg_update(1, 0, N, T[curl], 1);
            }
            for(auto i : Sval[curl]){
                //cout << "i : " << i << " T[i] : " << T[i] << "\n";
                sumseg_update(1, 0, N, i, 1);
                sumseg_update(1, 0, N, T[i], -1);
            }
            curl++;
        }
        int a=range_sum(1, 0, N, 0, r);
        //cout << a << "\n";
        if(a>0) ans[i]=0;
        else ans[i]=1;
    }

    for(int i=0; i<Q; i++){
        if(ans[i]) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
