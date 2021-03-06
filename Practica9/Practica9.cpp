// Practica9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
class CListNode
{
	CListNode(const char*);
	const char* data;
	CListNode* next;
};

class CList
{
public:
	CList();

	~CList();
	
	intSize();

	// devuelve posici�n donde inserte el nodo... size
	// A parte de a�adir el nodo deber�a hacer ++m_uSize
	int Push(const char*);

	const char* First(); // m_pCurrentNode = m_pFirstNode;
	const char* Next(); // m_CurrentNode = m_pCurrentNode.next;

	// A parte de a�adir el nodo deber�a hacer --m_uSize
	const char* Pop();

private:
	unsigned int m_uSize = 0;
	CListNode* m_pFirstNode = nullptr;

	CListNode* m_pCurrentNode = nullptr;

};
int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
