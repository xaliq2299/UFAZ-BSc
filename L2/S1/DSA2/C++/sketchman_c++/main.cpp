#include <iostream>
#include <math.h>
#define PI 3.1415

using namespace std;

class Position{
    int x, y;
    public:
    Position(int x, int y){
        this.x=x;  this.y = y;
    }
}

class Color{
    private: int r,g,b;
    public:
    Color(int r, int g, int b){
        this.r = r;
        this.g = g;
        this.b = b;
    }
}

class Circle{
    float rad;
    int col;
    Position p;
    public:
        float perimeter(){
        return 2*PI*rad;
    }
    float area(){
        return PI*rad*rad;
    }
    Circle(float rad){
        this.rad = rad;
    }
}

class Triangle{
    Position p;
    int col;
    float side;
    public:
    float perimeter(){
        return side*3;
    }
    float area(){
        return sqrt(3)*side*side/4;
    }
}

class Rectangle{
    Position pos;
    int col;
    float width, height;
    public:
    Rectangle(float w, float h, int c, Position p){
        width=w; height=h; col=c;
        pos=new Position(p);//default constructor
    }
    float perimeter(){
        return (width+height)*2;
    }
    float area(){
        return this.length*this.width;
    }
}

class Rocket{
    Triangle tops[3], bottoms[3];
    Rectangle body, arms[2];
    
    public:
    Rocket(Triangle t1, Triangle t2, Triangle t3, 
        Triangle t4, Triangle t5,Triangle t6, 
        Rectangle r1, Rectangle r2, Rectangle r3 );    
    float perimeter(){
        return 3*tops[0].perimeter()+3*bottoms[0].perimeter()+3*r1.perimeter();
    }
    float area(){
        return 3*tops[0].area()+3*bottoms[0].area()+3*r1.area();
    }
}

int main(){
    // create the instances of shape objects and then the rocket object...
    return 0;
}