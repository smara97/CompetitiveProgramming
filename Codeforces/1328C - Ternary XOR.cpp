#include <bits/stdc++.h>

#define fast ios_base::sync_with_stdio(0);cin.tie(NULL),cout.tie(NULL)
#define EPS 1e-9
#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;

ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }

int  dix[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int  diy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };

using namespace std;

struct Point {
    int x, y;
};

float dist(int x1,int y1,int x2,int y2){
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

int distSq(Point p, Point q)
{
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}

bool isSquare(Point p1, Point p2, Point p3, Point p4)
{
    int d2 = distSq(p1, p2);
    int d3 = distSq(p1, p3);
    int d4 = distSq(p1, p4);

    if (d2 == 0 || d3 == 0 || d4 == 0)
        return false;


    if (d2 == d3 && 2 * d2 == d4
        && 2 * distSq(p2, p4) == distSq(p2, p3)) {
        return true;
    }

    if (d3 == d4 && 2 * d3 == d2
        && 2 * distSq(p3, p2) == distSq(p3, p4)) {
        return true;
    }
    if (d2 == d4 && 2 * d2 == d3
        && 2 * distSq(p2, p3) == distSq(p2, p4)) {
        return true;
    }

    return false;
}
int main()
{
    fast;
    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin>>x1>>y1>>x2>>y2;
    if(x1==x2){
        if (x1+abs(max(y1,y2)-min(y2,y1))<=1000){
            x3=x1+abs(max(y1,y2)-min(y2,y1));
        }
        else{
             x3=x1-abs(max(y1,y2)-min(y2,y1));
        }
        y3=y1;
        x4=x3;
        y4=y2;
    }
    else if(y1==y2){
        x3=x1;
        x4=x2;
        if(y2+abs(x1-x2)<=1000){
            y3=y2+abs(max(x1,x2)-min(x2,x1));
            y4=y3;
        }
        else{
            y3=y2-abs(max(x1,x2)-min(x2,x1));
            y4=y3;
        }
    }
    else{
        x3 = x2;
        y3 = y1;
        x4 = x1;
        y4 = y2;
    }
    if(isSquare({x1,y1},{x2,y2},{x3,y3},{x4,y4}))
        cout<<x3<<' '<<y3<<' '<<x4<<' '<<y4<<endl;
    else
        cout<<-1<<endl;
    return 0;
}
