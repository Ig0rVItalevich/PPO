#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <string>

class Order
{
private:
	int id;
	std::string comment;
	std::string status;
	std::string date;
	int user_id;

public:
	Order(int id, std::string comment, std::string status, std::string date, int user_id);
	Order();
	~Order();
	int getId();
	std::string getStatus();
	std::string toString();
};

#endif // ORDER_H