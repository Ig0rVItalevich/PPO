#include "review.hpp"

Review::Review(int id, std::string content, std::string date, int user_id, int product_id)
{
	this->id = id;
    this->content = content;
    this->date = date;
    this->user_id = user_id;
    this->product_id = product_id;
}

Review::Review()
{
    this->id = 0;
    this->content = "";
    this->date = "";
    this->user_id = 0;
    this->product_id = 0;
}

Review::~Review() { }