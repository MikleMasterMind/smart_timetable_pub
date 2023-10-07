// MyLib.cpp

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class day {
private:

	// max amount of lessons today
	static const int num_lessons = 7;

	// counter of added lessons
	int workload;

	// subjects
	string lessons[num_lessons];

	// monday, tuesday, wednesday, thursday, friday, saturday
	string name;

public:

	// constructor
	// call day immediately
	day(string name) {

		this->name = name;

		this->workload = 0;
	}

	// counstructor
	// call day immediately
	// add lessons immediately
	day(string name, string& lessons) {

		this->name = name;

		// check size 
		if (lessons.size() > num_lessons) {
			cout << "Error: add too many lessons";
			return;
		}

		// add lessons
		int i;
		for (i = 0; i < lessons.size(); i++) {
			this->lessons[i] = lessons[i];
		}
		workload = i;

	}

	// distructor
	~day() {

	}

	// print main info
	void print() {
		cout << name << endl;
		for (int i = 0; i < num_lessons; i++) {
			cout << "\t" << lessons[i] << endl;
		}
	}

	// print main info in file.txt
	// open file before call
	void print(ofstream& file) {
		file << name << endl;
		for (int i = 0; i < num_lessons; i++) {
			file << "\t" << lessons[i] << endl;
		}
	}

	// day overload -> true
	// day have free place -> false
	bool overload() {
		return ((workload + 1) == num_lessons);
	}

	// return true if day consist subject
	// else -> false
	bool consist(string subject) {
		for (int i = 0; i < workload; i++) {
			bool consist = this->lessons[i] == subject;
			if (consist) {
				return true;
			}
		}
		return false;
	}

	// return amount of lessons today
	int count() {
		return this->workload;
	}

	// return amount of <subject> lessons today
	int count(string subject) {
		int count = 0;
		for (int i = 0; i < num_lessons; i++) {
			bool found = this->lessons[i] == subject;
			if (found) {
				count++;
			}
		}
		return count;
	}

	// return k lesson
	// k = 1, 2, ...
	// ( if day consist k lessons
	string getlesson(int k) {
		if (k < workload) {
			return lessons[k - 1];
		}
		else {
			return "\0";
		}
	}

	// add lesson to the end, set name of lesson
	// (if day overload -> do nothing
	void add_lesson(string subject) {
		// check place
		if (!this->overload()) {

			// add user lesson
			lessons[workload] = subject;

			// increase counter
			workload++;
		}
	}

	// add lesson ещ k place,set name of lesson, move rest down
	// (if day overload -> do nothing
	void add_lesson(string subject, int k) {
		// check place
		if (this->overload())
			return;

		// move down lessons after k
		for (int i = workload + 1; i > k; i--) {
			lessons[i] = lessons[i - 1];
		}

		// add user lesson
		lessons[k] = subject;

		// increase counter
		workload++;
	}


	// remove all lessons
	void remove_lesson() {
		workload = 0;
	}

	// remove last lesson <subject>
	void remove_lesson(string subject) {
		
		// find subject
		int i;
		for (i = workload - 1; i >= 0; i--) {
			bool gotcha = this->lessons[i] == subject;
			if (gotcha) {
				break;
			}
		}

		// move up lessons after subject
		if (i > 0) {
			for (; i < workload - 1; i++) {
				this->lessons[i] = this->lessons[i + 1];
			}
			workload--;
		}
	}
};