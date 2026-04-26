#include <iostream>
using namespace std;

class Shape
{
    string color;
protected: 
    const static double PI;
public:
    Shape(string mycolor = "")
    {
        this->color = mycolor;
        cout << "1 create Shape " << endl;
    }
    virtual void output() { cout << "颜色：" << color << endl<<endl; }
    virtual double getArea() { return 0; }
    virtual double getPeri() { return 0; }
};
const double Shape::PI = 3.14;

class Point :public Shape
{
    int x, y;
public:
    Point(int myx = 0, int myy = 0, string mycolor = "")
        :Shape(mycolor)
    {
        this->x = myx;
        this->y = myy;
        cout << "2 create Point " << endl;
    }
    void outputOnlyPoint()
    {
        cout << "（" << x << "," << y << ")" << endl;
    }
    void output()
    {
        cout << "点的坐标：（" << x << "," << y << ")" << endl;
        Shape::output();
    }
};

class Rect :public Shape
{
    int length, width;
public:
    Rect(int len = 1, int w = 1, string mycolor = "") :Shape(mycolor)
    {
        this->length = len;
        this->width = w;
        cout << "3 create rect " << endl;
    }
    double getArea() {
        cout << "矩形的面积";
        return this->length * this->width;
    }
    double getPeri() {
        cout << "矩形的周长";
        return this->length * 2 + this->width * 2;
    }
    void output()
    {
        cout << "矩形的长：" << length << endl << "矩形的宽：" << width << endl ;
        Shape::output();
    }
};

class Circle :public Shape
{
    int r;
    Point center;
public:
    Circle(int myr = 0, int x = 0, int y = 0, string mycolor = "")
        :Shape(mycolor), center(x, y)
    {
        this->r = myr;
        cout << "4 create Circle " << endl;
    }
    double getArea() {
        cout << "Circle的面积";
        return PI * r * r;
    }
    double getPeri() {
        cout << "Circle的周长";
        return PI * r * 2;
    }
    void output()
    {
        cout << "圆的半径：" << r << endl <<"圆心坐标：" ;
        center.outputOnlyPoint();
        Shape::output();
    }
};


void fun(Shape& s)
{
    s.output();
}



int main() {
    Rect r(10, 6, "red");

    Circle c(10, 0, 0, "blue");

    Point a(1, 1, "yellow");

    fun(r);
    fun(c);
    fun(a);
    return 0;
}