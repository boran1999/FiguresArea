#pragma once
#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>

#define PI 3.141592

using namespace std;

template<class T> struct Point {
	T x, y;
};

class Figures{
public:
	virtual string name() = 0;
	virtual double area() = 0;
	virtual double perim() = 0;
};


template<class T> class Circle : public Figures {
public:
	Circle(double R) {
		this->r = R;
	}
	Circle() {}
	string name() {
		return "I am Circle";
	}
	double area() {
		return PI * r * r;
	}
	double perim() {
		return 2 * PI * r;
	}
private:
	T r;
};
template<class T> class Rectangle :public Figures {
public:
	Rectangle() {}
	Rectangle(double A, double B) {
		this->a = A;
		this->b = B;
	}
	string name() {
		return "I am Rectangle";
	}
	double area() {
		return a*b;
	}
	double perim() {
		return (a+b)*2;
	}
private:
	T a, b;
};

template<class T> class Triangle :public Figures {
public:
	Triangle() {}
	Triangle(double A, double B, double C) {
		this->a=A;
		this->b=B;
		this->c=C;
	}
	string name() {
		return "I am triangle";
	}
	double area() {
		double p = this->perim() / 2;
		return sqrt(p * (p - a)*(p - b)*(p - c));
	}
	double perim() {
		return a + b + c;
	}

private:
	T a, b, c;
};

class Poligon :public Figures {
public:
	Poligon() {}
	void set(const char* namefile) {
		double x, y;
		ifstream in(namefile);
		while (!in.eof()) {
			Point point;
			in >> x;
			point.x = x;
			in >> y;
			point.y = y;
			dot.push_back(point);
		}
	}
	string name() {
		return "i am poligon";
	}
	double area() {
		double ar = 0;
		for (int i = 0; i < dot.size() - 2; i++) {
			ar += ((dot[i + 1].x - dot[0].x) * (dot[i + 2].y - dot[0].y)) - ((dot[i + 1].y - dot[0].y) * (dot[i + 2].x - dot[0].x));
		}
		ar = abs(ar) / 2;
		return ar;
	}
	double perim() {
		double per = 0;
		for (int i = 0; i < dot.size() - 1; i++) {
			per += sqrt((dot[i + 1].x - dot[i].x) * (dot[i + 1].x - dot[i].x) + (dot[i + 1].y - dot[i].y) * (dot[i + 1].y - dot[i].y));
		}
		per += sqrt((dot[dot.size() - 1].x - dot[0].x) * (dot[dot.size() - 1].x - dot[0].x) +
			(dot[dot.size() - 1].y - dot[0].y) * (dot[dot.size() - 1].y - dot[0].y));
		return per;
	}
private:
	vector<Point>dot;
};
