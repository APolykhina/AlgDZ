#include "stdafx.h"
#include <vector>
#include <locale.h>
#include "Home.h"
#include <iostream>
#include <string>
#include "System.h"
#include <fstream>
using namespace std;


int main()
{
	string S,c,rez;
	int Num,Ch,Dolg;
	int G;
	char buff[50];
	Home D;
	System UChet;
	GKH temp;

	cout << "Menu of accounting system:" << endl;
	cout << "1-AddHome" << endl;
	cout << "2-DeleteHome" << endl;
	cout << "3-ChangeGKH" << endl;
	cout << "4-ChangeNumOfMen" << endl;
	cout << "5-GetSchet" << endl;
	cout << "6-PaySchet" << endl;
	cout << "7-GetDolg" << endl;
	cout << "8-GetHotWater" << endl;
	cout << "9-GetCouldWater" << endl;
	cout << "10-GetElectricity" << endl;
	cout << "11-history" << endl;
	cout << "12-SaveInf" << endl;
	cout << "13-GetInf" << endl;

	while (S != "end") {
		cin >> S;
		if (S=="AddHome"){
			try {
				cout << "Number of Home" << endl;
				cin >> Num;
				cout << "Count of men" << endl;
				cin >> Ch;
				cout << "If GKH switch on,write 1, or white 0" << endl;
				cout << "HotWater ";
				cin >> temp.HotWater;
				cout << "CouldWater ";
				cin >> temp.CouldWater;
				cout << "Electricity ";
				cin >> temp.Electricity;
				cout << "Dolg ";
				cin >> Dolg;
				D(Num, Ch, temp, Dolg);
				UChet.InsertHome(D);
				rez = S + " № " + to_string(Num) + " Count of people " + to_string(Ch) + " CouldWater " + to_string(temp.CouldWater) + " HotWater " + to_string(temp.HotWater) + " Electicity " + to_string(temp.Electricity);
				UChet.history.push_back(rez);
			}
			catch (char* str) {
				cout << str << endl;
			}
		}
		if (S == "DeleteHome") {
			cout << "Write number of home,whitch you want to delete" << endl;
			cin >> Num;
			UChet.DeleteHome(Num);
			rez = S + " № " + to_string(Num);
			UChet.history.push_back(rez);
		}
		if (S == "ChangeGKH") {
			cout << "Write number of home,whitch you want change GKH" << endl;
			cin >> Num;
			cout << "Write name of services and her new status(1-switch on/0-switch off)" << endl;
			cin >> c;
			cin >> G;
			UChet.ChangeGKH(Num, c, G);
			rez = S + " № " + to_string(Num) + c + " " + to_string(G);
			UChet.history.push_back(rez);
			}
		if (S == "ChangeNumOfMen") {
			cout << "Write number of home,whitch you want change count of men and new count of men" << endl;
			cin >> Num;
			cin >> Ch;
			UChet.ChangeNumofMen(Num, Ch);
			rez = S + " № " + to_string(Num) + " Count of people " + to_string(Ch);
			UChet.history.push_back(rez);
		}
		if (S == "GetSchet") {
			cout << "Write number of home,whitch account you want to have " << endl;
			cin >> Num;
			cout << UChet.GetSchet(Num) << endl;
			rez = S + " № " + to_string(Num);
			UChet.history.push_back(rez);
		}
		if (S == "PaySchet") {
			cout << "Write number of home,whitch pay account and contribution " << endl;
			cin >> Num;
			cin >> Ch;
			UChet.paySchet(Num, Ch);
			rez = S + " № " + to_string(Num) + " Sum " + to_string(Ch);
			UChet.history.push_back(rez);
		}
		if (S == "GetDolg") {
			vector<int> temp=UChet.GetDolg();
			for (int i = 0; i < temp.size(); i++) {
				cout << temp[i] << " ";
			}
     		for (int i = 0; i < temp.size(); i++) {
				rez = S + "  № " + to_string(temp[i])+ " Dolg " +to_string(UChet.DolgHome(temp[i])) ;
				UChet.history.push_back(rez);
			}
		}
		if (S == "GetHotWater") {
			vector<int> temp = UChet.GetHotWater();
			for (int i = 0; i < temp.size(); i++) {
				cout << temp[i] << " ";
			}
		}
		if (S == "GetCouldWater") {
			vector<int> temp = UChet.GetCouldWater();
			for (int i = 0; i < temp.size(); i++) {
				cout << temp[i] << " ";
			};
		}
		if (S == "GetElectricity") {
			vector<int> temp = UChet.GetElectricity();
			for (int i = 0; i < temp.size(); i++) {
				cout << temp[i] << " ";
			}
		}
		if (S == "history") {
			for (int i = 0; i < UChet.history.size(); i++) {
				cout << UChet.history[i] << endl;
			}
		}
		if (S == "SaveInf") {
			ofstream F;
			cout << "write name of file " <<endl;
			cin >> S;
			F.open(S);
			F << "CountHomes " << UChet.GetInf().size() << endl <<endl;
			for (int i = 0; i < UChet.GetInf().size(); i++) {
				F << UChet.GetInf()[i] << endl;
			}
			F.close();
		}
		if (S == "GetInf") {
			ifstream F;
			cout << "write name of file " << endl;
			cin >> S;
			F.open(S);
			if (F.is_open()) {
				F >> buff;
				F >> G;
				int i = 0;
				while (i < G)
				{
					F >> buff;
					F >> Num;
					F >> buff;
					F >> Ch;
					F >> buff;
					F >> temp.HotWater;
					F >> buff;
					F >> temp.CouldWater;
					F >> buff;
					F >> temp.Electricity;
					F >> buff;
					F >> Dolg;
					D(Num, Ch, temp,Dolg);
					UChet.InsertHome(D);
					i++;
					S = "AddHome ";
					rez = S+ "№ " + to_string(Num) + " Count of people " + to_string(Ch) + " CouldWater " + to_string(temp.CouldWater) + " HotWater " + to_string(temp.HotWater) + " Electicity " + to_string(temp.Electricity);
					UChet.history.push_back(rez);
				}
				F.close();
			}
			else
				cout << "File can't open for reading" << endl;
		}
	}
    return 0;
}


