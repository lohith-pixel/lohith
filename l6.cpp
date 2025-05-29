#include<iostream>
using namespace std;

float areaofcircle(float radius)
{
    return 3.14 * radius * radius;
}
float areaoftrtiangle(float height, float width)
{
    return 0.5 * height * width;
}
float areaofrectangle(float height, float breath)
{
    return height * breath;
}

int main()
{
    float fullArea = areaofrectangle(10, 10) + areaoftriangle(5, 12);
    float subArea = areaofrectangle(3, 7) + areaofcircle(2) + areaoftriangle(2, 3);
    cout << fullArea - subArea << endl;
}
