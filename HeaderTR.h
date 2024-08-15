#pragma once
#include<string>

using namespace std;

#define ALPHABET_SIZE 26
struct TrieNode
{
	struct TrieNode* children[ALPHABET_SIZE];
	// isEndOfWord - true, указатель конца слова
	bool isEndOfWord;
	~TrieNode();                                                     // Деструктор структуры
	TrieNode* getNewNode();                                          // Функция инициализации узла
	void insert(TrieNode* root, string key);                         // Функция вставки ключа в дерево 
	void findEveryWord(TrieNode* root, string* array, string& tip, int& index);  // Функция находит каждый суффикс в деревеи заносит в массив 'array'
	TrieNode* findChildren(TrieNode* root, string key);              // Функция находит в суффиксном дереве узел "children" по строке
};
