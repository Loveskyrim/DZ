#include <iostream>
#include "sotrudnik.h"
#include "podrazdel.h"
#include <locale.h>
using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");
	podrazdel	*pPodr;
	sotrudnik   *pSotr;
	string name;
	double oklad;
	list<podrazdel> listPodr;
	while (1)
	{

	
	cout << endl << "����� ������ ";
	cout << endl << "1-���� ������, 2-������ �� �����, 3-������ � ����, 4-�����" << endl;
	int reg;
	cin >> reg;
	bool flag;
	switch (reg)
	{
	case 1://��� ������
		cout << "������� �������� �������������: "<< endl;
		cin >> name;
		pPodr=new podrazdel(name);
		do
		{
			cout<< "������� ��� ����������:"<< endl;
				cin >> name;
				cout <<"������� �����"<<endl;
				cin >> oklad;
				pSotr=new sotrudnik(name, oklad, pPodr);
				cout <<"���������� ���� �����������? 1-��, 0-���"<< endl;
				cin >> flag;
		} while (flag);
		
		listPodr.push_back(*pPodr);
		
		
		break;
	
	case 2:// ������ �� �����
	break;
		
	case 3:// ������ � ����	
		break;
		case 4:// �����
		break;
	}
	}
}