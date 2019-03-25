#include "Class.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
Student(string fio1, int id1) {
		id = id1;
		fio = fio1;
	}
	void Student::enroll(Group *group1){
		this->group = group1;
		

	}
	void addmark(int mark) {
		marks.push_back(mark);
		num++;
	}
	int avr() {
		float k=0;
		for (int i = 0; i < num; i++) {
		    k =k+marks[i];
			
		};
		return(k / num);
	
	}
	Group (string title1) {
		this->title = title1;
	};
	void add_student(Student *student) {
		student->group = this;
		this->students.push_back(student);
		num++;
	};
	void election() {
		
			this->head = students[rand() % num];
		
	}
	string search(Student *student) {
		for (int i = 0; i < num; i++) {
			if (student == students[i]) {
				return("Yes");
			}
		}
		return("No");
	}
	float average() {
		float k=0;
		for (int i = 0; i < num; i++) {
			k =k+students[i]->avr();
		}
		return (k/num);
	}
	void remove(Student *student) {
		
		if (student->group==this){
			for (int i = 0; i < num; i++) {
				if (student->id == students[i]->id) {
					students.erase(students.begin() + i);
					num = num - 1;
					if (student == this->head)
					{
						this->election();
					}
				}
			} 
		}
	}
	Deanery(string file) {

		int pos;
		ifstream F;
		F.open(file);
		if (!F.is_open()) {
			cout << "Ne chitaet";
		}
		int id = 0;
		string s;
		Group  *group = NULL;
		while (getline(F, s)) { 
			if (s.find("Group") !=-1) {
				
				pos = s.find("Group");
				group = new Group(s.substr(0, pos - 1));
				this->groups.push_back(group);
			}
			else
			{
			
				Student *student = new Student(s,id);
				this->students.push_back(student);
				group->add_student(student);
				id++;
			}
		};
     };
	
	void marks(int count) {
	for (int j=0;j<count;j++){
		for (unsigned int i = 0; i < students.size(); i++) {
			students[i]->addmark(rand() % 5 + 1);
		}
		}
	}
	void statistic() {
		for (int i = 0; i < groups.size(); i++) {
			for (int j = 0; j < groups[i]->num; j++) {
				cout <<"Score: "<< groups[i]->students[j]->avr() <<" Name: "<< groups[i]->students[j]->fio<<endl;
			}
			cout << "Groupe Score: " << groups[i]->average()<<endl;
		}
	}
	void trans(Student *student,Group *_group) {
		student->group->remove(student);
		student->group = _group;

	}
	void fire() {
		for (unsigned int i = 0; i < students.size(); i++) {
			if (students[i]->avr() < 2) {
				students.erase(students.begin() + i);
				students[i]->group->remove(students[i]);
			}
				}
	}
	void update(string name) {
		ofstream file;
		file.open(name);

		if (file.is_open())
		{
			for (int i = 0; i < groups.size(); i++) {
				file << i+1<<": " << groups[i]->title << " " << groups[i]->num << " | " << " Average ball " << groups[i]->average() << endl;
				file << "Head: " << groups[i]->head->fio << endl;
				for (int j = 0; j < groups[i]->students.size(); j++) {
					file << groups[i]->students[j]->fio << "-" << groups[i]->students[j]->avr() << "   ";
					for (int h = 0; h < groups[i]->students[j]->marks.size(); h++) {
						file << groups[i]->students[j]->marks[h] << " ";
					}
					file << endl;
				}
				file << endl;
			}
		}file.close();
	}
	void elections() {
		for (int i = 0; i < groups.size(); i++) {
			groups[i]->election();
		}
	}
	void printinfo() {
		cout << "Number students is  " << students.size() << endl;

		for (int i = 0; i < groups.size(); i++) {
			cout << i + 1 << ": "<<groups[i]->title << " " << groups[i]->num << " | " << " Average ball " << groups[i]->average() << endl;
			cout << "Head: " << groups[i]->head->fio << endl;
			for (int j = 0; j < groups[i]->students.size(); j++) {
				cout << groups[i]->students[j]->fio << ":" << groups[i]->students[j]->avr() << "    ";
				for (int h = 0; h < groups[i]->students[j]->marks.size(); h++) {
					cout << groups[i]->students[j]->marks[h] << " ";
				}
				cout << endl;
			}
			cout << endl;
		}

	}