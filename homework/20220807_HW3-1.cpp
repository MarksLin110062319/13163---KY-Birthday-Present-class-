#include <bits/stdc++.h>
#include "function.h"
using namespace std;


oj::Triangle::Triangle(double a, double b, double c)
{
    edge1 = a;
    edge2 = b;
    edge3 = c;
    if(a + b > c && a + c > b && b + c > a){
        double s = (a + b + c) / 2;
        setPerimeter(a + b + c);
        setArea(sqrt(s* (s - a)* (s - b)* (s - c)));
    }
    else{
        setPerimeter(0);
        setArea(0);
    }
}

oj::Rectangle::Rectangle(double a, double b)
{
    width = a;
    height = b;
    if(a > 0 && b > 0){
        double p = (a + b)* 2;
        setPerimeter(p);
        setArea(a * b);
    }
    else{
        setPerimeter(0);
        setArea(0);
    }
}

oj::Circle::Circle(double a, double b)
{
    radius = a;
    pi = b;
    if(radius > 0 && pi > 0){
        double A = b * a * a;
        setPerimeter(2 * b * a);
        setArea(A);
    }
    else{
        setPerimeter(0);
        setArea(0);
    }
}
