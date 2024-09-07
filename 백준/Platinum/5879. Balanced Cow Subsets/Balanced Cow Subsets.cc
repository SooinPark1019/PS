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

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;

void fillsum(vector<ll>& A, vector<pll>& sum){
    for(int i=0; i<(1<<A.size()); i++){
        //cout << "i : " << i << "\n";
        for(int j=0; j<=i; j++){
            if((i|j)==i){
                ll a=0;
                //cout << "j : " << j << "\n";
                //cout << i << " " << j << "\n";
                for(int k=0; k<A.size(); k++){
                    if((j&(1<<k))!=0) a-=A[k];
                    else if((i&(1<<k))!=0) a+=A[k];
                }
                //cout << a << " " << i << "\n";
                if(a>=0) sum.push_back({a, i});
            }
        }
    }
}

vector<int> check(1<<20);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<ll> A;
    vector<ll> B;
    for(int i=0; i<N/2; i++){
        ll a;
        cin >> a;
        A.push_back(a);
    }
    for(int i=N/2; i<N; i++){
        ll a;
        cin >> a;
        B.push_back(a);
    }
    vector<pll> sumA;
    vector<pll> sumB;
    fillsum(A, sumA);
    fillsum(B, sumB);

    sort(all(sumA));
    sort(all(sumB));


    /*for(auto i : sumA) cout << i.first << " ";
    cout << "\n";
    for(auto i : sumB) cout << i.first << " ";
    cout << "\n";*/

    //vector<int> check(1<<N);

    sumA.erase(unique(all(sumA)), sumA.end());
    sumB.erase(unique(all(sumB)), sumB.end());

    int pointerA=0;
    int pointerB=0;

    //cout << sumA.size() << " " << sumB.size() << "\n";

    while(pointerA<sumA.size()&&pointerB<sumB.size()){
        if(sumA[pointerA].first<sumB[pointerB].first) pointerA++;
        else if(sumA[pointerA].first>sumB[pointerB].first) pointerB++;
        else{
            //cout << "sumA : " << sumA[pointerA].first << "\n";
            //cout << "pointer A : " << pointerA << " pointerB : " << pointerB << "\n";
            int endA=pointerA+1;
            int endB=pointerB+1;
            while(endA<sumA.size()&&sumA[pointerA].first==sumA[endA].first) endA++;
            while(endB<sumB.size()&&sumB[pointerB].first==sumB[endB].first) endB++;
            //cout << "endA : " << endA << " endB : " << endB << "\n";
            for(int i=pointerA; i<endA; i++){
                for(int j=pointerB; j<endB; j++){
                    //cout << (sumA[i].second<<B.size())+sumB[j].second << "\n";
                    check[(sumA[i].second<<B.size())|sumB[j].second]=1;
                }
            }
            pointerA=endA;
            pointerB=endB;
        }
    }

    ll ans=0;
    for(int i=1; i<(1<<20); i++){
        if(check[i]!=0) ans++;
    }
    cout << ans;
    return 0;
}