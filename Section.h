#pragma once
#include"Books.h"
#include<vector>
class Section
{
public:
	Section();
	~Section();
	void setSectionNum(string sectionNum);
	void addRequiredBook(string ISBN);
	void addOptionalBook(string book);
	string getSectionNum();
	vector<string> getAllBook();
	vector<string> getAllRequiredBook();
	vector<string> getAllOptionalBook();
private:
	string sectionNumber;
	vector<string> required_bookSection; // Only store ISBN for books in the vector.
	vector<string> optional_bookSection;

};

