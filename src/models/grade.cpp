#include "grade.hpp"

Grade::Grade(int id, int value, std::string date, int user_id)
{
	this->id = id;
	this->value = value;
	this->date = date;
	this->user_id = user_id;
}

Grade::Grade()
{
	this->id = 0;
	this->value = 0;
	this->date = "";
	this->user_id = 0;
}

Grade::~Grade() { }

int Grade::getValue()
{
	return this->value;
}

int Grade::getId()
{
	return this->id;
}