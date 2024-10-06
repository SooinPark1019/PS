#include <bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define pii pair<int, int>

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int cur=2;
    vector<int> odd;
    for(int i=1; i<=2*N+1; i+=2){
        odd.push_back(i);
    }
    int left=0;
    int right=odd.size()-1;
    cout << cur << " ";
    int t=0;
    while(left<=right){
        if(t%2==0){
            cur-=odd[left];
            left++;
        }
        else{
            cur+=odd[right];
            right--;
        }
        t++;
        cout << cur << " ";
    }
}