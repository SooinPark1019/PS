#include <bits/stdc++.h>
//#define int long long
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

//const int INF=1e18;

using namespace std;

vector<int> seg;

void update_seg(int node, int start, int end, int index, int val){
    if(index<start||end<index) return;
    if(start==end) seg[node]+=val;
    else{
        int mid=(start+end)>>1;
        update_seg(node*2, start, mid, index, val);
        update_seg(node*2+1, mid+1, end, index, val);
        seg[node]=min(seg[node*2], seg[node*2+1]);
    }
    return;
}

int sum_seg(int node, int start, int end, int left, int right){
    if(right<start||end<left) return 1e18;
    if(left<=start&&end<=right) return seg[node];
    int mid=(start+end)>>1;
    return min(sum_seg(node*2, start, mid, left, right), sum_seg(node*2+1, mid+1, end, left, right));
}

int N, M;
multiset<int> MS;
map<int, int> dict;
vector<int> V;
vector<int> cnt;
vector<int> X;
int maxcnt=0;

bool compare(int a, int b){
    return a%M>b%M;
}

int find_leftans(int node, int start, int end, int index){
    if(seg[node]!=0) return start;
    if(start==end) return -1;
    int mid=(start+end)>>1;
    if(mid+1>index) return find_leftans(node*2, start, mid, index);
    int a=find_leftans(node*2+1, mid+1, end, index);
    if(a==mid+1){
        int b=find_leftans(node*2, start, mid, index);
        if(b==-1) return mid+1;
        else return b;
    }
    else return a;
}

int find_rightans(int node, int start, int end, int index){
    //cout << "node : " << node << " start : " << start << " end : " << end << " index : " << index << " seg : " << seg[node] << "\n";
    if(seg[node]!=0) return end;
    if(start==end) return -1;
    int mid=(start+end)>>1;
    if(mid<index) return find_rightans(node*2+1, mid+1, end, index);
    int a=find_rightans(node*2, start, mid, index);
    if(a==mid){
        int b=find_rightans(node*2+1, mid+1, end, index);
        if(b==-1) return mid;
        else return b;
    }
    else return a;
}

void element_erase(int i){
    cnt[i]--;
    update_seg(1, 0, maxcnt, i, -1);
    if(cnt[i]==0){
        int leftans=find_leftans(1, 0, maxcnt, i-1);
        int rightans=find_rightans(1, 0, maxcnt, i+1);
        if(leftans==-1) leftans=i;
        if(rightans==-1) rightans=i;
        if(MS.find(rightans-leftans+1)!=MS.end())MS.erase(MS.find(rightans-leftans+1));
        MS.insert(rightans-i);
        MS.insert(i-leftans);
    }
}


void element_insert(int i){
    //cout << "i : " << i << "\n";
    cnt[i]++;
    update_seg(1, 0, maxcnt, i, 1);
    if(cnt[i]==1){
        int leftans=find_leftans(1, 0, maxcnt, i-1);
        int rightans=find_rightans(1, 0, maxcnt, i+1);
        if(leftans==-1) leftans=i;
        if(rightans==-1) rightans=i;
        //cout << "leftans : " << leftans << " rightans : " << rightans << "\n";
        if(MS.find(i-leftans)!=MS.end())MS.erase(MS.find(i-leftans));
        if(MS.find(rightans-i)!=MS.end())MS.erase(MS.find(rightans-i));
        MS.insert(rightans-leftans+1);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--){
        cin >> N >> M;
        MS.clear();
        dict.clear();
        V.clear();
        X.clear();
        cnt.clear();
        seg.clear();
        maxcnt=0;
        for(int i=0; i<N; i++){
            int a;
            cin >> a;
            V.push_back(a);
            X.push_back(a/M);
            X.push_back(a/M+1);
        }
        sort(all(V), compare);
        //for(auto i : V) cout << i << " ";
        //cout << endl;
        sort(all(X));
        X.erase(unique(all(X)), X.end());
        for(int i=0; i<X.size(); i++){
            if(i!=0&&X[i-1]+1!=X[i]) maxcnt++;
            dict[X[i]]=maxcnt;
            maxcnt++;
        }
        cnt.resize(maxcnt+5, 0);
        seg.resize((maxcnt+5)*4, 0);
        for(auto i : V){
            element_insert(dict[i/M]);
        }
        MS.insert(0);
        assert(MS.size()>0);
        int ans=*prev(MS.end());
        int ansarg=0;
        //cout << "MS : \n";
        //for(auto i : MS) cout << i << " ";
        //cout << "\n";
        //cout << ans << " " << ansarg << endl;
        for(int i=0; i<N; i++){
            //cout << "i : " << i << " V[i] : " << V[i] << endl;
            element_erase(dict[V[i]/M]);
            element_insert(dict[V[i]/M+1]);
            while(i+1<N&&V[i+1]%M==V[i]%M){
                i++;
                element_erase(dict[V[i]/M]);
                element_insert(dict[V[i]/M+1]);
            }
            //cout << "MS : \n";
            //for(auto i : MS) cout << i << " ";
            //cout << "\n";
            assert(MS.size()>0);
            if(ans<*prev(MS.end())){
                ans=*prev(MS.end());
                ansarg=M-V[i]%M;
            }
        }
        cout << ans << " " << ansarg << "\n";
    }
}
