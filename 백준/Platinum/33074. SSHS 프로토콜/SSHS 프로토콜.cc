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
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 1e9+7;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
DP[i]=2*i번째 조각을 끝으로 했을 때의 최소 비용
*/

vector<int> seg(200005*4, 1e18);
vector<int> lazy(200005*4, 1e18);

void LazyUpdate(int node, int start, int end){
    if(lazy[node]!=1e18){
        //cout << "lazy : " << start << " " << end << " " << lazy[node] << "\n";
        seg[node]=min(seg[node], lazy[node]);
        if(start!=end){
            lazy[node*2]=min(lazy[node*2], lazy[node]);
            lazy[node*2+1]=min(lazy[node*2+1], lazy[node]);
        }
        lazy[node]=1e18;
    }
    return;
}

void UpdateSeg(int node, int start, int end, int left, int right, long long value){
    LazyUpdate(node, start ,end);
    if(right<start||end<left) return;
    else if(left<=start&&end<=right){
        lazy[node]=min(lazy[node], value);
        LazyUpdate(node, start, end);
    }
    else{
        int mid=(start+end)/2;
        UpdateSeg(node*2, start, mid, left, right, value);
        UpdateSeg(node*2+1, mid+1, end, left, right, value);
        seg[node]=min(seg[node*2], seg[node*2+1]);
    }
    return;
}

int SumSeg(int node, int start, int end, int left, int right){
    //cout << node << " " << start << " " << end << " " << left << " " << right << "\n";
    LazyUpdate(node, start, end);
    if(right<start||end<left) return 1e18;
    else if(left<=start&&end<=right){
        //cout << seg[node] << "\n";
        return seg[node];
    }
    else{
        int mid=(start+end)>>1;
        return min(SumSeg(node*2, start, mid, left, right), SumSeg(node*2+1, mid+1, end, left, right));
    }
}

int rightzerocnt[200005];//2*i에서 가장 가까운 오른쪽 1의 위치
int leftzerocnt[200005];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    string S;
    cin >> S;
    
    int pointer=0;

    for(int i=0; i<N; i+=2){
        pointer=max(pointer, i);
        while(pointer<N&&S[pointer]=='0'){
            pointer++;
        }
        rightzerocnt[i]=pointer-i;
    }

    reverse(all(S));
    pointer=0;
    for(int i=0; i<N; i+=2){
        pointer=max(pointer, i);
        while(pointer<N&&S[pointer]=='0'){
            pointer++;
        }
        leftzerocnt[N-1-i]=pointer-i;
    }
    UpdateSeg(1, 0, N, 0, 0, 0); 
    for(int i=0; i<N; i++){
        //cout << "i : " << i << "\n";    
        if(i%2==0){
            int cur_val=SumSeg(1, 0, N, i/2, i/2);
            //cout << cur_val << " " << i/2 << " " << rightzerocnt[i] << "\n";
            UpdateSeg(1, 0, N, i/2+1, i/2+1, cur_val+1);
            //cout << i/2+rightzerocnt[i] << " " << cur_val << "\n";
            UpdateSeg(1, 0, N, i/2, i/2+rightzerocnt[i], cur_val);
        }
        else{
            if(leftzerocnt[i]>0){
                int a=SumSeg(1, 0, N, i/2-leftzerocnt[i]+1, i/2);
                //cout << leftzerocnt[i] << " " << a << "\n";
                UpdateSeg(1, 0, N, i/2+1, i/2+1, a);
            }
        }
    }
    cout << SumSeg(1, 0, N, N/2, N/2);

    return 0;
}
