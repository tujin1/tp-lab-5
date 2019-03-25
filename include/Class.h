#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
class Student;
class Group;
class Deanery;

class Student {
private:
	friend Group;
	friend Deanery;
	int id;
	string fio;
	Group *group;
	std::vector<int> marks;
	int num;
public:
    Student(string fio1, int id1);
	void Student::enroll(Group *group1);
	void addmark(int mark);
	int avr();
}
class Group {
private:
	friend Student;
	friend Deanery;
	string title;
	std::vector<Student*> students;
	Student *head;
	int num;
public:
	Group (string title1);
	void add_student(Student *student);
	void election();
	string search(Student *student);
	float average();
    void remove(Student *student); 
};
class Deanery {
private:
	friend Group;
	std::vector<Student*> students;
	std::vector<Group *> groups;
public:
	Deanery(string file);
	void marks(int count);
	void statistic();
	void trans(Student *student,Group *_group);
	void fire();
	void update(string name);
	void elections();
	void printinfo();
}