
#include"Books.h"
#include"Course.h"
#include"Department.h"
#include <map>
#include<string>
#include<iostream>
#include <iomanip>      // std::setprecision
using namespace std;
class School_system
{
public:
	School_system();
	void commandParser(string input);
	void addBook_withTitle(string ISBN, string title);
	void addBook_withValue(string ISBN, string characteristic, string value);
	void addBook_withCost(string ISBN, string cost, string condition);
	void printBook_byISBN(string ISBN);
	void printAllBook();
	void printAllBook_byDate(string date);
	void addCourse(string departmentCode, string courseNum, string name);
	void addCourseWithBook(string ISBN, string departmentCode, string courseNum, string courseSection, string require);
	void printAllBook_forCourse(string departmentCode, string courseNum);
	void printAllBook_forSection(string departmentCode, string courseNum, string sectionNum);
	void printAllCourses();
	void printAllBook_byDepartment(string departmentCode);
	void printAvgMinBook_byDepartment(string department_code);
	void printAvgMaxBook_byDepartment(string department_code);
private:
	map<string, Books>book_storage; //key:ISBN
	map<string, Department>department_list; //key:Department code
											//map<string, Course>course_list;//Key:Course Number
};

