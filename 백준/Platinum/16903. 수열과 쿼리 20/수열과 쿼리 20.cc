#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
//#pragma GCC optimize ("O3")
//#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")

using namespace std;

typedef long long ll;
typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 998244353;

struct Trie{
    int l, r, cnt, fin;
    Trie() : l(-1), r(-1), cnt(0), fin(-1){}
};

Trie arr[6000005];
queue<int> Q;
int root;
int num[35]={};

int newTrie(){
    int A=Q.front();
    Q.pop();
    return A;
}

void insert(int x){
    int now=root;
    int temp=x;
    for(int i=29; i>=0; i--){
        num[i]=x&1;
        x>>=1;
    }
    for(int i=0; i<30; i++){
        if(num[i]){
            if(arr[now].r==-1){
                arr[now].r=newTrie();
            }
            now=arr[now].r;
            arr[now].cnt++;
        }
        else{
            if(arr[now].l==-1){
                arr[now].l=newTrie();
            }
            now=arr[now].l;
            arr[now].cnt++;
        }
    }
    arr[now].fin=temp;
}

void erase(int x){
    int now=root;
    for(int i=29; i>=0; i--){
        num[i]=x&1;
        x>>=1;
    }
    for(int i=0; i<30; i++){
        if(num[i]){
            int nxt=arr[now].r;
            arr[nxt].cnt--;
            if(arr[nxt].cnt==0){
                arr[now].r=-1;
                arr[nxt].fin=-1;
                Q.push(nxt);
            }
            now=nxt;
        }
        else{
            int nxt=arr[now].l;
            arr[nxt].cnt--;
            if(arr[nxt].cnt==0){
                arr[now].l=-1;
                arr[nxt].fin=-1;
                Q.push(nxt);
            }
            now=nxt;
        }
    }
}

int query(int x){
    int now=root;
    int temp=x;
    for(int i=29; i>=0; i--){
        num[i]=x&1;
        x>>=1;
    }
    for(int i=0; i<30; i++){
        if(num[i]){
            if(arr[now].l!=-1) now=arr[now].l;
            else now=arr[now].r;
        }
        else{
            if(arr[now].r!=-1) now=arr[now].r;
            else now=arr[now].l;
        }
    }
    return temp^arr[now].fin;
}

void init(){
    for(int i=1; i<6000005; i++){
        Q.push(i);
    }
    return;
}


int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    cin >> M;
    init();
    root=newTrie();
    insert(0);
    while(M--){
        int a, b;
        cin >> a >> b;
        if(a==1) insert(b);
        else if(a==2) erase(b);
        else cout << query(b) << "\n";
    }
    return 0;
}
