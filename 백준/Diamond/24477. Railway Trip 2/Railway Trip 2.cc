#include <ext/rope>
#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
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

vector<vector<pll>> seg(20, vector<pll>(400005, {1e18, -1e18}));
vector<vector<pll>> lazy(20, vector<pll>(400005, {1e18, -1e18}));

pll mergepair(pll A, pll B){
    //cout << A.first << " " << A.second << " " << B.first << " " << B.second << "\n";
    //cout << min(A.first, B.first) << " " << max(A.second, B.second) << "\n";
    return {min(A.first, B.first), max(A.second, B.second)};
}

void LazyUpdate(int node, int start, int end, int num){
    //cout << node << " " << start << " " << end << " " << num << "\n";
    //cout << lazy[num][node].first << " " << lazy[num][node].second << "\n";
    if(lazy[num][node].first!=1e18||lazy[num][node].second!=1e18){
        seg[num][node]=mergepair(seg[num][node], lazy[num][node]);
        //cout << seg[num][node].first << " " << seg[num][node].second << "\n";
        if(start!=end){
            lazy[num][node*2]=mergepair(lazy[num][node*2], lazy[num][node]);
            lazy[num][node*2+1]=mergepair(lazy[num][node*2+1], lazy[num][node]);
        }
        lazy[num][node]={1e18, -1e18};
    }   
}

void updateseg(int node, int start, int end, int num, int left, int right, ll val1, ll val2){
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

pll sumseg(int node, int start, int end, int num, int left, int right){
    //cout << node << " " << start << " " << end << " " << num << " " << seg[node][num].first << " " << seg[node][num].second << "\n";
    LazyUpdate(node, start, end, num);
    if(right<start||end<left) return {1e18, -1e18};
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

    ll N, K;
    cin >> N >> K;
    ll M;
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
            updateseg(1, 1, N, 0, a, min(a+K-1, b), 1e18, b);
        }
        else{
            updateseg(1, 1, N, 0, max(a-K+1, b), a, b, -1e18);
        }
    }

    for(int i=1; i<=N; i++){
        sparsetable[i][0]=sumseg(1, 1, N, 0, i, i);
        //cout << i << " " << sparsetable[i][0].first << " " << sparsetable[i][0].second << "\n";
    }

    for(int i=1; i<20; i++){
        for(int j=1; j<=N; j++){
            updateseg(1, 1, N, i, j, j, sparsetable[j][i-1].first, sparsetable[j][i-1].second);
        }
        for(int j=1; j<=N; j++){
            sparsetable[j][i]=sumseg(1, 1, N, i, sparsetable[j][i-1].first, sparsetable[j][i-1].second);
        }
    }

    int Q;
    cin >> Q;
    while(Q--){
        int S, T;
        cin >> S >> T;
        ll left=0;
        ll right=M+5;
        ll ans=987654321;
        while(left<=right){
            ll mid=(left+right)/2;
            ll temp=mid;
            pll a={S, S};
            int i=0;
            while(temp!=0){
                if((temp&1)!=0){
                    a=sumseg(1, 1, N, i+1, a.first, a.second);
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