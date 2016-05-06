#pragma once
#include <string>
#include "podrazdel.h"

using namespace std;

class sotrudnik
{
	string fio;
	char stcom; // 0.не был, 1.отправлен, 2.вернулся, 3.была оплачена
	bool prem; //0....
	double oklad;
	podrazdel *pPodr;


public:

	sotrudnik(const sotrudnik& sotr);
	sotrudnik(string fio1);
	sotrudnik();
	void Print();
	double GetOklad();
	bool GetPrem();
	char GetState();

	sotrudnik(string name1, double oklad1, podrazdel *p);


	void AddtoPodr(podrazdel *p, double oklad1, ostream& out);
	void SetOklad(double newOkl, ostream& out);
	void SetPodr(podrazdel *p, ostream& out);
	~sotrudnik(void);
};

