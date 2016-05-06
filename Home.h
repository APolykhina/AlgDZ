#pragma once
#include <vector>
using namespace std;

#define Price_of_HotWater 25
#define Price_of_CouldWater 25
#define Price_of_Electricity 40

struct GKH {
	bool HotWater;
	bool CouldWater;
	bool Electricity;
};

class Home
{
public:
	friend class System;
	int Schet();
	int GetNumberofHome();
	Home();
	Home(int, int,GKH);
	void operator()(int, int, GKH);
	~Home() {};
private:
	int Dolg;
	int IHome;
	int MenCount;
	GKH gkh;
};

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

void Home::operator()(int I, int M,GKH G) {
	IHome = I;
	MenCount = M;
	gkh = G;
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


