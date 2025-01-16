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

using namespace __gnu_cxx;
using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;

pii Seg[300000*4+5];
int lazy[300000*4+5];

int lft, rgt;

void LazyUpdate(int node, int start, int end){
    if(lazy[node]!=-1){
        Seg[node].first=lazy[node];
        Seg[node].second=lazy[node];
        if(start!=end){
            lazy[node<<1]=lazy[node];
            lazy[(node<<1)|1]=lazy[node];
        }
        lazy[node]=-1;
    }
    return;
}

void UpdateSeg(int node, int start, int end, int value){
    LazyUpdate(node, start ,end);
    if(rgt<start||end<lft) return;
    else if(lft<=start&&end<=rgt){
        lazy[node]=value;
        LazyUpdate(node, start, end);
    }
    else{
        int mid=(start+end)/2;
        UpdateSeg(node*2, start, mid, value);
        UpdateSeg(node*2+1, mid+1, end, value);
        Seg[node].first=min(Seg[node<<1].first, Seg[(node<<1)|1].first);
        Seg[node].second=max(Seg[node<<1].second, Seg[(node<<1)|1].second);
    }
    return;
}

pii SumSeg(int node, int start, int end){
    LazyUpdate(node, start, end);
    if(rgt<start||end<lft) return {INF, 0};
    else if(lft<=start&&end<=rgt){
        return Seg[node];
    }
    else{
        int mid=(start+end)/2;
        pll A=SumSeg(node<<1, start, mid);
        pll B=SumSeg((node<<1)|1, mid+1, end);
        return {min(A.first, B.first), max(A.second, B.second)};
    }
}

int A[300005];
int B[300005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, Q;
    cin >> N >> Q;

    string S;
    string T;

    cin >> S >> T;

    for(int i=0; i<N; i++){
        A[i]=S[N-1-i]-'0';
        B[i]=T[N-1-i]-'0';
    }

    int prev=0;

    for(int i=0; i<N; i++){
        ll a=A[i]+B[i]+prev;
        lft=i;
        rgt=i;
        UpdateSeg(1, 0, N, a%10);
        prev=0;
        if(a>=10) prev++;
    }
    lft=N;
    rgt=N;
    UpdateSeg(1, 0, N, prev);

    /*for(int i=0; i<=N; i++){
        cout << SumSeg(1, 0, N, i, i).first << " ";
    }
    cout << "\n";*/

    while(Q--){
        char type;
        cin >> type;
        if(type=='A'){
            int i, d;
            cin >> i >> d;
            i--;
            if(A[i]==d){
                cout << 0 << "\n";
            }
            else if(A[i]<d){
                lft=i;
                rgt=i;
                int cur=SumSeg(1, 0, N).first;
                if(cur+(d-A[i])>=10){
                    lft=i+1;
                    rgt=i+1;
                    int nxt=SumSeg(1, 0, N).first;
                    if(nxt<9){
                        lft=i+1;
                        rgt=i+1;
                        UpdateSeg(1, 0, N, nxt+1);
                        lft=i;
                        rgt=i;
                        UpdateSeg(1, 0, N, cur+(d-A[i])-10);
                        A[i]=d;
                        cout << 2 << "\n";
                    }
                    else{
                        int left=i+1;
                        int right=N;
                        int ans=i+1;
                        while(left<=right){
                            int mid=(left+right)>>1;
                            lft=i+1;
                            rgt=mid;
                            if(SumSeg(1, 0, N).first==9){
                                ans=max(ans, mid);
                                left=mid+1;
                            }
                            else right=mid-1;
                        }
                        cout << ans-i+2 << "\n";
                        lft=ans+1;
                        rgt=ans+1;
                        UpdateSeg(1, 0, N, SumSeg(1, 0, N).first+1);
                        lft=i+1;
                        rgt=ans;
                        UpdateSeg(1, 0, N, 0);
                        lft=i;
                        rgt=i;
                        UpdateSeg(1, 0, N, cur+(d-A[i])-10);
                        A[i]=d;
                    }
                }
                else{
                    lft=i;
                    rgt=i;
                    UpdateSeg(1, 0, N, cur+(d-A[i]));
                    A[i]=d;
                    cout << 1 << "\n";
                }
            }
            else{
                lft=i;
                rgt=i;
                int cur=SumSeg(1, 0, N).second;
                if(cur+(d-A[i])<0){
                    lft=i+1;
                    rgt=i+1;
                    int nxt=SumSeg(1, 0, N).second;
                    if(nxt>0){
                        lft=i+1;
                        rgt=i+1;
                        UpdateSeg(1, 0, N, nxt-1);
                        lft=i;
                        rgt=i;
                        UpdateSeg(1, 0, N, 10+cur+(d-A[i]));
                        A[i]=d;
                        cout << 2 << "\n";
                    }
                    else{
                        int left=i+1;
                        int right=N;
                        int ans=i+1;
                        while(left<=right){
                            int mid=(left+right)>>1;
                            lft=i+1;
                            rgt=mid;
                            if(SumSeg(1, 0, N).second==0){
                                ans=max(ans, mid);
                                left=mid+1;
                            }
                            else right=mid-1;
                        }
                        cout << ans-i+2 << "\n";
                        lft=ans+1;
                        rgt=ans+1;
                        UpdateSeg(1, 0, N, SumSeg(1, 0, N).second-1);
                        lft=i+1;
                        rgt=ans;
                        UpdateSeg(1, 0, N, 9);
                        lft=i;
                        rgt=i;
                        UpdateSeg(1, 0, N, 10+cur+(d-A[i]));
                        A[i]=d;
                    }
                }
                else{
                    lft=i;
                    rgt=i;
                    UpdateSeg(1, 0, N, cur+(d-A[i]));
                    A[i]=d;
                    cout << 1 << "\n";
                }
            }
        }
        else{
            int i, d;
            cin >> i >> d;
            i--;
            //cout << B[i] << " " << d << "\n";
            if(B[i]==d){
                cout << 0 << "\n";
            }
            else if(B[i]<d){
                lft=i;
                rgt=i;
                int cur=SumSeg(1, 0, N).first;
                if(cur+(d-B[i])>=10){
                    lft=i+1;
                    rgt=i+1;
                    int nxt=SumSeg(1, 0, N).first;
                    if(nxt<9){
                        lft=i+1;
                        rgt=i+1;
                        UpdateSeg(1, 0, N, nxt+1);
                        lft=i;
                        rgt=i;
                        UpdateSeg(1, 0, N, cur+(d-B[i])-10);
                        B[i]=d;
                        cout << 2 << "\n";
                    }
                    else{
                        int left=i+1;
                        int right=N;
                        int ans=i+1;
                        while(left<=right){
                            int mid=(left+right)>>1;
                            lft=i+1;
                            rgt=mid;
                            if(SumSeg(1, 0, N).first==9){
                                ans=max(ans, mid);
                                left=mid+1;
                            }
                            else right=mid-1;
                        }
                        cout << ans-i+2 << "\n";
                        lft=ans+1;
                        rgt=ans+1;
                        UpdateSeg(1, 0, N, SumSeg(1, 0, N).first+1);
                        lft=i+1;
                        rgt=ans;
                        UpdateSeg(1, 0, N, 0);
                        lft=i;
                        rgt=i;
                        UpdateSeg(1, 0, N, cur+(d-B[i])-10);
                        B[i]=d;
                    }
                }
                else{
                    lft=i;
                    rgt=i;
                    UpdateSeg(1, 0, N, cur+(d-B[i]));
                    B[i]=d;
                    cout << 1 << "\n";
                }
            }
            else{
                lft=i;
                rgt=i;
                int cur=SumSeg(1, 0, N).second;
                if(cur+(d-B[i])<0){
                    lft=i+1;
                    rgt=i+1;
                    int nxt=SumSeg(1, 0, N).second;
                    if(nxt>0){
                        lft=i+1;
                        rgt=i+1;
                        UpdateSeg(1, 0, N, nxt-1);
                        lft=i;
                        rgt=i;
                        UpdateSeg(1, 0, N, 10+cur+(d-B[i]));
                        B[i]=d;
                        cout << 2 << "\n";
                    }
                    else{
                        int left=i+1;
                        int right=N;
                        int ans=i+1;
                        while(left<=right){
                            int mid=(left+right)>>1;
                            lft=i+1;
                            rgt=mid;
                            if(SumSeg(1, 0, N).second==0){
                                ans=max(ans, mid);
                                left=mid+1;
                            }
                            else right=mid-1;
                        }
                        cout << ans-i+2 << "\n";
                        lft=ans+1;
                        rgt=ans+1;
                        UpdateSeg(1, 0, N, SumSeg(1, 0, N).second-1);
                        lft=i+1;
                        rgt=ans;
                        UpdateSeg(1, 0, N, 9);
                        lft=i;
                        rgt=i;
                        UpdateSeg(1, 0, N, 10+cur+(d-B[i]));
                        B[i]=d;
                    }
                }
                else{
                    lft=i;
                    rgt=i;
                    UpdateSeg(1, 0, N, cur+(d-B[i]));
                    B[i]=d;
                    cout << 1 << "\n";
                }
            }
        }
        /*for(int i=0; i<=N; i++){
            cout << SumSeg(1, 0, N, i, i).first << " ";
        }
        cout << "\n";*/
    }
    return 0;
}

