#include "Course.h"

Course::Course()
{
	this->courseName = " ";
	this->courseNum = " ";


}

void Course::setCourseName(string course_name)
{
	this->courseName = course_name;
}

void Course::setCourseNumber(string course_num)
{
	this->courseNum = course_num;
}
/*
void Course::setCourseSection(string section)
{
this->courseSec = section;
}
//still have require
void Course::setBookForCourse(string section, string ISBN, string require)
{
this->books_for_course[section] = ISBN;
}*/

string Course::getCourseName()
{
	return this->courseName;
}

string Course::getCourseNumber()
{
	return this->courseNum;
}

/*string Course::getCourseSection()
{
return this->courseSec;
}
*/
vector<string> Course::getAllBook_ForCourse()
{
	vector<string> allISBN;
	for (int i = 0; i < this->sectionCourse.size(); i++) {
		for (int j = 0; j < this->sectionCourse.at(i).getAllBook().size(); j++) {
			allISBN.push_back(this->sectionCourse.at(i).getAllBook().at(j));
		}
		//allISBN.insert(allISBN.end(), this->sectionCourse.at(i).getAllBook().begin(), this->sectionCourse.at(i).getAllBook().end());
	}
	return allISBN;
}
vector<string> Course::getAllRequiredBook_ForCourse()
{
	vector<string> allISBN_forRequired;
	for (int i = 0; i < this->sectionCourse.size(); i++) {
		for (int j = 0; j < this->sectionCourse.at(i).getAllRequiredBook().size(); j++) {
			allISBN_forRequired.push_back(this->sectionCourse.at(i).getAllRequiredBook().at(j));
		}
		//allISBN_forRequired.insert(allISBN_forRequired.end(), this->sectionCourse.at(i).getAllRequiredBook().begin(), this->sectionCourse.at(i).getAllRequiredBook().end());
	}
	return allISBN_forRequired;
}

vector<string> Course::getAllOptionalBook_ForCourse()
{
	vector<string> allISBN_forOptional;
	for (int i = 0; i < this->sectionCourse.size(); i++) {
		for (int j = 0; j < this->sectionCourse.at(i).getAllOptionalBook().size(); j++) {
			allISBN_forOptional.push_back(this->sectionCourse.at(i).getAllOptionalBook().at(j));
		}
		//allISBN_forOptional.insert(allISBN_forOptional.end(), this->sectionCourse.at(i).getAllOptionalBook().begin(), this->sectionCourse.at(i).getAllOptionalBook().end());
	}
	return allISBN_forOptional;
}

vector<string> Course::getAllBook_ForSection(string sectionNum)
{
	vector<string>allISBN_ForSection;
	for (int i = 0; i < this->sectionCourse.size(); i++) {
		if (this->sectionCourse.at(i).getSectionNum().compare(sectionNum) == 0) {
			for (int j = 0; j < this->sectionCourse.at(i).getAllBook().size(); j++) {
				//allISBN_ForSection = this->sectionCourse.at(i).getAllBook();
				allISBN_ForSection.push_back(this->sectionCourse.at(i).getAllBook().at(j));
			}

			break;
		}
	}
	return allISBN_ForSection;
}

void Course::addSectionwithBook(string ISBN, string sectionNum, string required)
{
	bool find_section = false;
	int index_section;
	for (int i = 0; i < this->sectionCourse.size(); i++) {
		if (this->sectionCourse.at(i).getSectionNum().compare(sectionNum) == 0) {
			find_section = true;
			index_section = i;

			break;
		}
	}
	if (find_section == true) { // Section already exists.
		if (required.compare("R") == 0)
			this->sectionCourse.at(index_section).addRequiredBook(ISBN);
		else
			this->sectionCourse.at(index_section).addOptionalBook(ISBN);
	}
	else { // New section.
		Section* section = new Section();
		section->setSectionNum(sectionNum);
		if (required.compare("R") == 0)
			section->addRequiredBook(ISBN);
		else
			section->addOptionalBook(ISBN);
		this->sectionCourse.push_back(*section);
	}

}

/*void Course::printAllBook_ForSection()
{
}
*/




