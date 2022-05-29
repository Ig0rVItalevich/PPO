#include "product.hpp"

Product::Product(int id,
			   std::string title,
			   std::string category,
			   std::string content,
			   int count,
			   float cost,
			   std::string image_path,
			   int grade)
{
	this->id = id;
	this->title = title;
    this->category = category;
    this->content = content;
    this->count = count;
    this->cost = cost;
    this->image_path = image_path;
    this->grade = grade;
}

Product::Product()
{
    this->id = 0;
	this->title = "";
    this->category = "";
    this->content = "";
    this->count = 0;
    this->cost = 0;
    this->image_path = "";
    this->grade = 0;
}

Product::~Product() { }