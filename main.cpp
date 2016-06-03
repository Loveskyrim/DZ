#include <iostream>
#include "sotrudnik.h"
#include "podrazdel.h"
#include <locale.h>
#include <fstream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "rus");
	podrazdel	*pPodr;
	sotrudnik   *pSotr;
	string name;
	double oklad;
	ofstream *ofs; // ������ - ���� ��� ������
	ifstream *ifs; // ������ - ���� ��� ������
	list<podrazdel> listPodr;
	while (1)
	{

	
	cout << endl << "����� ������ ";
	cout << endl << "1-���� ������, 2-������ �� �����, 3-������ � ����, 4-������ ������, 5-������ ��������� �������� ��� �������������, 6- ����� ����������� � ���������� �������������, 7- ������ ���� ������, 8- ����� ����������, 9- ���������� ������ ������������� 10-�����" << endl;
	int reg;
	cin >> reg;
	bool flag;
	int n;
	ofstream myLog("MyLog.txt");
	try
	{
	
	switch (reg)
	{
	case 1://���� ������ (1 �������������)
		cout << "������� �������� �������������: "<< endl;
		cin >> name;
		pPodr=new podrazdel(name);
		do
		{
			cout<< "������� ��� ����������:"<< endl;
				cin >> name;
				cout <<"������� �����"<<endl;
				cin >> oklad;
				pSotr=new sotrudnik(name, oklad);
				*pPodr+*pSotr;// �������� ���������� � �������������
				cout <<"���������� ���� �����������? 1-��, 0-���"<< endl;
				cin >> flag;
		} while (flag);
		
		listPodr.push_back(*pPodr); // ��������� ������������� � ������
		
		
		break;
	
	case 2:// ������ �� �����
		ifs=new ifstream("MyData.dat");
		listPodr.clear();
		*ifs>>n;
		for(int i=0; i<n; i++) {
			pPodr=new podrazdel;
			pPodr->readFromFile(*ifs, myLog);
			listPodr.push_back(*pPodr); // ��������� ������������� � ������
		}
		ifs->close();
		delete ifs;

	break;
		
	case 3:// ������ � ����	
		ofs=new ofstream("MyData.dat");
		*ofs<<listPodr.size()<<endl;
		for(auto pos: listPodr) pos.PrintInFile(*ofs);
		ofs->close();
		delete ofs;

		break;
	case 4: // ������ ������
		for(auto pos: listPodr) 
			pos.print();

		break;
	case 5: // ������ �������� ��� �������������
		for(auto pos: listPodr) 
			cout<<pos.getName()<<' '<<"����� ��������: "<<pos.getZarp();
		break;

	case 6:
		flag=0;
		for(auto pos: listPodr) 
		{
			cout<<pos.getName()<<endl;
			for(auto pos2: pos.getList()) if (pos2.GetState()==3) {
				pos2.Print();
				flag=1;
			}
		}
		if (flag==0)
			cout<<"List is empty"<<endl;
		break;
	case 7: // ������ ���� ������
		for(auto pos: listPodr) 
		   pos.print();

		break;
	case 8:
		{
			
		cout<<"������� �������� �������������: "; cin>>name;
		list<podrazdel>::iterator pos, pos1;
	    for(pos=listPodr.begin(); pos!=listPodr.end(); ++pos)
		if ((*pos).getName()==name) {
			 break;
		}
		if (pos==listPodr.end())
		{
			throw "��� ������������� � ������ "+name;
		}
		string name2;
		cout<<"������� ��� ����������: "; cin>>name2;
		list<sotrudnik>::iterator pos2;
	    for(pos2=pos->getList().begin(); pos2!=pos->getList().end(); ++pos2)
		if ((*pos2).GetFio()==name2) {
			 break;
		}
		if (pos2==pos->getList().end())
		{
			throw "��� ���������� "+name2+" � ������������� "+name;
		}
		pos2->Print();
		cout<<" �������� � �����������: 1- ��������� 2- ������� 3- �������� �������� 4- ��������� ������ 5- �������� ������ 6- ����� � �������� ����: ";
		int reg2;

		cin>>reg2;
		switch(reg2)
		{
		case 1: 
			{
			cout<<"������� �������� ������������� ��� ��������: "; cin>>name;
			
	        for(pos1=listPodr.begin(); pos1!=listPodr.end(); ++pos1)
		      if ((*pos1).getName()==name) {
			 break;
			}
			if (pos1==listPodr.end())
			{
				throw "��� ������������� � ������ "+name;
			}
			// �������
			sotrudnik *pSotr=new sotrudnik(*pos2);
			(*pos)-(*pos2);
			(*pos1)+(*pSotr);
			}
			break;
		case 2:
			(*pos)-(*pos2);
			
			break;
		
		case 3:
			cout<<"����� ��������: "; cin>>oklad;
			pos2->SetOklad(oklad, myLog);
			break;
		case 4:
			
			pos2->SetPrem(true);
			cout<<"������ ���������."<<endl;
			break;
		case 5:
			
			pos2->SetPrem(false);
			cout<<"������ ��������."<<endl;
			break;
		case 6:
			break;
		
		} // switch(reg2)
		}
		break;

	case 9: // ���������� ������ �������������
		{
			cout<<"������� �������� �������������: "; cin>>name;
		   list<podrazdel>::iterator pos;
	        for(pos=listPodr.begin(); pos!=listPodr.end(); ++pos)
		    if ((*pos).getName()==name) {
			      break;
		    }
		    if (pos==listPodr.end())
			{
			throw "��� ������������� � ������ "+name;
		    }
			double summa;
			cout<<"��������� ������ ������ ��� ����� �������������: "; cin>>summa;
			pos->setprimiy(summa);
		}
		break;
			


	case 10:// �����
		myLog.close();
		return;
	}
	}  // ����� try
	catch(string str)
	{
		cout<<"�������� ����������: "<<str<<endl;

	}
	}
}