#ifndef GRADE_H
#define GRADE_H

#include <iostream>
#include <string>

class Grade
{
private:
	int id;
	int value;
	std::string date;
	int user_id;

public:
	Grade(int id, int value, std::string date, int user_id);
	Grade();
	~Grade();
	int getValue();
	int getId();
	std::string toString();
};

#endif // GRADE_H