#pragma once
#include <iostream>
#include <vector>
using namespace std;

#define Price_of_HotWater 25
#define Price_of_CouldWater 25
#define Price_of_Electricity 40

struct GKH {
	int HotWater;
	int CouldWater;
	int Electricity;
};

class Home
{
public:
	friend ostream& operator<<(ostream& , const Home&);
	friend class System;
	int Schet();
	int GetNumberofHome();
	Home();
	Home(int, int,GKH);
	void operator()(int, int, GKH,int);
	~Home() {};
private:
	int Dolg;
	int IHome;
	int MenCount;
	GKH gkh;
};

ostream& operator<<(ostream& os, const Home& H) {

	os << "Number " << H.IHome << endl;
	os << "CountMen " << H.MenCount << endl;
	os << "HotWater " << H.gkh.HotWater << endl;
    os << "CouldWater " << H.gkh.CouldWater << endl; 
	os << "Electicity " << H.gkh.Electricity <<endl ;
	os <<"Dolg " << H.Dolg <<endl ;
	return os;
}

int Home::Schet() {
	int sum =0;
	if (gkh.CouldWater) {
		sum = sum + Price_of_CouldWater;
	}
	if (gkh.HotWater) {
		sum = sum + Price_of_HotWater;
	}
	if (gkh.Electricity) {
		sum = sum + Price_of_Electricity;
	}
	return MenCount*sum;
}

int Home::GetNumberofHome() {
	return IHome;
}

void Home::operator()(int I, int M,GKH G,int D) {
	IHome = I;
	MenCount = M;
	gkh = G;
	Dolg = D;
}

Home::Home() {
	IHome = 0;
	gkh.CouldWater = gkh.Electricity = gkh.HotWater = false;
	MenCount = 0;
	Dolg = 0;
}

Home::Home(int I, int M,GKH G) {
	IHome = I;
	MenCount = M;
	gkh = G;
	Dolg = 0;
}




