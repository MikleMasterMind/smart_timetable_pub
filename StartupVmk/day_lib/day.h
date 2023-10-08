#pragma once
// day.h
#pragma once

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class day {
private:

	int workload;
	string name;
	static const int max_workload = 7;
	string lessons[max_workload];


public:

	// constructor
	// call day immediately
	day(string name);

	// counstructor
	// call day immediately
	// add lessons immediately
	day(string name, string& lessons);

	// distructor
	~day();

	// print main info
	void print();

	// print main info in file.txt
	// open file before call
	void print(ofstream& file);

	// day overload -> true
	// day have free place -> false
	bool overload();

	// return true if day consist subject
	bool consist(string subject);

	// return amount of lessons today
	int count();

	// return amount of <subject> lessons today
	int count(string subject);

	// return k lesson
	// k = 1, 2, ...
	// ( if day consist k lessons
	string getlesson(int k);

	// add lesson to the end, set name of lesson
	// (if day overload -> do nothing
	void add_lesson(string subject);

	// add lesson ещ k place,set name of lesson, move rest down
	// (if day overload -> do nothing
	void add_lesson(string subject, int k);

	// remove all lessons
	void remove_lesson();

	// remove last lesson <subject>
	void remove_lesson(string subject);
};