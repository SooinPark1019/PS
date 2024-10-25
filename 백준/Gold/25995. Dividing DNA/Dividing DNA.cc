#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

using namespace std;

signed main(){
    int N;
    cin >> N;
    int left=0;
    int right=1;
    int ans=0;
    while(right<=N){
        cout << "? " << left << " " << right << endl;
        string S;
        cin >> S;
        if(S=="absent"){
            ans++;
            left=right;
        }
        right++;
    }
    cout << "! " << ans << endl;
}