// day.h
#pragma once

#include<iostream>
#include<string>

namespace tday {

	class day {
	private:

		static const int num_lessons = 7;
		int workload;
		std::string lessons[num_lessons];
		std::string name;

	public:

		// constructor
		// call day immediately
		day(std::string name);

		// counstructor
		// call day immediately
		// add lessons immediately
		day(std::string name, std::string& lessons);

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
		bool consist(std::string subject);

		// return amount of lessons today
		int count();

		// return amount of <subject> lessons today
		int count(std::string subject);

		// return k lesson
		// k = 1, 2, ...
		// ( if day consist k lessons
		std::string getlesson(int k);

		// add lesson to the end, set name of lesson
		// (if day overload -> do nothing
		void add_lesson(std::string subject);

		// add lesson �� k place,set name of lesson, move rest down
		// (if day overload -> do nothing
		void add_lesson(std::string subject, int k);

		// remove all lessons
		void remove_lesson();

		// remove last lesson <subject>
		void remove_lesson(std::string subject);
	};
}