#include "podrazdel.h"
#include "sotrudnik.h"

podrazdel::podrazdel(void)
{
}

	podrazdel::podrazdel(string name1)
	{
		name=name1;
	}

	
void podrazdel::AddSotr(sotrudnik& sotr, ostream& out)
	{
		listst.push_back(sotr);
	}

podrazdel::~podrazdel(void)
{
}
