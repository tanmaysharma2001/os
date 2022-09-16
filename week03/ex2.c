#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point
{
    double x;
    double y;
};

typedef struct Point Point;

double distance(const Point *p1, const Point *p2)
{
    double diff1 = ((p1->x - p2->x) * (p1->x - p2->x));
    double diff2 = ((p1->y - p2->y) * (p1->y - p2->y));

    double sum = diff1 + diff2;

    // double distance = sqrt(sum);

    return sum;
}

double area(const Point *A, const Point *B, const Point *C) {
    double x1y2 = (A->x) * (B->y);
    double x2y1 = (B->x) * (A->y);
    double x2y3 = (B->x) * (C->y);
    double x3y2 = (C->x) * (B->y);
    double x3y1 = (C->x) * (A->y);
    double x1y3 = (A->x) * (C->y);

    double area = 0.5 * abs(x1y2 - x2y1 + x2y3 - x3y2 + x3y1 - x1y3);

    return sqrt(area);
}

Point aPoint(double x, double y) {
    Point p;
    p.x = x;
    p.y = y;
    return p;
}

int main()
{
    Point APoint;
    APoint.x = 2.5;
    APoint.y = 6;
    Point* A = &APoint;

    Point BPoint;
    BPoint.x = 1;
    BPoint.y = 2.2;
    Point* B = &BPoint;

    Point CPoint;
    CPoint.x = 10;
    CPoint.y = 6;
    Point* C = &CPoint;

    printf("The Distance between A and B is: %f\n", distance(A, B));

    printf("The Area of the triangle ABC is: %f\n", area(A, B, C));

    return 0;
}