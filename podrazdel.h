#include <string>
#include  <list>
using namespace std;
#include "sotrudnik.h"
#pragma once




class podrazdel
{
	string name;
	list <sotrudnik> listst;
public:
	
	podrazdel(string name1);
	podrazdel(string name1, double oklad1, podrazdel *p);

	void AddSotr(sotrudnik& sotr, ostream& out);
	
	podrazdel(void);
	~podrazdel(void);
	friend class sotrudnik;
};

