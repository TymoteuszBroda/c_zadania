#include<stdlib.h>
struct point
{
    int x;
    int y;
};
void changeCoords(struct point *p1, int x2, int y2)
{
    p1->x=x2;
    p1->y=y2;
}
struct Rectangle
{
    struct  point topl;
    struct  point botr;
};
float calculate(struct Rectangle rectangle)
{
    int width = rectangle.topl.x - rectangle.botr.x;
    int height = rectangle.topl.y - rectangle.botr.y;
    return width*height;
}

int main()
{
    struct point Point;
    Point.x=1;
    Point.y=2;
    printf("\nPrzed funkcją: punkt x: %d, punkt y: %d",Point.x, Point.y);
    changeCoords(&Point, 2, 4);
    printf("\nPo funkcji: punkt x: %d, punkt y: %d",Point.x, Point.y);
    struct Rectangle rectangle;
    
    float myField = calculate(rectangle);
    printf("Pole: %d", myField);
    return 0;
}