#include<cstdio>
#include<cmath>
using namespace std;

const double pi = acos(-1);
const double pi_third = pi * 60.0 / 180.0;

struct point{double x,y;};

void koch(int d, point p1, point p2)
{
    if(d == 0) return;

    point s,t,u;

    s.x = (2.0 * p1.x + 1.0 * p2.x) / 3.0;
    s.y = (2.0 * p1.y + 1.0 * p2.y) / 3.0;
    t.x = (1.0 * p1.x + 2.0 * p2.x) / 3.0;
    t.y = (1.0 * p1.y + 2.0 * p2.y) / 3.0;
    u.x = (t.x - s.x) * cos(pi_third) - (t.y - s.y) * sin(pi_third) + s.x;
    u.y = (t.x - s.x) * sin(pi_third) + (t.y - s.y) * cos(pi_third) + s.y;

    koch(d-1, p1, s);
    printf("%lf %lf\n", s.x, s.y);
    koch(d-1, s, u);
    printf("%lf %lf\n", u.x, u.y);
    koch(d-1, u, t);
    printf("%lf %lf\n", t.x, t.y);
    koch(d-1, t, p2);
}

int main()
{
    int n;
    scanf("%d", &n);
    point p1,p2;
    p1.x = 0.0;
    p1.y = 0.0;
    p2.x = 100.0;
    p2.y = 0.0;
    
    printf("%lf %lf\n", p1.x, p1.y);
    koch(n, p1, p2);
    printf("%lf %lf\n", p2.x, p2.y);
    
    return 0;
}

