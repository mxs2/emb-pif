#include <stdio.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point A;
    Point B;
    Point C;
    Point D;
} Rectangle;

int isInside(Point robot, Rectangle rect) {
    int minX = (rect.A.x < rect.D.x) ? rect.A.x : rect.D.x;
    int maxX = (rect.B.x > rect.C.x) ? rect.B.x : rect.C.x;
    int minY = (rect.A.y < rect.B.y) ? rect.A.y : rect.B.y;
    int maxY = (rect.D.y > rect.C.y) ? rect.D.y : rect.C.y;

    return (robot.x >= minX && robot.x <= maxX && robot.y >= minY &&
            robot.y <= maxY);
}

int main() {
    int testCases;
    scanf("%d", &testCases);

    while (testCases--) {
        Rectangle rect;
        Point robot;

        scanf("%d %d %d %d %d %d %d %d %d %d", &rect.A.x, &rect.A.y, &rect.B.x,
              &rect.B.y, &rect.C.x, &rect.C.y, &rect.D.x, &rect.D.y, &robot.x,
              &robot.y);

        if (rect.A.y == rect.B.y && rect.D.y == rect.C.y &&
            rect.A.x == rect.D.x && rect.B.x == rect.C.x) {
            printf("%d\n", (robot.x >= rect.A.x && robot.x <= rect.B.x &&
                            robot.y >= rect.A.y && robot.y <= rect.D.y));
        } else {
            printf("%d\n", isInside(robot, rect));
        }
    }

    return 0;
}
