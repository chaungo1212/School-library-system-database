#pragma once
#include"Books.h"
#include"Section.h"
#include <string>
#include <map>
using namespace std;

class Course
{
public:
	Course();
	//~Course();
	void setCourseName(string course_name);
	void setCourseNumber(string course_num);
	//	void setCourseSection(string section);
	//	void setBookForCourse(string section, string ISBN, string require); ;
	string getCourseName();
	string getCourseNumber();
	//	string getCourseSection();
	vector<string> getAllBook_ForCourse();
	vector<string> getAllRequiredBook_ForCourse();
	vector<string> getAllOptionalBook_ForCourse();
	vector<string> getAllBook_ForSection(string sectionNum);
	//	void printAllBook_ForSection();
	void addSectionwithBook(string ISBN, string sectionNum, string required);

private:
	string courseName;
	string courseNum;
	vector<Section>sectionCourse;//section for Course

};

