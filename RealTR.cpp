#include<iostream>
#include<string>
#include"HeaderTR.h"
using namespace std;

/* ���������� ��������� */
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
/* ������� ������������� ���� */
TrieNode* TrieNode::getNewNode()                // ���������� ����� ���� � �������� ����������� �� �����
{
    struct TrieNode* pNode = new TrieNode;      // �������� ������ ��� ����� ����
    pNode->isEndOfWord = false;                 // ���������� �������� ����� ����� ��� false
    for (int i = 0; i < ALPHABET_SIZE; i++)     // ���������������� ���������� �� ����� ������
        pNode->children[i] = nullptr;

    return pNode;
}
/* ������� ������� ����� � ������ */
void TrieNode::insert(TrieNode* root, string key) // �������� ���� � ������  
{
    bool wordExist = false;                      // ����������, ������� ����������, ��� �������� ����� ��� ���� � �������
    TrieNode* current = root;                    // ������ � ����� ������
    for (int i = 0; i < key.length(); i++)       
    {
        int index = key[i] - 'a';                // �������� ������ �������� ������� � ��������

        if (!current->children[index])                // ���� ��� ����� � ������ ��������, ��
        {
            current->children[index] = getNewNode();  // ������� ����� ����
            wordExist = false;
        }
        else wordExist = true;
        current = current->children[index];      // ������� � �����
    }
    current->isEndOfWord = true;                 // �������� ����� �����
}
/* ������� ������� ������ ������� � ������, ������� � ����������� ���� "children" � ������� � ������ 'array' */
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
    tip.erase(tip.size() - 1);  // �������� ���������� ������� ��� ������ ������
                                // �� ���������� ��������� �������
}
/* ������� ������� � ���������� ������ ���� "children" �� ������ */
TrieNode* TrieNode::findChildren(TrieNode* root, string key)
{
    if (root == nullptr) return root;
    for (int i = 0; i < key.size(); i++)
    {
        if (root->children[key[i] - 'a'])         // ���� � ������� ������� 'children' ���� ���� � ������� �������� ������ 'key'
            root = root->children[key[i] - 'a'];  // �� ��������� � ����� ����
        else return nullptr;                      // ����� ���������� nullptr
    }
    return root;
}
