#include<iostream>
#include<string>
#include"HeaderTR.h"
using namespace std;

/* Деструктор структуры */
TrieNode::~TrieNode()
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (children[i])
        {
            children[i] = nullptr;
            delete children[i];
        }
    }
}
/* Функция инициализации узла */
TrieNode* TrieNode::getNewNode()                // Возвратить новый узел с нулевыми указателями на детей
{
    struct TrieNode* pNode = new TrieNode;      // Выделить память под новый узел
    pNode->isEndOfWord = false;                 // Установить значение конца слова как false
    for (int i = 0; i < ALPHABET_SIZE; i++)     // Инициализировать указателей на детей нолями
        pNode->children[i] = nullptr;

    return pNode;
}
/* Функция вставки ключа в дерево */
void TrieNode::insert(TrieNode* root, string key) // Вставить ключ в дерево  
{
    bool wordExist = false;                      // Переменная, которая показывает, что вводимое слово уже есть в словаре
    TrieNode* current = root;                    // Начать с корня дерева
    for (int i = 0; i < key.length(); i++)       
    {
        int index = key[i] - 'a';                // Получить индекс текущего символа в алфавите

        if (!current->children[index])                // Если нет детей с данным индексом, то
        {
            current->children[index] = getNewNode();  // Создать новый узел
            wordExist = false;
        }
        else wordExist = true;
        current = current->children[index];      // Перейти к детям
    }
    current->isEndOfWord = true;                 // Пометить конец слова
}
/* Функция находит каждый суффикс в дереве, начиная с переданного узла "children" и заносит в массив 'array' (рекурсивная) */
void TrieNode::findEveryWord(TrieNode* root, string* array, string& tip, int& index)
{;
    if (root->isEndOfWord)
    {
        array[index++] = tip;
        //cout << " " << tip << endl;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (root->children[i])
        {
            tip += i + 'a';
            findEveryWord(root->children[i], array, tip, index);
        }
    }
    if (tip != "")
    tip.erase(tip.size() - 1);  // удаление последнего символа при каждом выходе
                                // из рекурсивно вызванной функции
}
/* Функция находит в суффиксном дереве узел "children" по строке */
TrieNode* TrieNode::findChildren(TrieNode* root, string key)
{
    if (root == nullptr) return root;
    for (int i = 0; i < key.size(); i++)
    {
        if (root->children[key[i] - 'a'])         // Если в текущем массиве 'children' есть узел с текущим символом строки 'key'
            root = root->children[key[i] - 'a'];  // то переходим к этому узлу
        else return nullptr;                      // иначе возварщаем nullptr
    }
    return root;
}
