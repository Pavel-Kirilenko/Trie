#pragma once
#include<string>

using namespace std;

#define ALPHABET_SIZE 26
struct TrieNode
{
	struct TrieNode* children[ALPHABET_SIZE];
	// isEndOfWord - true, ���� ���� �������� ������ �����
	bool isEndOfWord;
	~TrieNode();                                                     // ���������� ���������
	TrieNode* getNewNode();                                          // ���������� ����� ���� � �������� ����������� �� �����
	void insert(TrieNode* root, string key);                         // �������� ���� � ������ 
	void findEveryWord(TrieNode* root, string* array, string& tip, int& index);  // ����� ������ �������, ������� � ����������� ����
	TrieNode* findChildren(TrieNode* root, string key);              // ����� ���� '�hildren' �� ������
};
