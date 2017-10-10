#include "School_system.h"
#include"Books.h"
#include<string>
#include<map>


School_system::School_system()
{
	map<string, Books>book_storage;
	string ISBN = " ";
	string title = " ";
	string characteristic = " ";
	string value = " ";
}

void School_system::commandParser(string input)
{
	int first_space = input.find(" ");
	string cmd = input.substr(0, first_space);
	if (cmd.compare("B") == 0) { // 0 means cmd and "B" are equal
								 // Since the cmd is B,
								 // you are going to call the addBookbyISBN(string ISBN, string title).
								 // Hence, you need string ISBN and string title
		string ISBN; // It is the substring between first whitespace and second whitespace
		string ISBN_title = input.substr(first_space + 1); // the string containing ISBN and title start after 1st_space_index till the end
														   // if use only one index in substring, that index is the first index till the end of string			
														   // ISBN_title = "123456789 name_of_book"

		int second_space = ISBN_title.find(" "); // Now 1st_space_index = 9
		ISBN = ISBN_title.substr(0, second_space);
		string title = ISBN_title.substr(second_space + 1);
		this->addBook_withTitle(ISBN, title);
		//cout << cmd <<"-" << ISBN<<"-" << title << endl;
	}
	else if (cmd.compare("D") == 0) {
		string ISBN; // It is the substring between first whitespace and second whitespace
		string ISBN_character_value = input.substr(first_space + 1); //ISBN_characteristic="123456789 characteristic value
		int second_space = ISBN_character_value.find(" "); //find second space after ISBN
		ISBN = ISBN_character_value.substr(0, second_space);
		string characteristic_value = ISBN_character_value.substr(second_space + 1);//characteristic _value= A|E|D value
		int third_space = characteristic_value.find(" ");
		string letter = characteristic_value.substr(0, third_space);
		//check to see if the letter of characteristic is A or E or D then the value for each
		if (letter.compare("A") == 0) {
			string author = characteristic_value.substr(third_space + 1);
			this->addBook_withValue(ISBN, letter, author);
			//cout << cmd<<"-" << ISBN<<"-" << letter<<"-" <<author << endl;
		}
		else if (letter.compare("E") == 0) {
			string edition = characteristic_value.substr(third_space + 1);
			this->addBook_withValue(ISBN, letter, edition);
			//cout << cmd <<"-"<< ISBN<<"-" << letter<<"-" << edition << endl;
		}
		else if (letter.compare("D") == 0) {
			string date = characteristic_value.substr(third_space + 1);
			this->addBook_withValue(ISBN, letter, date);
			//cout << cmd <<"-"<< ISBN<<"-" << letter<<"-" << date << endl;
		}
	}
	else if (cmd.compare("M") == 0) {
		string ISBN; // It is the substring between first whitespace and second whitespace
		string ISBN_cost_condition = input.substr(first_space + 1);//= 1234567890123 39.99 condition
		int second_space = ISBN_cost_condition.find(" "); //find second space after ISBN
		ISBN = ISBN_cost_condition.substr(0, second_space);

		string cost_condition = ISBN_cost_condition.substr(second_space + 1);//cost_condition= 39.99 N|U|R|E
		int third_space = cost_condition.find(" ");
		string cost = cost_condition.substr(0, third_space);
		string condition = cost_condition.substr(third_space + 1);
		//cout << cmd << "-" << ISBN << "-" << cost << "-" << condition << endl;
		this->addBook_withCost(ISBN, cost, condition);
	}
	else if (cmd.compare("C") == 0) {
		string department_code;
		string department_courseNum_name = input.substr(first_space + 1);//department_code courseNum courseName
		int second_space = department_courseNum_name.find(" ");
		department_code = department_courseNum_name.substr(0, second_space);
		string courseNum_name = department_courseNum_name.substr(second_space + 1);//courseNum courseName
		int third_space = courseNum_name.find(" ");
		string courseNum = courseNum_name.substr(0, third_space);
		string name = courseNum_name.substr(third_space + 1);
		this->addCourse(department_code, courseNum, name);
		//cout << cmd << "-" << department_code << "-" << courseNum << "-" << name << endl;
	}
	else if (cmd.compare("A") == 0) {
		//A <ISBN> <Department Code> <Course Number> <Section Number> <R | O>
		string ISBN_department_course_sec_RO = input.substr(first_space + 1);//ISBN department courseNum courseSection RO
		int second_space = ISBN_department_course_sec_RO.find(" "); // 
		string ISBN = ISBN_department_course_sec_RO.substr(0, second_space);
		string department_course_sec_RO = ISBN_department_course_sec_RO.substr(second_space + 1);//department courseNum courseSection RO
		int third_space = department_course_sec_RO.find(" ");
		string department_code = department_course_sec_RO.substr(0, third_space);
		string course_sec_RO = department_course_sec_RO.substr(third_space + 1);//courseNum courseSection R
		int fourth_space = course_sec_RO.find(" ");
		string courseNum = course_sec_RO.substr(0, fourth_space);
		string sec_RO = course_sec_RO.substr(fourth_space + 1);//courseSection RO
		int fifth_space = sec_RO.find(" ");
		string secNum = sec_RO.substr(0, fifth_space);
		string require = sec_RO.substr(fifth_space + 1);
		this->addCourseWithBook(ISBN, department_code, courseNum, secNum, require);
		//cout << cmd << "-" << ISBN << "-" << department_code << "-" << courseNum << "-" << secNum << "-" << require << endl;
	}
	else if (cmd.compare("GC") == 0) {
		// GC <Department Code> <Course Number>
		// -Print the books required and optional for all sections of a given course
		cout << "==========================================================\n";
		cout << "A list of books for a give course:\n";
		cout << "==========================================================\n";
		string department_course = input.substr(first_space + 1);
		int second_space = department_course.find(" "); // Now 1st_space_index = 9
		string department_code = department_course.substr(0, second_space);
		string course = department_course.substr(second_space + 1);
		this->printAllBook_forCourse(department_code, course);
		//cout << department_code << "-" << course << "-" << endl;

	}
	else if (cmd.compare("GS") == 0) {
		//	GS <Department Code> <Course Number> <Section Number>
		//	-Print the books required and optional for a given section of a course
		cout << "==========================================================\n";
		cout << "A list of books for a given section:\n";
		cout << "==========================================================\n";
		string department_course = input.substr(first_space + 1); // the string containing ISBN and title start after 1st_space_index till the end
		int second_space = department_course.find(" "); // Now 1st_space_index = 9
		string department_code = department_course.substr(0, second_space);
		string course_section = department_course.substr(second_space + 1);
		int third_space = course_section.find(" ");
		string course = course_section.substr(0, third_space);
		string section = course_section.substr(third_space + 1);
		this->printAllBook_forSection(department_code, course, section);
	}
	else if (cmd.compare("GB") == 0) {
		cout << "==========================================================\n";
		string ISBN = input.substr(first_space);
		cout << "Book with ISBN:" << ISBN << "'s information:\n";
		cout << "==========================================================\n";
		this->printBook_byISBN(ISBN);
		//	cout << cmd << " " << ISBN << endl;
	}
	else if (cmd.compare("PB") == 0) {
		cout << "==========================================================\n";
		cout << "All books' information in our system:\n";
		cout << "==========================================================\n";
		this->printAllBook();
		//	cout << cmd ;
	}
	else if (cmd.compare("PC") == 0) {
		cout << "==========================================================\n";
		cout << "All courses' information in our system:\n";
		cout << "==========================================================\n";
		//	cout << cmd << endl;
		this->printAllCourses();
	}
	else if (cmd.compare("PY") == 0) {
		string date = input.substr(first_space + 1);
		cout << "==========================================================\n";
		cout << "Books with same date:" << date << " information:\n";
		cout << "==========================================================\n";
		//	cout << cmd << endl;
		this->printAllBook_byDate(date);
		//	cout << cmd << " " << date;
	}
	else if (cmd.compare("PD") == 0) {
		//	cout << cmd << endl;
		string department_code = input.substr(first_space + 1);
		cout << "==========================================================\n";
		cout << "All books for department:" << department_code << " information:\n";
		cout << "==========================================================\n";
		this->printAllBook_byDepartment(department_code);
	}
	else if (cmd.compare("PM") == 0) {
		//	cout << cmd << endl;
		string department_code = input.substr(first_space + 1);
		cout << "==========================================================\n";
		cout << "Average minimal cost for books in department:" << department_code << ":\n";
		this->printAvgMinBook_byDepartment(department_code);
		cout << "==========================================================\n";
		cout << "Average maximal cost for books in department:" << department_code << ":\n";
		this->printAvgMaxBook_byDepartment(department_code);
	}
	else
		cout << "Command is not found!" << endl;
}


// B
void School_system::addBook_withTitle(string ISBN, string title)
{
	map<string, Books>::iterator it;
	it = this->book_storage.find(ISBN);
	if (it != this->book_storage.end()) { // The book already exists
		if (it->second.getTitle().compare(" ") == 0) // The book hasn't set the title.
			it->second.setTitle(title);
		else // The book already has its title => It means this ISBN is used. The added book cant use this ISBN. 
			cout << "This ISBN has already been used. Please define book with available ISBN\n";
	}
	else { // New book.
		Books defineBook;
		defineBook.setISBN(ISBN);
		defineBook.setTitle(title);
		this->book_storage[ISBN] = defineBook;
	}
}
// D
void School_system::addBook_withValue(string ISBN, string characteristic, string value)
{
	map<string, Books>::iterator it;
	it = this->book_storage.find(ISBN);
	if (it != this->book_storage.end()) { // The book already exists. Then we update it value with characteristics.
		if (characteristic.compare("A") == 0) {
			it->second.setAuthor(value);
		}
		if (characteristic.compare("E") == 0) {
			it->second.setEditionNum(value);
		}
		if (characteristic.compare("D") == 0) {
			it->second.setDateOfPublication(value);
		}
	}
	else { // New book.
		Books* defineBook = new Books();
		defineBook->setISBN(ISBN);
		if (characteristic.compare("A") == 0) {
			defineBook->setAuthor(value);
		}
		if (characteristic.compare("E") == 0) {
			defineBook->setEditionNum(value);
		}
		if (characteristic.compare("D") == 0) {
			defineBook->setDateOfPublication(value);
		}
		this->book_storage[ISBN] = *defineBook;
	}

}
// M
void School_system::addBook_withCost(string ISBN, string cost, string condition)
{
	map<string, Books>::iterator it;
	it = this->book_storage.find(ISBN);
	if (it != this->book_storage.end()) { // The book already exists. Then we update its cost by condition.
		it->second.setCost(stod(cost), condition);
	}
	else { // New book.
		Books* defineBook = new Books();
		defineBook->setISBN(ISBN);
		defineBook->setCost(stod(cost), condition);
		this->book_storage[ISBN] = *defineBook;
	}
}
//GB 
void School_system::printBook_byISBN(string ISBN)
{
	map<string, Books>::iterator it;
	it = this->book_storage.find(ISBN);
	if (it != this->book_storage.end())
		it->second.printBook();
	else
		cout << "This book is not in the system\n";
}
//PB
void School_system::printAllBook()
{
	map<string, Books>::iterator it;
	for (it = this->book_storage.begin(); it != this->book_storage.end(); it++) {
		it->second.printBook();
	}
}
//PY
void School_system::printAllBook_byDate(string date)
{
	map<string, Books>::iterator it;
	for (it = this->book_storage.begin(); it != this->book_storage.end(); it++) {
		string date_of_book = it->second.getDateOfPublication(); // MM/YYYY
																 //cout << date_of_book << endl;
		if (date.compare(date_of_book) == 0) { // when two dates are matched
			it->second.printBook();
		}
		else {
			int month = stoi(date.substr(0, 2));
			int year = stoi(date.substr(3, 7));
			int month_of_book = stoi(date_of_book.substr(0, 2));
			int year_of_book = stoi(date_of_book.substr(3, 7));
			if (month_of_book > month && year_of_book == year) {
				it->second.printBook();
			}
			else if (year_of_book > year) {
				it->second.printBook();
			}
		}
	}
}

void School_system::addCourse(string departmentCode, string courseNum, string name)
{
	//this->department_list  map<string, Department>
	map<string, Department>::iterator it;
	it = this->department_list.find(departmentCode);
	if (it != this->department_list.end()) { // The department is already exist. Then just update the course 
		it->second.addCourse(courseNum, name);
	}
	else { // This is a new department with adding course. Then we new department and new course.
		Department* department = new Department();
		department->setDepartmentCode(departmentCode);
		department->addCourse(courseNum, name);
		this->department_list[departmentCode] = *department;
	}

}

void School_system::addCourseWithBook(string ISBN, string departmentCode, string courseNum, string courseSection, string require)
{
	map<string, Department>::iterator it;
	it = this->department_list.find(departmentCode);
	if (it == this->department_list.end()) { // If the department is not in the system, then we new a department for the system.
		Department* department = new Department();
		department->setDepartmentCode(departmentCode);
		department->addCoursewithBookinSection(ISBN, courseNum, courseSection, require);
		this->department_list[departmentCode] = *department;
	}
	else { // It means the department is already exist.
		   // it->second : the department we want to update
		it->second.addCoursewithBookinSection(ISBN, courseNum, courseSection, require);
	}
}

void School_system::printAllBook_forCourse(string departmentCode, string courseNum)
{
	map<string, Department>::iterator it_department;
	it_department = this->department_list.find(departmentCode);
	vector<string> allISBN_ForCourse;
	if (it_department != this->department_list.end()) {
		allISBN_ForCourse = it_department->second.getCourse(courseNum)->getAllBook_ForCourse(); // Get all ISBN.
		cout << "Debug\n";
	}
	else {
		cout << "There is no this department code\n";
		return;
	}
	// Go to the book system to print out the information.
	map<string, Books>::iterator it_book;
	for (int i = 0; i < allISBN_ForCourse.size(); i++) {
		it_book = this->book_storage.find(allISBN_ForCourse.at(i));
		if (it_book != this->book_storage.end()) {
			it_book->second.printBook();
		}
	}
	return;
}

void School_system::printAllBook_forSection(string departmentCode, string courseNum, string sectionNum)
{
	map<string, Department>::iterator it_department;
	it_department = this->department_list.find(departmentCode);
	vector<string> allISBN_ForSection;
	if (it_department != this->department_list.end())
		allISBN_ForSection = it_department->second.getCourse(courseNum)->getAllBook_ForSection(sectionNum); // Get all ISBN for specific section.
	else {
		cout << "There is no this department code\n";
		return;
	}
	// Go to the book system to print out the information.
	map<string, Books>::iterator it_book;
	if (allISBN_ForSection.size() != 0) {
		for (int i = 0; i < allISBN_ForSection.size(); i++) {
			it_book = this->book_storage.find(allISBN_ForSection.at(i));
			if (it_book != this->book_storage.end()) {
				it_book->second.printBook();
			}
		}
		return;
	}
	else {
		cout << "There is either no assigned book for section or there is no that section\n";
		return;
	}
}

void School_system::printAllCourses()
{
	map<string, Department>::iterator it;
	for (it = this->department_list.begin(); it != this->department_list.end(); it++) {
		it->second.printAllCourses();
	}
}

void School_system::printAllBook_byDepartment(string departmentCode)
{
	map<string, Department>::iterator it_department;
	it_department = this->department_list.find(departmentCode);
	vector<string> allISBN_department;
	for (int i = 0; i < it_department->second.getAllBooksISBN().size(); i++) {
		allISBN_department.push_back(it_department->second.getAllBooksISBN().at(i));
	}
	//vector<string> allISBN_department = it_department->second.getAllBooksISBN();
	map<string, Books>::iterator it_book;
	// Find each ISBN correponding to the book in the book_storage
	for (int i = 0; i < allISBN_department.size(); i++) {
		it_book = this->book_storage.find(allISBN_department.at(i));
		if (it_book != this->book_storage.end()) {
			it_book->second.printBook();
		}
		else {
			cout << "This book with ISBN: " << allISBN_department.at(i) << " does not exist in the system.\n";
		}
	}
}

void School_system::printAvgMinBook_byDepartment(string department_code)
{
	map<string, Department>::iterator it_department;
	it_department = this->department_list.find(department_code);
	if (it_department != this->department_list.end()) {
		vector<string> allISBN_forDepartment;
		for (int j = 0; j < it_department->second.getAllRequiredBooksISBN().size(); j++) {
			allISBN_forDepartment.push_back(it_department->second.getAllRequiredBooksISBN().at(j));
		}
		//vector<string> allISBN_forDepartment = it_department->second.getAllRequiredBooksISBN(); // Only see required books
		// Go to book_storeage get each book corresponding to ISBN in the vector.
		map<string, Books>::iterator it_book;
		double min = 0.0;
		double amount_of_books = 0;
		for (int i = 0; i < allISBN_forDepartment.size(); i++) {
			it_book = this->book_storage.find(allISBN_forDepartment.at(i));
			if (it_book != this->book_storage.end()) {
				min = min + it_book->second.getMinCost();
				amount_of_books++;
			}
		}

		min = min / amount_of_books;
		cout << std::fixed;
		cout << "The average minimal cost of all books in " << department_code << " Department is " << std::setprecision(2) << min << endl;
	}
	else {
		cout << "There is no such department in our system to get average minimal cost of all books.\n";
	}
}

void School_system::printAvgMaxBook_byDepartment(string department_code)
{
	map<string, Department>::iterator it_department;
	it_department = this->department_list.find(department_code);
	if (it_department != this->department_list.end()) {
		// See both required and optional books for department.
		vector<string> allISBN_forDepartment;
		for (int j = 0; j < it_department->second.getAllRequiredBooksISBN().size(); j++) {
			allISBN_forDepartment.push_back(it_department->second.getAllRequiredBooksISBN().at(j));
		}
		for (int j = 0; j < it_department->second.getAllOptionalBooksISBN().size(); j++) {
			allISBN_forDepartment.push_back(it_department->second.getAllOptionalBooksISBN().at(j));
		}
		//vector<string> allISBN_forDepartment = it_department->second.getAllRequiredBooksISBN();
		//allISBN_forDepartment.insert(allISBN_forDepartment.end(), it_department->second.getAllOptionalBooksISBN().begin(), it_department->second.getAllOptionalBooksISBN().end());
		// Go to book_storeage get each book corresponding to ISBN in the vector.
		map<string, Books>::iterator it_book;
		double max = 0.0;
		double amount_of_books = 0;
		for (int i = 0; i < allISBN_forDepartment.size(); i++) {
			it_book = this->book_storage.find(allISBN_forDepartment.at(i));
			if (it_book != this->book_storage.end()) {
				max = max + it_book->second.getMaxCost();
				amount_of_books++;
			}
		}
		max = max / amount_of_books;
		cout << std::fixed;
		cout << "The average maximum cost of all books in " << department_code << " Department is " << std::setprecision(2) << max << endl;
	}
	else {
		cout << "There is no such department in our system to get average maximum cost of all books.\n";
	}
}


