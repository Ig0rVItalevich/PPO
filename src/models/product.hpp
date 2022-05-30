#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

class Product
{
private:
	int id;
	std::string title;
	std::string category;
	std::string content;
	int count;
	float cost;
	std::string image_path;
	int grade;

public:
	Product(int id,
			std::string title,
			std::string category,
			std::string content,
			int count,
			float cost,
			std::string image_path,
			int grade);
	Product();
	~Product();
	int getId();
	std::string getTitle();
};

#endif // PRODUCT_H