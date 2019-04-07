#include<iostream>
#include<sstream>
#include<string>
#include<ctime>
#include<vector>
#include "AreaF.h"
using namespace std;

int main(void) {
	setlocale(LC_ALL, "Russian");
	vector<Figures*>fig;
	Poligon* pol =  new Poligon();
	pol->set("in.txt");
	Circle<double>* cir = new Circle<double>(3);
	Rectangle<double>* rec = new Rectangle<double>(3,5);
	Triangle<double>* trig = new Triangle<double>(3,4,5);
	fig.push_back(pol);
	fig.push_back(cir);
	fig.push_back(rec);
	fig.push_back(trig);
	double sumAr = 0;
	double sumPer = 0;
	for (int i = 0; i < fig.size(); i++) {
		cout << fig[i]->name()<<"  area= "<< fig[i]->area() <<"  perim= "<< fig[i]->perim() << endl;
		sumAr += fig[i]->area();
		sumPer += fig[i]->perim();
	}
	cout << "сумма площадей= " << sumAr << "  сумма периметров= " << sumPer << endl;
	system("pause");
	return 0;
}
