#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>

using namespace std;

ll cal(priority_queue<pll>& PQ, int cap){
    ll ret=0;
    while(!PQ.empty()&&cap>0){
        if(PQ.top().second==0){
            PQ.pop();
        }
        else if(cap>=PQ.top().second){
            ret=max(ret, PQ.top().first);
            cap-=PQ.top().second;
            PQ.pop();
        }
        else{
            ret=max(ret, PQ.top().first);
            pll temp=PQ.top();
            PQ.pop();
            temp.second-=cap;
            PQ.push(temp);
            cap=0;
        }
    }
    return ret;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    priority_queue<pll> A;
    priority_queue<pll> B;
    for(int i=0; i<n; i++){
        A.push({i+1, deliveries[i]});
        B.push({i+1, pickups[i]});
    }
    ll ans=0;
    while(!A.empty()||!B.empty()){
        ll temp=0;
        ll a=cal(A, cap);
        ll b=cal(B, cap);
        temp=max(temp, a);
        temp=max(temp, b);
        ans+=2*temp;
    }
    return ans;
}