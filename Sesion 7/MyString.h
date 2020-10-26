#pragma once

class CMyString
{
public:
	CMyString();
	CMyString(const char *pszString);
	CMyString(const CMyString &pszString);
	~CMyString();

	const CMyString &	operator=(const char *pszSrc);
	const CMyString &	operator=(const CMyString& strSrc);

	const char *GetBuffer();

	const CMyString &operator++();
	const CMyString &operator++(int);

	CMyString&       operator+=(const CMyString& Op2);

	void* operator new (unsigned int uSize);
	void operator delete (void* ptr);

private:
	char				*m_pszBuffer;
	unsigned int m_uLen;

	void Init(const char *pszString);

};

const CMyString operator+(const CMyString& Op1, const CMyString& Op2);

// EOF
