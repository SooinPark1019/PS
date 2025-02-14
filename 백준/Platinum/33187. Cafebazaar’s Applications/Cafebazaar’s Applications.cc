#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

using namespace std;

vector<int> lazy;
vector<int> seg;

void lazy_update(int node, int start, int end){
    if(lazy[node]!=0){
        seg[node]+=lazy[node];
        if(start!=end){
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
}

void update_seg(int node, int start, int end, int left, int right, int value){
    lazy_update(node, start, end);
    if(right<start||end<left) return;
    if(left<=start&&end<=right){
        lazy[node]+=value;
        lazy_update(node, start, end);
    }
    else{
        int mid=(start+end)>>1;
        update_seg(node*2, start, mid, left, right, value);
        update_seg(node*2+1, mid+1, end, left, right, value);
        seg[node]=max(seg[node*2], seg[node*2+1]);
    }
}

int sum_seg(int node, int start, int end, int left, int right){
    lazy_update(node, start, end);
    if(right<start||end<left) return 0;
    if(left<=start&&end<=right) return seg[node];
    else{
        int mid=(start+end)>>1;
        return max(sum_seg(node*2, start, mid, left, right), sum_seg(node*2+1, mid+1, end, left, right));
    }
}
int ans[100005];
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    seg.resize(4*N+5);
    lazy.resize(4*N+5);

    vector<pii> V;
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        V.push_back({a, i});
    }
    sort(all(V));
    vector<pii> temp;

    for(int i=0; i<V.size(); i++){
        int a=V[i].first;
        int index=V[i].second;
        if(i>0&&a!=V[i-1].first){
            for(auto p : temp){
                ans[p.second]=K-sum_seg(1, 0, N-1, max(0ll, p.second-K+1), p.second)+1;
            }
            temp.clear();
        }
        update_seg(1, 0, N-1, max(0ll, index-K+1), index, 1);
        temp.push_back({a, index});
    }
    for(auto p : temp){
        //cout << p.first << " " << p.second << "\n";
        ans[p.second]=K-sum_seg(1, 0, N-1, max(0ll, p.second-K+1), p.second)+1;
    }
    for(int i=0; i<N; i++) cout << ans[i] << " ";
}