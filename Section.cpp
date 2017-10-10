#include "Section.h"



Section::Section()
{
}


Section::~Section()
{
}

void Section::setSectionNum(string sectionNum)
{
	this->sectionNumber = sectionNum;
}

void Section::addRequiredBook(string ISBN)
{
	for (int i = 0; i < this->required_bookSection.size(); i++) {
		if (this->required_bookSection.at(i).compare(ISBN) == 0) { // Book already exists.
			return;
		}
	}
	this->required_bookSection.push_back(ISBN);
}

void Section::addOptionalBook(string ISBN)
{
	for (int i = 0; i < this->optional_bookSection.size(); i++) {
		if (this->optional_bookSection.at(i).compare(ISBN) == 0) { // Book already exists.
			return;
		}
	}
	this->optional_bookSection.push_back(ISBN);
}

string Section::getSectionNum()
{
	return sectionNumber;
}

vector<string> Section::getAllBook()
{
	vector<string> allISBN;
	for (int i = 0; i < this->getAllRequiredBook().size(); i++) {
		allISBN.push_back(this->getAllRequiredBook().at(i));
	}
	for (int i = 0; i < this->getAllOptionalBook().size(); i++) {
		allISBN.push_back(this->getAllOptionalBook().at(i));
	}
	//allISBN.insert(allISBN.end(), this->getAllRequiredBook().begin(), this->getAllRequiredBook().end());
	//allISBN.insert(allISBN.end(), this->getAllOptionalBook().begin(), this->getAllOptionalBook().end());
	//cout << "Section:"<<this->getAllRequiredBook().size() << endl;
	//cout << "Section:"<<this->getAllOptionalBook().size() << endl;
	return allISBN;
}

vector<string> Section::getAllRequiredBook()
{
	vector<string> allISBN_forRequiredBook;
	for (int i = 0; i < this->required_bookSection.size(); i++)
		allISBN_forRequiredBook.push_back(this->required_bookSection.at(i));
	return allISBN_forRequiredBook;
}

vector<string> Section::getAllOptionalBook()
{
	vector<string> allISBN_forOptionalBook;
	for (int i = 0; i < this->optional_bookSection.size(); i++)
		allISBN_forOptionalBook.push_back(this->optional_bookSection.at(i));
	return allISBN_forOptionalBook;
}
