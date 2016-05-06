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

	
	cout << endl << "Выбор режима ";
	cout << endl << "1-ввод данных, 2-чтение из файла, 3-запись в файл, 4-выход" << endl;
	int reg;
	cin >> reg;
	bool flag;
	switch (reg)
	{
	case 1://ввд данных
		cout << "Введите название подразделения: "<< endl;
		cin >> name;
		pPodr=new podrazdel(name);
		do
		{
			cout<< "Введите ФИО сотрудника:"<< endl;
				cin >> name;
				cout <<"Введите оклад"<<endl;
				cin >> oklad;
				pSotr=new sotrudnik(name, oklad, pPodr);
				cout <<"Продолжить ввод сотрудников? 1-да, 0-нет"<< endl;
				cin >> flag;
		} while (flag);
		
		listPodr.push_back(*pPodr);
		
		
		break;
	
	case 2:// чтение из файла
	break;
		
	case 3:// запись в файл	
		break;
		case 4:// выход
		break;
	}
	}
}