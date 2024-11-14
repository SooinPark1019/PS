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
const int D = 20;

/*
1을 루트로 하는 트리를 생각하자
엘리스는 부모로 올라갈 것이고
퀸은 리프와의 최단 경로로 끌어내릴 것이다
각 정점마다 부모와의 거리, 리프와의 최단 경로를 적어 두자
*/
vector<int> seg(200005*4, 1e18);
vector<int> lazy(200005*4, 1e18);

void LazyUpdate(int node, int start, int end){
    if(lazy[node]!=1e18){
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

long long SumSeg(int node, int start, int end, int left, int right){
    LazyUpdate(node, start, end);
    if(right<start||end<left) return 1e18;
    else if(left<=start&&end<=right){
        return seg[node];
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
    
    int N, M;
    cin >> N >> M;
    vector<int> V(N+1);
    for(int i=1; i<=N; i++){
        cin >> V[i];
    }
    vector<pii> temp;
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        temp.push_back({a, b});
    }
    sort(all(temp));
    vector<pii> E;
    for(int i=M-1; i>=0; i--){
        if(E.size()==0||E.back().second>temp[i].second){
            E.push_back(temp[i]);
        }
    }
    reverse(all(E));
    UpdateSeg(1, 1, N+1, E[0].first, E[0].second, 0);
    for(int i=1; i<=N; i++){
        //cout << "i : " << i << "\n";
        int curcost=SumSeg(1, 1, N+1, i, i);
        //cout << curcost << "\n";
        if(curcost==1e18) continue;
        int left=0;
        int right=E.size()-1;
        int ans=E.size();
        while(left<=right){
            int mid=(left+right)/2;
            if(E[mid].first>i){
                ans=min(ans, mid);
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        //cout << ans << "\n";
        if(ans==E.size()) UpdateSeg(1, 1, N+1, 0, N+1, curcost+V[i]);
        else{
            UpdateSeg(1, 1, N+1, 0, E[ans].second, curcost+V[i]);
        }
    }
    cout << SumSeg(1, 1, N+1, N+1, N+1);
    return 0;
}