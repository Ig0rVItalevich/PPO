#include "order.hpp"

Order::Order(int id, std::string comment, std::string status, std::string date, int user_id)
{
	this->id = id;
    this->comment = comment;
    this->date = date;
    this->user_id = user_id;
    this->status = status;
}

Order::Order()
{
    this->id = 0;
    this->comment = "";
    this->date = "";
    this->user_id = 0;
    this->status = "";
}

Order::~Order() { }

int Order::getId()
{
    return this->id;
}

std::string Order::getStatus()
{
    return this->status;
}