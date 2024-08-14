#include<iostream>
#include"HeaderTR.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	system("chcp 1251");                        // ������ ��� ����������� ����������� ������������� ��������
	TrieNode root;                              // �������� ���������� ������ TrieNode
	TrieNode* dictionary = root.getNewNode();   // ���������������� ���������� ��� �������� ���� � �������
	dictionary->insert(dictionary, "apple");    // ������ ��������� ����� � �������
	dictionary->insert(dictionary, "approve");
	dictionary->insert(dictionary, "apricot");
	dictionary->insert(dictionary, "be");
	dictionary->insert(dictionary, "bee");
	dictionary->insert(dictionary, "bees");
	dictionary->insert(dictionary, "busy");
	dictionary->insert(dictionary, "cat");
	dictionary->insert(dictionary, "car");
	dictionary->insert(dictionary, "carry");

	cout << "��������� ������������� ������ ��������� ��� �������������� ������ �� ������ ����������� ������" << endl;
	cout << "��������� �������� ������ ��� ����� �������� ���� ���������� ��������" << endl << endl;
	string suffixSet[50];        // �������� ������ ��� �������� ���������
	for (int i = 0; i < 50; i++) // ���������������� ������ ��� �������� ��������� ��������� "!"
		suffixSet[i] = "!";
	string contProcNumber = "0"; // ���������� �� �������� ������� ������� ��� ���������. ��� ������ �� ����������� 
		                         // ������������ ��������� � ������������� �����
	string word;                 // ���������� ��� �������� ������� ����
	while (true)
	{
		while (contProcNumber != "1" && contProcNumber != "2" 
			&& contProcNumber != "3" && contProcNumber != "4")  //  ������ �� ������������� ����� ������ ���������� ��������
		{
			cout << "�������� ��������: 1 - �������� ����� � �������; 2 - ������ ������ �����; 3 - �������� �������; 4 - �����." << endl;
			getline(cin, contProcNumber);
		}
		if (contProcNumber == "4") break;
		if (contProcNumber == "1")
		{
			cout << "������� �����: ";
			getline(cin, word);
			for (int i = 0; i < word.size(); i++)    // ���������, ��� ������� ������ �������� ��������� �������
			{
				if (word.substr(i, 1) < "a" || word.substr(i, 1) > "z")
				{
					contProcNumber = "0";
				}
			}
			if (contProcNumber == "0")
			{
				cout << "������ ������������ ������ (�������). ����� �� ���������" << endl;
				continue;
			}
			dictionary->insert(dictionary, word);
			contProcNumber = "0";
		}
		if (contProcNumber == "2")
		{
			cout << "������� ������ �����: ";
			getline(cin, word);                      // �������� ������
			for (int i = 0; i < word.size(); i++)    // ���������, ��� ������� ������ �������� ��������� �������
			{
				if (word.substr(i, 1) < "a" || word.substr(i, 1) > "z")
				{
					contProcNumber = "0";
				}
			}
			if (contProcNumber == "0")
			{
				cout << "������ ������������ ������ (�������)" << endl;
				continue;
			}
			if (dictionary->findChildren(dictionary, word))  // ���� �������� ��� ���������� �������� ���� � �������
			{
				string w = "";
				int j = 0;
				int& index = j;
				dictionary->findEveryWord(dictionary->findChildren(dictionary, word), suffixSet, w, index); // ������� ��� ��������
				int i = 0;                                                                          // ��������� �������� � ������
				cout << "��������: " << endl;
				while (suffixSet[i] != "!") // �������� �������� �� ������� ���� �� ����� ���������� ������� ������� �������� ��������
				{                           // (����� ������ ������� ������, �� ���� ��� �������� ���������)
					cout << i + 1 << " - " << word << suffixSet[i] << endl; // ����� �� ������� ��������� ���������
					i++;
				}
				string nOfWord;             // ���������� ��������� ����� ��������, �������� � �������
				int numOfWord = 0;          // ����� �������� � ���� int
				while (numOfWord == 0)                     // ���� ������������ ���� �� ������� ���������� ������
				{
					cout << "������� ����� ��������: ";
					getline(cin, nOfWord);                 // ������ ����� �������� �� ������������ ����
					numOfWord = atoi(nOfWord.c_str());     // ��������� ��������� �������� string � integer
					if (numOfWord < 1 || numOfWord > 50)   // ���� ������ ����� ��� �������� ������� � ����������
					{
						cout << "������� �������� ��� � ������" << endl;  // ������� ��������������
						numOfWord = 0;
					}
					else if (suffixSet[numOfWord - 1] == "!")             // ���� � ������� ����������� ������� � ������ �������
					{
						cout << "������� �������� ��� � ������" << endl;  // ������� ��������������
						numOfWord = 0;
					}
					else cout << word << suffixSet[numOfWord - 1] << endl;        // ����� ������� �����
				}
			}
			else cout << "����������� � ������� ��������� ����������� � �������" << endl;
			int i = 0;
			while (suffixSet[i] != "!") // ������������ ������ � �������� ��������� ��� ���������� ��������
			{
				suffixSet[i] = "!";     // �������������� ��������� ��������� ������� ��� ���������� ��������
				i++;
			}
			contProcNumber = "0";
		}
		if (contProcNumber == "3")
		{
			string w = "";
			int j = 0;
			int& index = j;
			dictionary->findEveryWord(dictionary, suffixSet, w, index); // ������� � ������ �������� ���� ���������
			int i = 0;
			while (suffixSet[i] != "!")
			{  
				cout  << suffixSet[i] << endl; // ����� �� ������� ���� ���� � �������
				suffixSet[i] = "!";            // �������������� ��������� ��������� ������� ��� ���������� ��������
				i++;
			}
			contProcNumber = "0";
		}
	}

	return 0;
}