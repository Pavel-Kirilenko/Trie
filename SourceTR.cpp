#include<iostream>
#include"HeaderTR.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	system("chcp 1251");                        // строки для корректного отображения кириллических символов
	TrieNode root;                              // Объявить переменную класса TrieNode
	TrieNode* dictionary = root.getNewNode();   // Инициализировать переменную для хранения слов в словаре
	dictionary->insert(dictionary, "apple");    // Ввести некоторые слова в словарь
	dictionary->insert(dictionary, "approve");
	dictionary->insert(dictionary, "apricot");
	dictionary->insert(dictionary, "be");
	dictionary->insert(dictionary, "bee");
	dictionary->insert(dictionary, "bees");
	dictionary->insert(dictionary, "busy");
	dictionary->insert(dictionary, "cat");
	dictionary->insert(dictionary, "car");
	dictionary->insert(dictionary, "carry");

	cout << "Программа демонстрирует работу алгоритма для автозаполнения текста на основе префиксного дерева" << endl;
	cout << "Программа работает только при вводе строчных букв латинского алфавита" << endl << endl;
	string suffixSet[50];        // Объявить массив для хранения суффиксов
	for (int i = 0; i < 50; i++) // Инициализировать массив для хранения суффиксов символами "!"
		suffixSet[i] = "!";
	string contProcNumber = "0"; // Переменная от значения которой зависит ход алгоритма. Тип выбран из соображений 
		                         // устойчивости программы к некорректному вводу
	string word;                 // Переменная для хранения текущих слов
	while (true)
	{
		while (contProcNumber != "1" && contProcNumber != "2" 
			&& contProcNumber != "3" && contProcNumber != "4")  //  защита от некорректного ввода выбора дальнейших действий
		{
			cout << "Выберите действие: 1 - добавить слово в словарь; 2 - ввести начало слова; 3 - показать словарь; 4 - выход." << endl;
			getline(cin, contProcNumber);
		}
		if (contProcNumber == "4") break;
		if (contProcNumber == "1")
		{
			cout << "Введите слово: ";
			getline(cin, word);
			for (int i = 0; i < word.size(); i++)    // Проверить, что введены только строчные латинские символы
			{
				if (word.substr(i, 1) < "a" || word.substr(i, 1) > "z")
				{
					contProcNumber = "0";
				}
			}
			if (contProcNumber == "0")
			{
				cout << "Введен недопустимый символ (символы). Слово не добавлено" << endl;
				continue;
			}
			dictionary->insert(dictionary, word);
			contProcNumber = "0";
		}
		if (contProcNumber == "2")
		{
			cout << "Введите начало слова: ";
			getline(cin, word);                      // Записать строку
			for (int i = 0; i < word.size(); i++)    // Проверить, что введены только строчные латинские символы
			{
				if (word.substr(i, 1) < "a" || word.substr(i, 1) > "z")
				{
					contProcNumber = "0";
				}
			}
			if (contProcNumber == "0")
			{
				cout << "Введен недопустимый символ (символы)" << endl;
				continue;
			}
			if (dictionary->findChildren(dictionary, word))  // если варианты для введенного суффикса есть в словаре
			{
				string w = "";
				int j = 0;
				int& index = j;
				dictionary->findEveryWord(dictionary->findChildren(dictionary, word), suffixSet, w, index); // Занести все варианты
				int i = 0;                                                                          // окончаний суффикса в массив
				cout << "Варианты: " << endl;
				while (suffixSet[i] != "!") // Выводить суффиксы из массива пока не будет достигнуто условно нулевое значение элемента
				{                           // (далее массив условно пустой, то есть без значащих элементов)
					cout << i + 1 << " - " << word << suffixSet[i] << endl; // Вывод на консоль возможных вариантов
					i++;
				}
				string nOfWord;             // Переменная сохраняет номер варианта, вводимый с консоли
				int numOfWord = 0;          // Номер варианта в виде int
				while (numOfWord == 0)                     // Цикл продолжается пока не введены корректные данные
				{
					cout << "Введите номер варианта: ";
					getline(cin, nOfWord);                 // Ввести номер варианта из предложенных слов
					numOfWord = atoi(nOfWord.c_str());     // Перевести введенное значение string в integer
					if (numOfWord < 1 || numOfWord > 50)   // Если введен номер вне пределов массива с суффиксами
					{
						cout << "Данного варианта нет в списке" << endl;  // Вывести предупреждение
						numOfWord = 0;
					}
					else if (suffixSet[numOfWord - 1] == "!")             // Если в массиве отсутствует суффикс с данным номером
					{
						cout << "Данного варианта нет в списке" << endl;  // Вывести предупреждение
						numOfWord = 0;
					}
					else cout << word << suffixSet[numOfWord - 1] << endl;        // Иначе вывести слово
				}
			}
			else cout << "Продолжения к данному сочетанию отсутствуют в словаре" << endl;
			int i = 0;
			while (suffixSet[i] != "!") // Восстановить массив в исходное состояние для дальнейших действий
			{
				suffixSet[i] = "!";     // Восстановление исходного состояния массива для дальнейших действий
				i++;
			}
			contProcNumber = "0";
		}
		if (contProcNumber == "3")
		{
			string w = "";
			int j = 0;
			int& index = j;
			dictionary->findEveryWord(dictionary, suffixSet, w, index); // Занести в массив значение всех суффиксов
			int i = 0;
			while (suffixSet[i] != "!")
			{  
				cout  << suffixSet[i] << endl; // Вывод на консоль всех слов в словаре
				suffixSet[i] = "!";            // Восстановление исходного состояния массива для дальнейших действий
				i++;
			}
			contProcNumber = "0";
		}
	}

	return 0;
}