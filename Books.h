#ifndef BOOKS_H
#define BOOKS_H

#include <string>
#include<iostream>
#include<vector>
#include<iomanip>
#include<map>
using namespace std;
class Books
{
public:
	Books();
	map<string, Books>book_storage;
	void setISBN(string ISBN);
	void setTitle(string title);
	void setAuthor(string author);
	void setEditionNum(string edition);
	void setDateOfPublication(string date);
	void setValue(string value);
	void setCost(double cost, string condition);
	//void setCondition(string condition);
	void printBook();

	string getISBN();
	string getTitle();
	string getAuthor();
	string getEditionNum();
	string getDateOfPublication();
	//string getValue();
	double getNewCost();
	double getUsedCost();
	double getRentCost();
	double getElecCost();
	double getMinCost();
	double getMaxCost();
	//string getCondition();

private:
	string bookISBN;
	string bookTitle;
	string authorName;
	string editionNum;
	string dateOfPublication; //MM/YYYY
							  //string bookValue;
	double bookCost_new;
	double bookCost_used;
	double bookCost_rent;
	double bookCost_elec;
	//string bookCondition;
};
#endif 