#include "Books.h"
#include<string>

using namespace std;
Books::Books()
{
	bookISBN = " ";
	bookTitle = " ";
	authorName = " ";
	editionNum = " ";
	dateOfPublication = " ";
	//bookValue = " ";
	authorName = " ";
	editionNum = " ";
	dateOfPublication = " ";
	bookCost_new = -1.0;  // -1.0: means the specific cost is not set yet
	bookCost_used = -1.0;
	bookCost_rent = -1.0;
	bookCost_elec = -1.0;
	//bookCondition = " ";
}

void Books::setISBN(string ISBN)
{
	this->bookISBN = ISBN;
	return;
}

void Books::setTitle(string title)
{
	this->bookTitle = title;
	return;
}

void Books::setAuthor(string author)
{
	this->authorName = author;
	return;
}

void Books::setEditionNum(string edition)
{
	this->editionNum = edition;
	return;
}

void Books::setDateOfPublication(string date)
{
	this->dateOfPublication = date;
	return;
}

void Books::setCost(double cost, string condition)
{
	if (condition.compare("N") == 0)
		this->bookCost_new = cost;
	else if (condition.compare("U") == 0)
		this->bookCost_used = cost;
	else if (condition.compare("R") == 0)
		this->bookCost_rent = cost;
	else if (condition.compare("E") == 0)
		this->bookCost_elec = cost;
	else
		cout << "There is no this certain condition of book\n";
	return;
}



void Books::printBook()
{
	cout << "ISBN: " << this->getISBN() << endl;
	cout << "Title: " << this->getTitle() << endl;
	//How can we separate in this part for characteristic since characteristic is including author editionNum and date?????????????????????
	cout << "Author: " << this->getAuthor() << endl;
	cout << "Edition Number: " << this->getEditionNum() << endl;
	cout << "Date of Publication: " << this->getDateOfPublication() << endl;
	cout << std::fixed;
	if (this->bookCost_new != -1.0)
		cout << "Cost for New Version: " << std::setprecision(2) << this->getNewCost() << endl;
	if (this->bookCost_used != -1.0)
		cout << "Cost for Used Version: " << std::setprecision(2) << this->getUsedCost() << endl;
	if (this->bookCost_rent != -1.0)
		cout << "Cost for Rent Version: " << std::setprecision(2) << this->getRentCost() << endl;
	if (this->bookCost_elec != -1.0)
		cout << "Cost for Electronic Version: " << std::setprecision(2) << this->getElecCost() << endl;
	cout << "--------------------------------------\n";
}

string Books::getISBN()
{
	return bookISBN;
}

string Books::getTitle()
{
	return bookTitle;
}

string Books::getAuthor()
{
	return authorName;
}

string Books::getEditionNum()
{
	return editionNum;
}

string Books::getDateOfPublication()
{
	return dateOfPublication;
}





double Books::getNewCost()
{
	return this->bookCost_new;
}
double Books::getUsedCost()
{
	return this->bookCost_used;
}
double Books::getRentCost()
{
	return this->bookCost_rent;
}
double Books::getElecCost()
{
	return this->bookCost_elec;
}

double Books::getMinCost()
{
	vector<double> cost_exist; // Since a book might not have all costs for 4 versions.
	if (this->bookCost_new != -1.0)
		cost_exist.push_back(bookCost_new);
	if (this->bookCost_used != -1.0)
		cost_exist.push_back(bookCost_used);
	if (this->bookCost_rent != -1.0)
		cost_exist.push_back(bookCost_rent);
	if (this->bookCost_elec != -1.0)
		cost_exist.push_back(bookCost_elec);
	// Find min cost in this vector.
	double min_cost = 10000000000; // Set a big number to update min cost.
	for (int i = 0; i < cost_exist.size(); i++) {
		if (cost_exist.at(i) <= min_cost)
			min_cost = cost_exist.at(i);
	}
	return min_cost;
}

double Books::getMaxCost()
{
	vector<double> cost_exist; // Since a book might not have all costs for 4 versions.
	if (this->bookCost_new != -1.0)
		cost_exist.push_back(bookCost_new);
	if (this->bookCost_used != -1.0)
		cost_exist.push_back(bookCost_used);
	if (this->bookCost_rent != -1.0)
		cost_exist.push_back(bookCost_rent);
	if (this->bookCost_elec != -1.0)
		cost_exist.push_back(bookCost_elec);
	// Find max cost in this vector.
	double max_cost = 0; // Set a big number to update min cost.
	for (int i = 0; i < cost_exist.size(); i++) {
		if (cost_exist.at(i) >= max_cost)
			max_cost = cost_exist.at(i);
	}
	return max_cost;
}
