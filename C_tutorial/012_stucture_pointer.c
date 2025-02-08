#include <stdio.h>

struct Point
{
    int x;
    int y;
};

int main() {
    struct Point points[] = {
        {1,2},
        {3,4},
        {5,6}
    };

    printf("points[0].x == %d, points[0].y == %d\n", points[0].x, points[0].y);

    struct Point *p = points;
    // 下面两个是等价的
    printf("p->x == %d, p->y == %d\n", p->x, p->y);
    printf("(*p).x == %d, (*p).x == %d\n", (*p).x, (*p).y);

    p++;
    printf("p->x == %d, p->y == %d\n", p->x, p->y);

    p++;
    printf("p->x == %d, p->y == %d\n", p->x, p->y);
    return 0;
}
