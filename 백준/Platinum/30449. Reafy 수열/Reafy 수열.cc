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
const int MAXN = 1<<19;
const int D = 20;

/*
관찰을 좀 해보자
먼저 위에서 아래로 본다?
이건 좀 힘들 거 같은게
고려해야 할 게 너무 많다

그래도 일단 본다고 하면
2는 자신이 속한 절반 크기의 블록에서 자기보다 큰 게 없어야 한다
3 4는 자신이 속한 1/4 크기의 블록에서 자기보다 큰 게 없어야 한다

자리가 정해진 걸 어떻게 생각을 해야할까
일단 정해진게 없다고 하면 2*(2^(k-1))!이다

2^(위치가 안 정해진 애들의 개수)*(추가되는 애들 중 위치가 안정해진 애들의 개수)!

아니네
먼저 가능한지를 봐야 한다
위치가 정해진 작은 애부터 세그트리에 박아 넣고
정해진 블록 내에 어떤 애가 존재하는지를 확인->존재하는 순간 나가리

이후 매칭을 시켜준다고 하자
어떤 배열이 존재한다고 해
정해진 애들부터 매칭을 시켰을 때 이미 정해진 애들을 몇개 앗아가는지를 보고
안정해진 애들을 매칭을 시켜서 몇개의 안 정해진 애들이랑 매칭을 시킬 수 있는지를 보자
*/

struct fraction{
    int a, b;
    bool operator < (const fraction A) const{
        return a*A.b<b*A.a;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    if(N==1){
        if(K==1) cout << 0 << " " << 1;
        else cout << 1 << " " << 1;
        return 0;
    }
    vector<fraction> V;
    V.push_back({0, 1});
    for(int i=2; i<=N; i++){
        for(int j=1; j<=i/2; j++){
            if(__gcd(j, i)==1){
                V.push_back({j, i});
            } 
        }
    }
    if(K<V.size()){
        nth_element(V.begin(), V.begin()+K-1, V.end());
        cout << V[K-1].a << " " << V[K-1].b;
    }
    else{
        K=2*V.size()-K;
        nth_element(V.begin(), V.begin()+K-1, V.end());
        cout << V[K-1].b-V[K-1].a << " " << V[K-1].b;
    }
    return 0;
}