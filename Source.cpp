#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <Windows.h>
#include<fstream>

using namespace std;
struct words { string word; };//��������� ����� � �����
//����� ��������
void kol_vo_sim(string str)
{
	// ����� ���������� �������� � ��������� � �����������, ����� ���������� ���� � ������
	int probel = 0, slovo = 0; //�������, �����
	int i = 0; // i-���������� �������� 
	while (str[i] != '\0') // ������� ����� �����������, ���� ������ �� ����������
	{
		if (str[i] == ' ') // �������� �� ��������� �������
		{
			if (str[i] == '.' || str[i] == '!' || str[i] == ',' || str[i] == '?') //�������� �� ��������� ���� �������
				i++;
			else {
				probel++;
				i++;
			}
		}
		else
		{
			while (str[i] != ' ') // ������� ����� �����������, ���� ������ �� ��������� ��������
			{
				if (str[i] == '\0') // �������� , �� ����������� �� ������?
					break;
				else {
					if (str[i] == '.' || str[i] == '!' || str[i] == ',' || str[i] == '?') // �������� �� ��������� ���� ��������
						i++;
					else  i++;
				}

			}

			slovo++;
		}

	}



	cout << "���������� �������� � ���������: " << i << endl;
	cout << "���������� �������� ��� �������� :" << i - probel << endl;
	cout << "��������� ����: " << slovo << endl;
}
int main()
{
	SetConsoleCP(1251);// ��������� ���������� ������� ������� � ������/������� 
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	string s="0";//���
	int num_str = 0;//����� � ���-�� �����
	struct words mas[100];//������ �������� 
	ofstream f("text.txt");
	cout << "������� ����� ���������, ��� ��������� ����� ������� ������ ������:"<<endl<<endl;

	while (s!="")//���� ������ �� �������
	{
		getline(cin, s);
		f << s<<endl;	
		mas[num_str].word = s;//��������� ��������� �� �������
		num_str++;//����������� ���������� ����� 
	}
	f.close();
	cout << "���������� ����� � �����: " << num_str-1<<endl;
	for (int i = 0; i < num_str-1; i++)
	{
		cout << "������ ����� " << i+1 << endl;
		cout << mas[i].word << endl;
		kol_vo_sim(mas[i].word);//��������� ������� ��� ������ ���������� ��������
		cout<<endl;
	}
	

	system("pause");
	return 0;

}