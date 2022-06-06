#ifndef REVIEW_H
#define REVIEW_H

#include <iostream>
#include <string>

class Review
{
private:
	int id;
	std::string content;
	std::string date;
	int user_id;

public:
	Review(int id, std::string content, std::string date, int user_id);
	Review();
	~Review();
	int getId();
	std::string getContent();
	std::string toString();
};

#endif // REVIEW_H