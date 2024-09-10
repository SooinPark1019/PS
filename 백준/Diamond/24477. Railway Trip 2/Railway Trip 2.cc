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
//#define int long long

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;

vector<vector<pii>> seg(20, vector<pii>(400005, {1e9, -1e9}));
vector<vector<pii>> lazy(20, vector<pii>(400005, {1e9, -1e9}));

inline pii mergepair(pii A, pii B){
    return {min(A.first, B.first), max(A.second, B.second)};
}

void LazyUpdate(int node, int start, int end, int num){
    //cout << node << " " << start << " " << end << " " << num << "\n";
    //cout << lazy[num][node].first << " " << lazy[num][node].second << "\n";
    if(lazy[num][node].first!=1e9||lazy[num][node].second!=-1e9){
        seg[num][node]=mergepair(seg[num][node], lazy[num][node]);
        //cout << seg[num][node].first << " " << seg[num][node].second << "\n";
        if(start!=end){
            lazy[num][node*2]=mergepair(lazy[num][node*2], lazy[num][node]);
            lazy[num][node*2+1]=mergepair(lazy[num][node*2+1], lazy[num][node]);
        }
        lazy[num][node]={1e9, -1e9};
    }   
}

void updateseg(int node, int start, int end, int num, int left, int right, int val1, int val2){
    LazyUpdate(node, start, end, num);
    if(right<start||end<left) return;
    else if(left<=start&&end<=right){
        lazy[num][node]=mergepair(lazy[num][node], {val1, val2});
        //cout << lazy[num][node].first << " " << lazy[num][node].second << "\n";
        LazyUpdate(node, start, end, num);
        //cout << node << " " << seg[num][node].first << " " << seg[num][node].second << "\n";
    }
    else{
        int mid=(start+end)/2;
        updateseg(node*2, start, mid, num, left, right, val1, val2);
        updateseg(node*2+1, mid+1, end, num, left, right, val1, val2);
        seg[num][node]=mergepair(seg[num][node], mergepair(seg[num][node*2], seg[num][node*2+1]));
    }
    return;
}

pii sumseg(int node, int start, int end, int num, int left, int right){
    //cout << node << " " << start << " " << end << " " << num << " " << seg[node][num].first << " " << seg[node][num].second << "\n";
    LazyUpdate(node, start, end, num);
    if(right<start||end<left) return {1e9, -1e9};
    else if(left<=start&&end<=right){
        //cout << node << " " << start << " " << end << " " << num << " " << seg[num][num].first << " " << seg[node][num].second << "\n";
        return seg[num][node];
    }
    else{
        int mid=(start+end)/2;
        return mergepair(sumseg(node*2, start, mid, num, left, right), sumseg(node*2+1, mid+1, end, num, left, right));
    }
}   

pll sparsetable[100005][20];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    int M;
    cin >> M;

    for(int i=0; i<20; i++){
        for(int j=1; j<=N; j++){
            updateseg(1, 1, N, i, j, j, j, j);
            //cout << seg[0][8].first << " " << seg[0][8].second << "\n";
            //cout << i << " " << j << " " << sumseg(1, 1, N, i, j, j).first << " " << sumseg(1, 1, N, i, j, j).second << "\n";
        }
    }

    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        if(a<b){
            updateseg(1, 1, N, 0, a, min(a+K-1, b), 1e9, b);
        }
        else{
            updateseg(1, 1, N, 0, max(a-K+1, b), a, b, -1e9);
        }
    }

    for(int i=1; i<=N; i++){
        sparsetable[i][0]=sumseg(1, 1, N, 0, i, i);
        //cout << i << " " << sparsetable[i][0].first << " " << sparsetable[i][0].second << "\n";
    }

    for(int i=1; i<20; i++){
        for(int j=1; j<=N; j++){
            sparsetable[j][i]=sumseg(1, 1, N, i-1, sparsetable[j][i-1].first, sparsetable[j][i-1].second);
        }
        for(int j=1; j<=N; j++){
            updateseg(1, 1, N, i, j, j, sparsetable[j][i].first, sparsetable[j][i].second);
        }
    }

    int Q;
    cin >> Q;
    while(Q--){
        int S, T;
        cin >> S >> T;
        int left=0;
        int right=M+5;
        int ans=987654321;
        while(left<=right){
            int mid=(left+right)/2;
            int temp=mid;
            pll a={S, S};
            int i=0;
            while(temp!=0){
                if((temp&1)!=0){
                    a=sumseg(1, 1, N, i, a.first, a.second);
                }
                i++;
                temp>>=1;
            }
            if(a.first<=T&&T<=a.second){
                ans=min(ans, mid);
                right=mid-1;
            }
            else left=mid+1;
        }
        if(ans==987654321) cout << -1 << "\n";
        else cout << ans << "\n";
    }

    return 0;
}