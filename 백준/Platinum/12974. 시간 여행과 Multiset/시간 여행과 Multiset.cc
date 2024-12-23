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
#define sz(x) (int)x.size()

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
typedef complex<double> cpx;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 10007;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
값을 기준으로 좌표압축
같은 값이 쿼리들만 묶는다
하나씩 처리하면서 펜윅
*/
vector<long long> Fenwick;

void update(int index, long long value){
    while(index<Fenwick.size()){
        Fenwick[index]+=value;
        index+=index&(-index);
    }
    return;
}
long long sum(int index){
    long long ret=0;
    while(index>0){
        ret+=Fenwick[index];
        index-=index&(-index);
    }
    return ret;
}

struct query{
    int a, t, i;
};

bool compare(query A, query B){
    return A.t<B.t;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    map<int, vector<query>> M;
    for(int i=0; i<N; i++){
        int a, b, c;
        cin >> a >> b >> c;
        M[c].push_back({a, b, i});
    }

    vector<pii> ans;

    for(auto p : M){
        vector<query> temp=p.second;
        vector<int> X;
        for(auto q : temp){
            X.push_back(q.t);
        }
        zip(X);
        map<int, int> dict;
        for(int i=0; i<X.size(); i++){
            dict[X[i]]=i+1;
        }
        Fenwick.clear();
        Fenwick.resize(X.size()+1);
        for(auto q : temp){
            if(q.a==1){
                update(dict[q.t], 1);
            }
            else if(q.a==2){
                update(dict[q.t], -1);
            }
            else{
                ans.push_back({q.i, sum(dict[q.t])});
            }
        }
    }

    sort(all(ans));
    
    for(auto p : ans) cout << p.second << "\n";

    return 0;
}
