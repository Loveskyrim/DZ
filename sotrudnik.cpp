#include "sotrudnik.h"
#include <iostream>

sotrudnik::sotrudnik(void)
{
}

sotrudnik::sotrudnik(string fio1)
{
	fio=fio1;
//	oklad=oklad1;
	//pPodr=p;
}

	void sotrudnik::Print()
	{
		cout<< endl << "Name Surname" << fio << "oklad" ;/////
	}
	
	double sotrudnik::GetOklad()
	{
		return oklad;
	}
	
	bool sotrudnik::GetPrem()
	{
		return prem;
	}
	
	char sotrudnik::GetState()
	{
		return stcom;
	}

	sotrudnik::sotrudnik(string name1, double oklad1, podrazdel *p)
		{
			fio=name1;
			oklad=oklad1;
			pPodr=p;
			pPodr->listst.push_back(*this);
		}



	void sotrudnik::SetOklad(double newOkl, ostream& out)
	{
		oklad=newOkl;
		out << endl << "��������� ������ ���������� " << fio << " ����� �����: " << oklad ;

	}

	void sotrudnik::SetPodr(podrazdel *p, ostream& out)
	{
		pPodr=p;
		out << endl << "��������� �� ���������" ;///////
	}

		void sotrudnik::AddtoPodr(podrazdel *p, double oklad1, ostream& out)
		{
			oklad=oklad1;
			pPodr=p;
			pPodr->listst.push_back(*this);
			out << endl << "��������� �� ���������" ;///////
		}


sotrudnik::~sotrudnik(void)
{
}
