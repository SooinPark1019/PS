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
#define sz(x) (int)x.size()

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
typedef complex<double> cpx;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 10007;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
만약 (가 )로 바뀌었다고 치자
그러면 그냥 가장 왼쪽의 )를 (로 바꿔주면 된다

반대의 경우는 어떻게 할까?
무턱대고 가장 왼쪽거를 바꾸면 안된다

해당 괄호를 바꿈으로써 해당 위치부터 반대쪽의 괄호값에 모두 -2가 들어가기 때문에 괄호값의 누적합의 최소가 2 이상이어야 한다
*/

vector<long long> Seg(300005*4, 0);
vector<long long> lazy(300005*4, 0);

void LazyUpdate(int node, int start, int end){
    if(lazy[node]!=0){
        Seg[node]+=lazy[node];
        if(start!=end){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    return;
}

void UpdateSeg(int node, int start, int end, int left, int right, long long value){
    LazyUpdate(node, start ,end);
    if(right<start||end<left) return;
    else if(left<=start&&end<=right){
        lazy[node]+=value;
        LazyUpdate(node, start, end);
    }
    else{
        int mid=(start+end)/2;
        UpdateSeg(node*2, start, mid, left, right, value);
        UpdateSeg(node*2+1, mid+1, end, left, right, value);
        Seg[node]=min(Seg[node*2], Seg[node*2+1]);
    }
    return;
}

long long SumSeg(int node, int start, int end, int left, int right){
    LazyUpdate(node, start, end);
    if(right<start||end<left) return 1e18;
    else if(left<=start&&end<=right){
        return Seg[node];
    }
    else{
        int mid=(start+end)/2;
        return min(SumSeg(node*2, start, mid, left, right), SumSeg(node*2+1, mid+1, end, left, right));
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, Q;

    cin >> N >> Q;
    string S;
    cin >> S;
    set<int> endpar;
    for(int i=0; i<N; i++){
        if(S[i]=='(') UpdateSeg(1, 0, N-1, i, N-1, 1);
        else{
            UpdateSeg(1, 0, N-1, i, N-1, -1);
            endpar.insert(i);
        } 
    }

    while(Q--){
        int index;
        cin >> index;
        index--;
        if(S[index]=='('){
            S[index]=')';
            UpdateSeg(1, 0, N-1, index, N-1, -2);
            endpar.insert(index);
            int a=*endpar.begin();
            endpar.erase(a);
            S[a]='(';
            UpdateSeg(1, 0, N-1, a, N-1, 2);
            cout << a+1 << "\n";
        }
        else{
            S[index]='(';
            UpdateSeg(1, 0, N-1, index, N-1, 2);
            endpar.erase(index);
            int left=0;
            int right=N-1;
            int ans=N-1;
            while(left<=right){
                int mid=(left+right)>>1;
                if(SumSeg(1, 0, N-1, mid, N-1)<2){
                    left=mid+1;
                }
                else{
                    ans=min(ans, mid);
                    right=mid-1;
                }
            }
            S[ans]=')';
            endpar.insert(ans);
            UpdateSeg(1, 0, N-1, ans, N-1, -2);
            cout << ans+1 << "\n";
        }
    }

    return 0;
}
