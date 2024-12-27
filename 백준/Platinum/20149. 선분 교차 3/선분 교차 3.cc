#include <bits/stdc++.h>

using namespace std;

struct point{
    long double x,y;
};
struct line{
    point start, end;
};
int comparator(point left, point right){
    int ret;
    if(left.x == right.x){
        ret = (left.y <= right.y);
    }
    else{
        ret = (left.x <= right.x);
    }
    return ret;
}
int ccw(point A, point B, point C){
    long double temp=(B.x-A.x)*(C.y-B.y)-(C.x-B.x)*(B.y-A.y);
    if(temp>0) return 1;
    else if(temp==0) return 0;
    else return -1;
}

int intersect(line A, line B){
    if((ccw(A.start, A.end, B.start)*ccw(A.start, A.end, B.end)==0)&&(ccw(B.start, B.end, A.start)*ccw(B.start, B.end, A.end)==0)){
         return (comparator(A.start, B.end)&&comparator(B.start, A.end));
    }
    return (ccw(A.start, A.end, B.start)*ccw(A.start, A.end, B.end)<=0)&&(ccw(B.start, B.end, A.start)*ccw(B.start, B.end, A.end)<=0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    line A={{x1, y1}, {x2, y2}};
    cin >> x1 >> y1 >> x2 >> y2;
    line B={{x1, y1}, {x2, y2}};

    if(!comparator(A.start, A.end)) swap(A.start, A.end);
    if(!comparator(B.start, B.end)) swap(B.start, B.end);

    cout << intersect(A, B) << "\n";
    cout << fixed;
    cout.precision(12);
    if(intersect(A, B)){
        long double a1=(A.end.y-A.start.y)/(A.end.x-A.start.x);
        long double a2=(B.end.y-B.start.y)/(B.end.x-B.start.x);
        long double b1=(A.start.y-a1*A.start.x);
        long double b2=(B.start.y-a2*B.start.x);
        if(a1!=a2){
            long double ansx=-1*(b1-b2)/(a1-a2);
            long double ansy=a1*ansx+b1;
            if(A.end.x==A.start.x){
                cout << A.end.x << " " << a2*A.end.x+b2;
            }
            else if(B.end.x==B.start.x){
                cout << B.end.x << " " << a1*B.end.x+b1;
            }
            else cout << ansx << " " << ansy;
        }
        else{
            if((A.start.x==B.end.x)&&(A.start.y==B.end.y)&&A.end.x==B.start.x&&A.end.y==B.start.y) return 0;
            if((A.start.x==B.end.x)&&(A.start.y==B.end.y))
                cout << A.start.x << " " << A.start.y;
            else if(A.end.x==B.start.x&&A.end.y==B.start.y)
                cout << A.end.x << " " << A.end.y;
        }
    }
    return 0;
}
