#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    while(1){
        N++;
        if((N/100+N%100)*(N/100+N%100)==N) break;
    }
    if(N>=10000) cout << -1;
    else cout << N;
}