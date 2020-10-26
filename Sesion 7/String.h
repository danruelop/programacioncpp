#pragma once

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class CString {
public:
    CString(const char* str = "");
    CString(const CString& str);
    ~CString();

    bool operator==(const CString& other) const;
    bool operator!=(const CString& other) const;
    bool operator<(const CString& other) const;
    bool operator>(const CString& other) const;
    CString operator+(const CString& other) const;
    CString operator+(char c) const;
    CString& operator=(const CString& other);
    CString& operator=(char c);
    CString& operator+=(const CString& other);
    CString& operator+=(char c);
    char& operator[](unsigned int pos);
    const char& operator[](unsigned int pos) const;

    int Length() const;

    static CString FromInt(int val);
    static CString HexFromInt(int val);
    static CString FromFloat(float val);

    int ToInt() const;
    float ToFloat() const;
    const char* ToCString() const;

    CString Left(int n) const;
    CString Right(int n) const;
    CString Mid(int ofs, int n);
    CString Replace(const CString& find, const CString& rep) const;
    int Find(const CString& str, int ofs) const;

    CString ToUpper() const;
    CString ToLower() const;
    CString LTrim() const;
    CString RTrim() const;
    CString Trim() const;
		// Rellena por la izquierda con el caracter "c" hasta completar el pataño pasado "len":
		// 	CString("12345").LSet(10, 'x') --> "xxxxx12345"
    CString LSet(int len, char c) const;
    CString RSet(int len, char c) const;

    CString StripExt() const;
    CString StripDir() const;
    CString ExtractExt() const;
    CString ExtractDir() const;
    CString RealPath() const;

    static CString Read(const CString& filename);
    void Write(const CString& filename, bool append = true) const;
private:
		void *m_p;
};

