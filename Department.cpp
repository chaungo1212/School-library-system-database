#include "Department.h"

Department::Department()
{
	string department_code;


}

void Department::setDepartmentCode(string departmentCode)
{
	this->code = departmentCode;
}

string Department::getDepartmentCode()
{
	return code;
}

void Department::addCourse(string courseNum, string courseName)
{
	bool findCourse = false;
	for (int i = 0; i < this->courses.size(); i++) {
		if (this->courses.at(i).getCourseNumber().compare(courseNum) == 0) { // Course already exists.
			findCourse = true;
			break;
		}
	}
	if (findCourse == false) {
		Course* course = new Course();
		course->setCourseName(courseName);
		course->setCourseNumber(courseNum);
		this->courses.push_back(*course);
	}
}

void Department::addCoursewithBookinSection(string ISBN, string courseNum, string sectionNum, string required)
{
	bool findCourse = false;
	for (int i = 0; i < this->courses.size(); i++) {
		if (this->courses.at(i).getCourseNumber().compare(courseNum) == 0) { // Course already exists.
			findCourse = true;
			// Set book for section.
			// Check section.
			this->courses.at(i).addSectionwithBook(ISBN, sectionNum, required);
			break;
		}
	}
	if (findCourse == false) { // New course => New section and new ISBN for the section)
		Course* course = new Course();
		course->setCourseNumber(courseNum);
		course->addSectionwithBook(ISBN, sectionNum, required);
		this->courses.push_back(*course);
	}
}

bool Department::findCourse(string courseNum)
{
	for (int i = 0; i < this->courses.size(); i++) {
		if (this->courses.at(i).getCourseNumber().compare(courseNum) == 0) {
			return true;
		}
	}
	return false;
}

Course* Department::getCourse(string courseNum)
{
	for (int i = 0; i < this->courses.size(); i++) {
		if (this->courses.at(i).getCourseNumber().compare(courseNum) == 0) {
			return &this->courses.at(i);
		}
	}
	return NULL;
}

void Department::printAllCourses() {
	for (int i = 0; i < this->courses.size(); i++) {
		cout << this->code << " " << this->courses.at(i).getCourseNumber() << " " << this->courses.at(i).getCourseName() << endl;
	}
}

vector<string> Department::getAllBooksISBN()
{
	vector<string> allISBN_department;
	for (int i = 0; i < this->courses.size(); i++) {
		for (int j = 0; j < this->courses.at(i).getAllBook_ForCourse().size(); j++) {
			allISBN_department.push_back(this->courses.at(i).getAllBook_ForCourse().at(j));
		}
		//allISBN_department.insert(allISBN_department.end(), this->courses.at(i).getAllBook_ForCourse().begin(), this->courses.at(i).getAllBook_ForCourse().end());
	}

	return allISBN_department;

}

vector<string> Department::getAllRequiredBooksISBN()
{
	vector<string> allISBN_forRequired;
	for (int i = 0; i < this->courses.size(); i++) {
		for (int j = 0; j < this->courses.at(i).getAllRequiredBook_ForCourse().size(); j++) {
			allISBN_forRequired.push_back(this->courses.at(i).getAllRequiredBook_ForCourse().at(j));
		}
		//allISBN_forRequired.insert(allISBN_forRequired.end(), this->courses.at(i).getAllRequiredBook_ForCourse().begin(), this->courses.at(i).getAllRequiredBook_ForCourse().end());
	}
	return allISBN_forRequired;
}

vector<string> Department::getAllOptionalBooksISBN()
{
	vector<string> allISBN_forOptional;
	for (int i = 0; i < this->courses.size(); i++) {
		for (int j = 0; j < this->courses.at(i).getAllOptionalBook_ForCourse().size(); j++) {
			allISBN_forOptional.push_back(this->courses.at(i).getAllOptionalBook_ForCourse().at(j));
		}
		//allISBN_forOptional.insert(allISBN_forOptional.end(), this->courses.at(i).getAllOptionalBook_ForCourse().begin(), this->courses.at(i).getAllOptionalBook_ForCourse().end());
	}
	return allISBN_forOptional;
}




