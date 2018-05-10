#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <Windows.h>
#include<fstream>

using namespace std;
struct words { string word; };//структура строк с файла
//посик символов
void kol_vo_sim(string str)
{
	// поиск количества символов с пробелами и безпробелов, поиск количества слов в строке
	int probel = 0, slovo = 0; //пробелы, слово
	int i = 0; // i-количество символов 
	while (str[i] != '\0') // условие цикла выполняется, пока строка не закончится
	{
		if (str[i] == ' ') // проверка на равенство пробелу
		{
			if (str[i] == '.' || str[i] == '!' || str[i] == ',' || str[i] == '?') //проверка на равенство спец символу
				i++;
			else {
				probel++;
				i++;
			}
		}
		else
		{
			while (str[i] != ' ') // условие цикла выполняется, пока строка не равняется пробелом
			{
				if (str[i] == '\0') // проверим , не закончилась ли строка?
					break;
				else {
					if (str[i] == '.' || str[i] == '!' || str[i] == ',' || str[i] == '?') // проверка на равенство спец символам
						i++;
					else  i++;
				}

			}

			slovo++;
		}

	}



	cout << "Количество символов с пробелами: " << i << endl;
	cout << "Количество символов без пробелов :" << i - probel << endl;
	cout << "Колисетво слов: " << slovo << endl;
}
int main()
{
	SetConsoleCP(1251);// позволяет записывать русские символы в строки/массивы 
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");

	string s="0";//кэш
	int num_str = 0;//номер и кол-во строк
	struct words mas[100];//массив структур 
	ofstream f("text.txt");
	cout << "Введите текст построчно, для окончания ввода введите пустую строку:"<<endl<<endl;

	while (s!="")//пока строка не нулевая
	{
		getline(cin, s);
		f << s<<endl;	
		mas[num_str].word = s;//заполняет структуру по индексу
		num_str++;//увеличивает количество строк 
	}
	f.close();
	cout << "Количество строк в файле: " << num_str-1<<endl;
	for (int i = 0; i < num_str-1; i++)
	{
		cout << "Строка номер " << i+1 << endl;
		cout << mas[i].word << endl;
		kol_vo_sim(mas[i].word);//запускаем функцию для поиска количества символов
		cout<<endl;
	}
	

	system("pause");
	return 0;

}