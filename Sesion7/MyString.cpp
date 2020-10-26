#include "MyString.h"	
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "MyString.h"
#include "String.h"

CMyString::CMyString()
{
	printf("CMyString::CMyString() \n");
	Init(NULL);
}

CMyString::~CMyString()
{
	delete[]m_pszBuffer;
	m_pszBuffer = NULL;
}

// ********************************************************************
// Constructor
// ********************************************************************
CMyString::CMyString(const char* pszString)
{
	Init(pszString);
}

// ********************************************************************
// Constructor de copia
// ********************************************************************
CMyString::CMyString(const CMyString& strScr)
{
	Init(strScr.m_pszBuffer);
}

// ********************************************************************
// Init, para reutilizar código
// ********************************************************************
void CMyString::Init(const char* pszString)
{
	m_uLen = 0;
	m_pszBuffer = NULL;

	printf("CMyString::CMyString(const char *pszString): %s\n", pszString);
	if (pszString)
	{
		m_uLen = strlen(pszString);
		m_pszBuffer = new char[m_uLen + 1];
		strcpy(m_pszBuffer, pszString);
	}
}

// ********************************************************************
// Operador de asignación
// ********************************************************************
const CMyString& CMyString::operator=(const char* pszSrc)
{
	printf("const CMyString &CMyString::operator=(const char *pszSrc): %s \n", pszSrc ? pszSrc : "NULL");

	delete[]m_pszBuffer;
	m_pszBuffer = NULL;

	if (pszSrc)
	{
		m_uLen = strlen(pszSrc);
		m_pszBuffer = new char[m_uLen + 1];
		strcpy(m_pszBuffer, pszSrc);
	}
	return *this;
}

// ********************************************************************
// Operador de asignación
// ********************************************************************
const CMyString& CMyString::operator=(const CMyString& strSrc)
{
	printf("const CMyString &CMyString::operator=(const CMyString& strSrc): %s \n", strSrc.m_pszBuffer ? strSrc.m_pszBuffer : "NULL");

	delete[]m_pszBuffer;
	m_pszBuffer = NULL;

	if (strSrc.m_pszBuffer)
	{
		m_uLen = strlen(strSrc.m_pszBuffer);
		m_pszBuffer = new char[m_uLen + 1];
		strcpy(m_pszBuffer, strSrc.m_pszBuffer);
	}

	return *this;
}

const char* CMyString::GetBuffer()
{
	return m_pszBuffer;
}

// ********************************************************************
// Operador de ++
// ********************************************************************
const CMyString& CMyString::operator++()
{
	if (m_pszBuffer)
	{
		char* pszAux = m_pszBuffer;
		m_pszBuffer = new char[32];
		_itoa(atoi(pszAux) + 1, m_pszBuffer, 10);
		delete[]pszAux;
	}
	return *this;
}

// ********************************************************************
// Operador ++
// ********************************************************************
const CMyString& CMyString::operator++(int)
{
	operator++();
	return *this;
}

// ********************************************************************
// Operador +=
// ********************************************************************
CMyString& CMyString::operator+=(const CMyString& Op2)
{
	printf("const CMyString &operator+(const CMyString& Op2): %s \n", Op2.m_pszBuffer ? Op2.m_pszBuffer : "NULL");

	char* pszAux = m_pszBuffer;
	m_pszBuffer = NULL;

	if (Op2.m_pszBuffer)
	{
		unsigned int uLen = m_uLen + Op2.m_uLen;
		m_pszBuffer = new char[uLen + 1];
		if (pszAux)
			strcpy(m_pszBuffer, pszAux);
		else
			m_pszBuffer[0] = '\0';
		strcat(m_pszBuffer, Op2.m_pszBuffer);
	}

	delete pszAux;

	return *this;
}

const CMyString operator+(const CMyString& Op1, const CMyString& Op2)
{
	CMyString oRet = CMyString(Op1).operator+=(Op2);
	return oRet;
}

// **************************************************************
// new y delete
// **************************************************************
void* CMyString::operator new (unsigned int uSize)
{
	return ::operator new(uSize);
}

void CMyString::operator delete (void* ptr)
{
	::operator delete(ptr);
}
