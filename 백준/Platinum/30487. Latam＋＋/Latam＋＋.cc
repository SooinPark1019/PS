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

int Seg[400005*4];
vector<int> lazy(400005*4, -1);

void LazyUpdate(int node, int start, int end){
    if(lazy[node]!=-1){
        Seg[node]=lazy[node];
        if(start!=end){
            lazy[node*2]=lazy[node];
            lazy[node*2+1]=lazy[node];
        }
        lazy[node]=-1;
    }
    return;
}

void UpdateSeg(int node, int start, int end, int left, int right, long long value){
    LazyUpdate(node, start ,end);
    if(right<start||end<left) return;
    else if(left<=start&&end<=right){
        lazy[node]=value;
        LazyUpdate(node, start, end);
    }
    else{
        int mid=(start+end)/2;
        UpdateSeg(node*2, start, mid, left, right, value);
        UpdateSeg(node*2+1, mid+1, end, left, right, value);
        Seg[node]=Seg[node*2]+Seg[node*2+1];
    }
    return;
}

long long SumSeg(int node, int start, int end, int left, int right){
    LazyUpdate(node, start, end);
    if(right<start||end<left) return 0;
    else if(left<=start&&end<=right){
        return Seg[node];
    }
    else{
        int mid=(start+end)/2;
        return SumSeg(node*2, start, mid, left, right)+SumSeg(node*2+1, mid+1, end, left, right);
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;
    cin >> S;
    int ans=0;
    int cur=200000;
    int flag=0;
    for(int i=0; i<S.length(); i++){
        if(S[i]=='+'||S[i]=='*'||S[i]=='-'||S[i]=='/'){
            if(S[i-1]=='+'||S[i-1]=='*'||S[i-1]=='-'||S[i-1]=='/'||S[i-1]=='('){
                UpdateSeg(1, 0, 400000, 0, 400000, 0);
            }
            continue;
        }
        else if(S[i]=='('){
            flag=0;
            if(i>0&&S[i-1]!='+'&&S[i-1]!='-'&&S[i-1]!='*'&&S[i-1]!='/'&&S[i-1]!='(') UpdateSeg(1, 0, 400000, 0, 400000, 0);
            UpdateSeg(1, 0, 400000, cur, cur, SumSeg(1, 0, 400000, cur, cur)+1);
            cur++;
            continue;
        }
        else if(S[i]==')'){
            UpdateSeg(1, 0, 400000, cur, cur, 0);
            cur--;
            if(flag==0||S[i-1]=='+'||S[i-1]=='-'||S[i-1]=='*'||S[i-1]=='/') UpdateSeg(1, 0, 400000, 0, 400000, 0);
        }   
        else{
            if(i>0&&S[i-1]==')') UpdateSeg(1, 0, 400000, 0, 400000, 0);
            flag=1;
            UpdateSeg(1, 0, 400000, cur, cur, SumSeg(1, 0, 400000, cur, cur)+1);
        }
        ans+=SumSeg(1, 0, 400000, cur, cur);
        //cout << i << " " << cur << " " << ans << "\n";
    }
    cout << ans;
    
    return 0;
}