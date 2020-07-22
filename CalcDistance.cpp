//Used class information from http://www.cplusplus.com/doc/tutorial/classes/
#include <iostream>
#include <cmath>
using namespace std;

//defining the class Point
class Point{
    public:
        float x;
        float y;
        void set_values(float, float);
};

//method to set the x and y coordinates of a specific point
void Point::set_values (float pointX, float pointY){
    x = pointX;
    y = pointY;
}

//method to calculate and return the distance between point one and two
float calculateDistance(Point * one, Point * two){
    Point p1 = *one;
    Point p2 = *two;
    float part1 = pow((p2.x- p1.x), 2);
    float part2 = pow((p2.y- p1.y), 2);
    float answer = sqrt((part1 + part2));
    return answer;
}

/*
Main function that creates two Point objects, p1 and p2, asks the user to 
enter the coordinates for these two points, calculates the distance between 
the two by calling the calculateDistance function, and displays the result
*/
int main(){
    Point pointOne;
    Point pointTwo;
    float p1One;
    float p1Two;
    float p2One;
    float p2Two;
    
    cout << "Please input two coordinates (floats) for point one: " << endl;
    cin >> p1One;
    cin >> p1Two;
    
    pointOne.set_values(p1One, p1Two);
    
    Point * pointerOne = &pointOne;
    
    cout << "Please input two coordinates (floats) for point two: " << endl;
    cin >> p2One;
    cin >> p2Two;
    
    pointTwo.set_values(p2One, p2Two);
    
    Point * pointerTwo = &pointTwo;
    
    float mainAnswer = calculateDistance(pointerOne, pointerTwo);
    cout << "The distance between the two points is: " << mainAnswer << endl;
    return 0;
}