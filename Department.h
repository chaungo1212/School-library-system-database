#include"Books.h"
#include"Course.h"
#include<vector>
#include<string>
class Department
{
public:
	Department();
	//~Department();
	void setDepartmentCode(string departmentCode);
	string getDepartmentCode();
	void addCourse(string courseNum, string courseName);
	void addCoursewithBookinSection(string ISBN, string courseNum, string sectionNum, string required);
	bool findCourse(string courseNum); // find whether it is inside the department list.
	Course* getCourse(string courseNum); // get the course from the list.
	void printAllCourses(); //print course for department
	vector<string> getAllBooksISBN(); //get all ISBN of assigned books for department
	vector<string> getAllRequiredBooksISBN();
	vector<string> getAllOptionalBooksISBN();
private:
	string code;
	vector<Course>courses;
};

