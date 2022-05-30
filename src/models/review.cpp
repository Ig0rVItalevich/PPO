#include "review.hpp"

Review::Review(int id, std::string content, std::string date, int user_id)
{
	this->id = id;
    this->content = content;
    this->date = date;
    this->user_id = user_id;
}

Review::Review()
{
    this->id = 0;
    this->content = "";
    this->date = "";
    this->user_id = 0;
}

Review::~Review() { }

int Review::getId()
{
    return this->id;
}

std::string Review::getContent()
{
    return this->content;
}