#include "String.h"
#include <iostream>
#include <assert.h>

using namespace std;

namespace TheUltimateString
{
	String::String()
	{
		pData = NULL;
		elementNum = 0;
	}

	String::String(const String &string)
	{
		pData = NULL;
		copy(*this, string);
	}

	String::String(const char c, unsigned int times)
	{
		elementNum = times;

		if (elementNum == 0)
		{
			pData = NULL;
			return;
		}

		pData = new char[elementNum + 1];
		for (unsigned int i = 0; i < elementNum; i++)
		{
			pData[i] = c;
		}
		pData[elementNum] = '\0';
	}

	void String::print(ostream &os)
	{
		for (unsigned int i = 0; i < elementNum; i++)
		{
			os << pData[i];
		}
	}

	String String::concatenate(const String &string1, const String &string2)
	{
		String s;
		s.elementNum = string1.elementNum + string2.elementNum;

		if (s.elementNum == 0)
		{
			s.pData = NULL;
			return s;
		}

		s.pData = new char[s.elementNum + 1];

		for (unsigned int i = 0; i < string1.elementNum; i++)
		{
			s.pData[i] = string1.pData[i];
		}
		for (unsigned int j = string1.elementNum; j < s.elementNum; j++)
		{
			s.pData[j] = string2.pData[j - string1.elementNum];
		}

		s.pData[s.elementNum] = '\0';
		return s;
	}

	bool String::isEqual(const String &string1, const String &string2)
	{
		if (string1.elementNum != string2.elementNum)
			return false;

		for (unsigned int i = 0; i < string1.elementNum; i++)
		{
			if (string1.pData[i] != string2.pData[i])
				return false;
		}
		return true;
	}

	void String::copy(String &string1, const String &string2)
	{
		delete string1.pData;
		string1.elementNum = string2.elementNum;
		if (string1.elementNum == 0)
		{
			string1.pData = NULL;
			return;
		}
		string1.pData = new char[string1.elementNum + 1];
		for (unsigned int i = 0; i < string1.elementNum; i++)
		{
			string1.pData[i] = string2.pData[i];
		}
		string1.pData[string1.elementNum] = '\0';
	}
}