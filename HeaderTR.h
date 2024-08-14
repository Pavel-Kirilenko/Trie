#pragma once
#include<string>

using namespace std;

#define ALPHABET_SIZE 26
struct TrieNode
{
	struct TrieNode* children[ALPHABET_SIZE];
	// isEndOfWord - true, если ключ является концом слова
	bool isEndOfWord;
	~TrieNode();                                                     // Деструктор структуры
	TrieNode* getNewNode();                                          // Возвратить новый узел с нулевыми указателями на детей
	void insert(TrieNode* root, string key);                         // Вставить ключ в дерево 
	void findEveryWord(TrieNode* root, string* array, string& tip, int& index);  // Найти каждый суффикс, начиная с переданного узла
	TrieNode* findChildren(TrieNode* root, string key);              // Найти узел 'сhildren' по строке
};
