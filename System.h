#pragma once
#include "Home.h"
class System{
public:
	friend class Home;
	vector<Home>& GetInf();
	vector<int> GetDolg();
	int DolgHome(int);
	vector<int> GetCouldWater();
	vector<int> GetElectricity();
	vector<int> GetHotWater();
	void paySchet(int, int);
	int GetSchet(int);
	void ChangeNumofMen(int, int);
	void InsertHome(Home&);
	void DeleteHome(int);
	void ChangeGKH(int, string, bool);
	System() {};
	~System() {};
	vector<string> history;
private:
	vector<Home> mas;
};

int System::DolgHome(int N) {
	for (int i = 0; i < mas.size(); i++) {
		if (mas[i].IHome == N) {
			return mas[i].Dolg;
		}
	}
}

vector<Home>& System::GetInf() {
	return mas;
}

vector<int> System::GetElectricity() {
	vector<int> rez;
	for (int i = 0; i < mas.size(); i++) {
		if (mas[i].gkh.Electricity) {
			rez.push_back(mas[i].IHome);
		}
	}
	return rez;
}

vector<int> System::GetCouldWater() {
	vector<int> rez;
	for (int i = 0; i < mas.size(); i++) {
		if (mas[i].gkh.CouldWater) {
			rez.push_back(mas[i].IHome);
		}
	}
	return rez;
}

vector<int> System::GetHotWater() {
	vector<int> rez;
	for (int i = 0; i < mas.size(); i++) {
		if (mas[i].gkh.HotWater) {
			rez.push_back(mas[i].IHome);
		}
	}
	return rez;
}

vector<int> System::GetDolg() {
	vector<int> rez;
	for (int i = 0; i < mas.size(); i++) {
		if (mas[i].Dolg > 0) {
			rez.push_back(mas[i].IHome);
		}
	}
	return rez;
}

void System::paySchet(int N, int sum) {
	for (int i = 0; i < mas.size(); i++) {
		if (mas[i].IHome == N) {
			mas[i].Dolg = mas[i].Schet() + mas[i].Dolg - sum;
		}
	}
}

int System::GetSchet(int N) {
	for (int i = 0; i < mas.size(); i++) {
		if (mas[i].IHome == N) {
			return mas[i].Schet()+mas[i].Dolg;
		}
	}
}

void System::ChangeNumofMen(int N, int Count) {
	for (int i = 0; i < mas.size(); i++) {
		if (mas[i].IHome == N) {
			mas[i].MenCount = Count;
			break;
		}
	}
}

void System::InsertHome(Home& D) {
	for (int i = 0; i < mas.size(); i++) {
		if (D.IHome == mas[i].IHome)
			throw "This number is already in use, create another one ";

	}
	mas.push_back(D);
}

void System::DeleteHome(int N) {
	for (int i = 0; i < mas.size(); i++) {
		if (mas[i].IHome == N) {
			mas.erase(mas.begin() + i);
			break;
		}
	}
}

void System::ChangeGKH(int Num,string c, bool B){
	for (int i = 0; i < mas.size(); i++) {
		if (mas[i].IHome == Num) {
			if (c == "CouldWater") {
				mas[i].gkh.CouldWater = B;
				break;
			}
			if (c == "HotWater") {
				mas[i].gkh.HotWater = B;
				break;
			}
			if (c == "Electricity") {
				mas[i].gkh.Electricity = B;
				break;
			}
		}
	}
}


