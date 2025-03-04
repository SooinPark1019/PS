#include <ext/rope>
#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#define P pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;
const int MAX=500005;

pair<vector<int>, vector<int>> SuffixArray(const string &s){ // O(N log N)
  int n = s.size(), m = max(n, 256);
  vector<int> sa(n), lcp(n), pos(n), tmp(n), cnt(m);
  auto counting_sort = [&](){
    fill(cnt.begin(), cnt.end(), 0);
    for(int i=0; i<n; i++) cnt[pos[i]]++;
    partial_sum(cnt.begin(), cnt.end(), cnt.begin());
    for(int i=n-1; i>=0; i--) sa[--cnt[pos[tmp[i]]]] = tmp[i];
  };
  for(int i=0; i<n; i++) sa[i] = i, pos[i] = s[i], tmp[i] = i;
  counting_sort();
  for(int k=1; ; k<<=1){
    int p = 0;
    for(int i=n-k; i<n; i++) tmp[p++] = i;
    for(int i=0; i<n; i++) if(sa[i] >= k) tmp[p++] = sa[i] - k;
    counting_sort();
    tmp[sa[0]] = 0;
    for(int i=1; i<n; i++){
      tmp[sa[i]] = tmp[sa[i-1]];
      if(sa[i-1]+k < n && sa[i]+k < n && pos[sa[i-1]] == pos[sa[i]] && pos[sa[i-1]+k] == pos[sa[i]+k]) continue;
      tmp[sa[i]] += 1;
    }
    swap(pos, tmp); if(pos[sa.back()] + 1 == n) break;
  }
  for(int i=0, j=0; i<n; i++, j=max(j-1,0)){
    if(pos[i] == 0) continue;
    while(sa[pos[i]-1]+j < n && sa[pos[i]]+j < n && s[sa[pos[i]-1]+j] == s[sa[pos[i]]+j]) j++;
    lcp[pos[i]] = j;
  }
  return {sa, lcp};
}

int lcs[MAX];
int prefix[MAX];

vector<pll> seg;

void update_seg(int node, int start, int end, int index, long long diff){
    if(index<start||index>end) return;
    if(start==end)seg[node]={diff, 1};
    if(start!=end){
        int mid=(start+end)/2;
        update_seg(node*2, start, mid, index, diff);
        update_seg(node*2+1, mid+1, end, index, diff);
        if(seg[node*2].first==seg[node*2+1].first){
            seg[node]={seg[node*2].first, seg[node*2].second+seg[node*2+1].second};
        }
        else{
            seg[node]=min(seg[node*2], seg[node*2+1]);
        }
    }
    return;
}

pll sum_seg(int node, int start, int end, int left, int right){
    if(left>end||right<start) return {INF, 0};
    if(left<=start&&end<=right) return seg[node];
    int mid=(start+end)/2;
    pll A=sum_seg(node*2, start, mid, left, right);
    pll B=sum_seg(node*2+1, mid+1, end, left, right);
    if(A.first==B.first) return {A.first, A.second+B.second};
    else return min(A, B);
}

int maxindex[MAX];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int TC;
    cin >> TC;
    while(TC--){
        string A, B;
        cin >> A >> B;
        string S=A+"@"+B;
        ll K;
        cin >> K;
        vector<int> sa;
        vector<int> lcp;
        for(int i=0; i<A.length(); i++){
            lcs[i]=0;
            prefix[i]=0;
        }

        tie(sa, lcp)=SuffixArray(S);
        int temp=0;
        for(int i=0; i<S.length(); i++){
            if(sa[i]>A.length()) temp=S.length()-sa[i];
            else if(sa[i]<A.length()){
                temp=min(temp, lcp[i]);
                lcs[sa[i]]=max(lcs[sa[i]], temp);
            }
        }
        temp=0;
        for(int i=S.length()-1; i>=0; i--){
            if(sa[i]>A.length()) temp=S.length()-sa[i];
            else if(sa[i]<A.length()){
                if(i!=S.length()-1) temp=min(temp, lcp[i+1]);
                lcs[sa[i]]=max(lcs[sa[i]], temp);
            }
        }
        /*for(int i=0; i<A.length(); i++) cout << lcs[i] << " ";
        cout << "\n";*/
        S=A;
        tie(sa, lcp)=SuffixArray(S);

        for(int i=0; i<A.length(); i++){
            if(i!=0) prefix[i]=prefix[i-1];
            if(A[i]=='(') prefix[i]++;
            else prefix[i]--;
        }
        seg.clear();
        seg.resize(4*A.length()+5);
        for(int i=0; i<A.length(); i++){
            update_seg(1, 0, A.length(), i, prefix[i]);
        }
        memset(maxindex, -1, sizeof(int)*(A.length()+2));
        for(int i=0; i<A.length(); i++){
            int a;
            if(i==0) a=0;
            else a=prefix[i-1];
            if(A[i]==')') continue;
            int left=i;
            int right=A.length()-1;
            int ans=i;
            while(left<=right){
                int mid=(left+right)/2;
                if(sum_seg(1, 0, A.length(), i, mid).first<a){
                    right=mid-1;
                }
                else{
                    ans=max(ans, mid);
                    left=mid+1;
                }
            }
            maxindex[i]=ans;
        }
        /*for(int i=0; i<A.length(); i++){
            cout << maxindex[i] << " ";
        }
        cout << "\n";*/
        ll cnt=0;
        for(int i=0; i<A.length(); i++){
            int cur=sa[i];
            if(maxindex[cur]==-1) continue;
            //cout << "cur : " << cur << "\n";
            //cout << "nxt : " << min(maxindex[cur], cur+lcs[cur]-1) << "\n";
            ll a; 
            if(cur==0) a=0;
            else a=prefix[cur-1];
            //cout << a << "\n";
            int b=0;
            //cout << "cur+b : " << cur+b << "\n";
            if(i!=0) b=lcp[i];
            if(min(maxindex[cur], cur+lcs[cur]-1)<cur+b){
                continue;
            }
            else{
                /*for(int i=cur; i<=min(maxindex[cur], cur+lcs[cur]-1); i++){
                    cout << A[i];
                }
                cout << "\n";*/
                pll mi=sum_seg(1, 0, A.length(), cur+b, min(maxindex[cur], cur+lcs[cur]-1));
                //cout << mi.first << " " << mi.second << " " << cnt << "\n";
                if(mi.first!=a) continue;
                if(mi.second+cnt<K) cnt+=mi.second;
                else{
                    for(int j=cur+b; j<=min(maxindex[cur], cur+lcs[cur]-1); j++){
                        //cout << "j : " << j << " prefix : " << prefix[j] << "\n";
                        if(prefix[j]<a) break;
                        if(prefix[j]==a){
                            //cout << "j : " << j << "\n";
                            cnt++;
                            if(cnt==K){
                                for(int k=cur; k<=j; k++) cout << A[k];
                                cout << "\n";
                                break;
                            }
                        }
                    }
                }
                //cout << "cnt : " << cnt << endl;
            }
            if(cnt==K) break;
        }
        //cout << cnt << "\n";
        if(cnt<K) cout << -1 << "\n";
    }
    return 0;
}

