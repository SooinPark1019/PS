#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
//#pragma GCC optimize ("O3")
//#pragma GCC optimize ("Ofast")
//#pragma GCC optimize ("unroll-loops")

using namespace std;

typedef long long ll;
//typedef __int128 i128;
typedef long double ld;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const ll LNF = 1e18;
const ll mod = 1e9+7;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N;
    cin >> N;
    int arr[4][1005]={};
    int up[1005]={};
    for(int i=1; i<=3; i++){
        for(int j=1; j<=N; j++){
            cin >> arr[i][j];
            up[arr[i][j]]+=i;
        }
    }
    int check[1005]={};
    for(int i=1; i<=N; i++){
        if(arr[1][i]==arr[2][i]&&arr[1][i]==arr[3][i]){
            check[arr[1][i]]=1;
        }
    }
    check[0]=1;
    ll emptyslot=N+1;
    vector<pair<int, int>> ans;
    while(1){
        ll pivot=0;
        for(int i=1; i<=N+1; i++){
            if(up[arr[1][i]]<=6&&check[arr[1][i]]==0&&arr[1][i]!=0){
                pivot=arr[1][i];
                break;
            }
        }
        if(pivot==0) break;
        check[pivot]=1;
        pair<int, int> a={-1, 0};
        pair<int, int> b={-1, 0};
        pair<int, int> c={-1, 0};
        for(int i=1; i<=3; i++){
            for(int j=1; j<=N+1; j++){
                if(arr[i][j]==pivot){
                    if(a.first==-1){
                        a.first=i;
                        a.second=j;
                    }
                    else if(b.first==-1){
                        b.first=i;
                        b.second=j;
                    }
                    else{
                        c.first=i;
                        c.second=j;
                        break;
                    }
                }
            }
            if(c.first!=-1) break;
        }
        ans.push_back({a.second, emptyslot});
        arr[a.first][a.second]=0;
        arr[3][emptyslot]=pivot;
        for(int i=1; i<=2; i++){
            if(arr[i][b.second]==0) continue;
            else if(arr[i][b.second]==pivot){
                ans.push_back({b.second, emptyslot});
                if(arr[2][emptyslot]!=0) arr[1][emptyslot]=pivot;
                else arr[2][emptyslot]=pivot;
                arr[i][b.second]=0;
            }
            else{
                ans.push_back({b.second, a.second});
                arr[1][a.second]=arr[i][b.second];
                arr[i][b.second]=0;
            }
        }
        for(int i=1; i<=3; i++){
            if(arr[i][c.second]==0) continue;
            else if(arr[i][c.second]==pivot){
                ans.push_back({c.second, emptyslot});
                arr[1][emptyslot]=pivot;
                arr[i][c.second]=0;
            }
            else if(b.second==c.second){
                ans.push_back({c.second, a.second});
                if(arr[3][a.second]==0){
                    arr[3][a.second]=arr[i][c.second];
                }
                else if(arr[2][a.second]==0){
                    arr[2][a.second]=arr[i][c.second];
                }
                else{
                    arr[1][a.second]=arr[i][c.second];
                }
                arr[i][c.second]=0;
            }
            else{
                ans.push_back({c.second, b.second});
                if(arr[3][b.second]==0){
                    arr[3][b.second]=arr[i][c.second];
                }
                else if(arr[2][b.second]==0){
                    arr[2][b.second]=arr[i][c.second];
                }
                else{
                    arr[1][b.second]=arr[i][c.second];
                }
                arr[i][c.second]=0;
            }
        }
        /*for(int i=1; i<=3; i++){
            for(int j=1; j<=N+1; j++){
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }*/
        emptyslot=c.second;
        memset(up, 0, sizeof(up));
        for(int i=1; i<=3; i++){
            for(int j=1; j<=N+1; j++){
                up[arr[i][j]]+=i;
            }
        }
        int cnt=0;
        for(int i=1; i<=N+1; i++){
                if(arr[1][i]==arr[2][i]&&arr[1][i]==arr[3][i]){
                check[arr[1][i]]=1;
                cnt++;
            }
        }
        if(cnt>N) break;
    }
    if(emptyslot!=N+1){
        for(int i=0; i<3; i++){
            ans.push_back({N+1, emptyslot});
        }
    }
    cout << ans.size() << "\n";
    for(auto p : ans){
        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}
