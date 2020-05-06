#ifndef STRING_H
#define STRING_H
#include <iostream>

namespace TheUltimateString
{
	class String
	{
		// Number of characters in the string
		unsigned int elementNum;
		// Pointer to the memory segment containing the characters
		char* pData;
	
	public:
		// Default constructor (without arguments)
		String();

		// Copy constructor
		String(const String& string);

		// Conversion constructor that expects a char* with '\0' at the end
		// This constructor is responsible for the conversion char*-> String
		String(const char* str);

		// Constructor with a char (c) and an int parameter (times)
		// This constructor creates a string that contains 'times' pieces of the character c
		// e.g. if c='$' and times=5 then String="$$$$$"
		String(char c, unsigned int times);

		// Destructor
		~String(){ delete[] pData;}
		
		// Returns the length of the string
		unsigned int getLength() const { return elementNum; }

		// Writes the string to the given stream
		void print(std::ostream& os);

		// Returns with the character at the given position, otherwise 0
		char& operator[](unsigned int pos);
		// Returns with the constant character at the given position
		const char& operator[](unsigned int pos) const;
		
		// Overloaded operators
		String operator+(const String& theOther) const;
		String& operator+=(const String& theOther);
		String& operator=(const String& theOther);
		bool operator==(const String& theOther) const;
		bool operator!=(const String& theOther) const;
		
		// Returns with a read-only access to String
		operator const char*() const;

		// --- Static functions. They operate on two strings. ---
		
		// Concatenates two strings
		static String concatenate(const String& string1, const String& string2);

		// Compares two strings
		static bool isEqual(const String& string1, const String& string2);

		// Copies the second string to the first one
		static void copy(String& string1, const String& string2);
	};
}
#endif /* STRING_H */