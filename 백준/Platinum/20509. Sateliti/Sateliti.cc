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
const ll mod = 1e9+123;
const int MAXN = (1<<18)+5;
const double PI = acos(-1);

/*
각 단어마다 짝을 지어준 다음에
DP[i][j]=인덱스 i, 인덱스 j인 경우의 최소 비용
*/

int p=7, q=11;

int fastmul(int a, int b){
    if(b==0) return 1;
    if(b==1) return a;
    if(b%2==0){
        int temp=fastmul(a, b/2);
        return temp*temp%mod;
    }
    return a*fastmul(a, b-1)%mod;
}

int prefix[2005][2005];
int arr[2005][2005];
int powpq[2005][2005];

void input(int N, int M){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            char c;
            cin >> c;
            if(c=='.') arr[i][j]=1;
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            arr[i+N][j]=arr[i][j];
            arr[i][j+M]=arr[i][j];
            arr[i+N][j+M]=arr[i][j];
        }
    }
}

void precalc(int N, int M){
    for(int i=0; i<2*N; i++){
        for(int j=0; j<2*M; j++){
            if(i==0&&j==0) powpq[i][j]=1;
            else if(i==0) powpq[i][j]=powpq[i][j-1]*q%mod;
            else powpq[i][j]=powpq[i-1][j]*p%mod;
        }
    }
    for(int i=0; i<2*N; i++){
        for(int j=0; j<2*M; j++){
            if(i!=0) prefix[i][j]+=prefix[i-1][j];
            if(j!=0) prefix[i][j]+=prefix[i][j-1];
            if(i!=0&&j!=0) prefix[i][j]-=prefix[i-1][j-1];
            prefix[i][j]+=mod;
            prefix[i][j]%=mod;
            if(arr[i][j]==1){
                prefix[i][j]+=powpq[i][j];
                prefix[i][j]%=mod;
            }
        }
    }
}

int calc(int x, int y, int dx, int dy){
    int a=prefix[x+dx][y+dy];
    if(x>0) a-=prefix[x-1][y+dy];
    if(y>0) a-=prefix[x+dx][y-1];
    if(x>0&&y>0) a+=prefix[x-1][y-1];
    a%=mod;
    a+=mod;
    a%=mod;
    return a;
}

bool isequal(int x1, int y1, int x2, int y2, int dx, int dy){
    int a=calc(x1, y1, dx, dy)*powpq[x2][y2]%mod;
    int b=calc(x2, y2, dx, dy)*powpq[x1][y1]%mod;
    //cout << "a : " << a << " b : " << b << "\n";
    return a==b;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    input(N, M);
    precalc(N, M);

    int ansx=0;
    int ansy=0;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            //cout << "i : " << i << " j : " << j << "\n";
            int left=0;
            int right=N-1;
            int ansdx=0;
            while(left<=right){
                int mid=(left+right)>>1;
                if(isequal(ansx, ansy, i, j, mid, M)){
                    ansdx=max(ansdx, mid+1);
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
            //cout << "ansdx : " << ansdx << "\n";
            if(ansdx==N){
                continue;
            }
            left=0;
            right=M-1;
            int ansdy=0;
            while(left<=right){
                int mid=(left+right)>>1;
                if(isequal(ansx+ansdx, ansy, i+ansdx, j, 0, mid)){
                    ansdy=max(ansdy, mid+1);
                    left=mid+1;
                }
                else right=mid-1;
            }
            //cout << "ansdy : " << ansdy << "\n";
            if(arr[ansx+ansdx][ansy+ansdy]==1){
                ansx=i;
                ansy=j;
            }
            //cout << "ansx : " << ansx << " ansy : " << ansy << "\n";
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[ansx+i][ansy+j]==0) cout << '*';
            else cout << '.';
        }
        cout << "\n";
    }
    
    return 0;
}
