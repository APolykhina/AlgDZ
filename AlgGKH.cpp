// AlgGKH.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <locale.h>
#include "Home.h"
#include <iostream>
#include <string>
#include "System.h"
using namespace std;


int main()
{
	string S,c;
	int Num,Ch;
	bool G;
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

	while (S != "end") {
		cin >> S;
		if (S=="AddHome"){
			cout << "Number of Home" << endl;
			cin >> Num;
			cout <<  "Count of men" << endl;
			cin >> Ch;
			cout << "If GKH switch on,write 1, or white 0" << endl;
			cout << "HotWater ";
			cin >> temp.HotWater;
			cout << "CouldWater ";
			cin >> temp.CouldWater;
			cout << "Electricity";
			cin >> temp.Electricity;
			D(Num, Ch, temp);
			UChet.InsertHome(D);
		}
		if (S == "DeleteHome") {
			cout << "Write number of home,whitch you want to delete" << endl;
			cin >> Num;
			UChet.DeleteHome(Num);
		}
		if (S == "ChangeGKH") {
			cout << "Write number of home,whitch you want change GKH" << endl;
			cin >> Num;
			cout << "Write name of services and her new status(1-switch on/0-switch off)" << endl;
			cin >> c;
			cin >> G;
			UChet.ChangeGKH(Num, c, G);
			}
		if (S == "ChangeNumOfMen") {
			cout << "Write number of home,whitch you want change count of men and new count of men" << endl;
			cin >> Num;
			cin >> Ch;
			UChet.ChangeNumofMen(Num, Ch);
		}
		if (S == "GetSchet") {
			cout << "Write number of home,whitch account you want to have " << endl;
			cin >> Num;
			cout << UChet.GetSchet(Num) << endl;
		}
		if (S == "PaySchet") {
			cout << "Write number of home,whitch pay account and contribution " << endl;
			cin >> Num;
			cin >> Ch;
			UChet.paySchet(Num, Ch);
		}
		if (S == "GetDolg") {
			vector<int> temp=UChet.GetDolg();
			for (int i = 0; i < temp.size(); i++) {
				cout << temp[i] << " ";
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
			}
		}
		if (S == "GetElectricity") {
			vector<int> temp = UChet.GetElectricity();
			for (int i = 0; i < temp.size(); i++) {
				cout << temp[i] << " ";
			}
		}
	}

    return 0;
}

