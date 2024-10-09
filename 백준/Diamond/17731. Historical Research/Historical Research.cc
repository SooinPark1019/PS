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
const int MAXN = 2e5+5;
const int D = 20;

int N, sqrtn;
struct query{
    int start, end, index;
};
bool compare(query A, query B){
    if(A.start/sqrtn==B.start/sqrtn) return A.end<B.end;
    return A.start/sqrtn < B.start/sqrtn;
}//쿼리 비교함수
vector<int> V(100005);
vector<query> Q;
int ans[100005];
map<int, int> cnt;
multiset<int> MS;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A;
    cin >> N >> A;
    sqrtn=sqrt(N);
    for(int i=1; i<=N; i++){
        cin >> V[i];
    }
    for(int i=0; i<A; i++){
        int a, b;
        cin >> a >> b;
        Q.push_back({a, b, i});
    }   
    sort(all(Q), compare);
    int start=Q[0].start;
    int end=Q[0].end;
    int index=Q[0].index;
    for(int i=start; i<=end; i++){
        if(cnt[V[i]]!=0){
            auto it=MS.find(cnt[V[i]]*V[i]);
            MS.erase(it);
        }
        cnt[V[i]]++;
        MS.insert(cnt[V[i]]*V[i]);
    }
    //for(auto i : MS) cout << i << " ";
    //cout << "\n";
    ans[index]=*prev(MS.end());
    for(int i=1; i<A; i++){
        int curs=Q[i].start;
        int cure=Q[i].end;
        int curi=Q[i].index;
        //cout << curs << " " <<cure << endl;
        while(start>curs){
            start--;
            if(cnt[V[start]]!=0){
                auto it=MS.find(cnt[V[start]]*V[start]);
                if(it!=MS.end()) MS.erase(it);
            }
            cnt[V[start]]++;
            MS.insert(cnt[V[start]]*V[start]);
        }
        while(start<curs){
            auto it=MS.find(cnt[V[start]]*V[start]);
            if(it!=MS.end()) MS.erase(it);
            cnt[V[start]]--;
            if(cnt[V[start]]!=0){
                MS.insert(cnt[V[start]]*V[start]);
            }
            start++;
        }
        while(end<cure){
            end++;
            if(cnt[V[end]]!=0){
                auto it=MS.find(cnt[V[end]]*V[end]);
                if(it!=MS.end()) MS.erase(it);
            }
            cnt[V[end]]++;
            MS.insert(cnt[V[end]]*V[end]);
        }
        while(end>cure){
            auto it=MS.find(cnt[V[end]]*V[end]);
            if(it!=MS.end())MS.erase(it);
            cnt[V[end]]--;
            if(cnt[V[end]]!=0){
                MS.insert(cnt[V[end]]*V[end]);
            }
            end--;
        }
        if(MS.size()==0) ans[curi]=0;
        else ans[curi]=*prev(MS.end());
        //for(auto i : MS) cout << i << " ";
        //cout << "\n";
    }
    for(int i=0; i<A; i++) cout << ans[i] << "\n";
    return 0;
}