#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
//#pragma GCC optimize ("O3")
//#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;

vector<long long> Seg(120005, 0);
vector<long long> cnt(120005, 0);

struct query{
    long long flag, x, y1, y2;
};

bool compare(query A, query B){
    return A.x<B.x;
}

void UpdateSeg(int node, int start, int end, int left, int right, long long value){
    if(right<start||end<left) return;
    else if(left<=start&&end<=right) cnt[node]+=value;
    else{
        int mid=(start+end)/2;
        UpdateSeg(node*2, start, mid, left, right, value);
        UpdateSeg(node*2+1, mid+1, end, left, right, value);
    }
    if(cnt[node]>=1) Seg[node]=end-start+1;
    else{
        if(start==end) Seg[node]=0;
        else Seg[node]=Seg[node*2]+Seg[node*2+1];
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<query> queryvector;
    for(int i=0; i<N; i++){
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        queryvector.push_back({1, x1, y1, y2});
        queryvector.push_back({-1, x2, y1, y2});
    }
    sort(queryvector.begin(), queryvector.end(), compare);
    long long ans=0;
    for(int i=0; i<queryvector.size(); i++){
        if(i!=0) ans+=Seg[1]*(queryvector[i].x-queryvector[i-1].x);
        UpdateSeg(1, 0, 30000, queryvector[i].y1+1, queryvector[i].y2, queryvector[i].flag);
    }
    cout << ans;

    return 0;
}
