#ifndef PRODUCTREPO_H
#define PRODUCTREPO_H

#include "../models/product.hpp"
#include <iostream>
#include <string>

#include <pqxx/pqxx>

class InterfaceProductRepo
{
public:
	InterfaceProductRepo(){};
	~InterfaceProductRepo() = default;

	int addProduct(std::string title,
				   std::string category,
				   std::string content,
				   int count,
				   float cost,
				   std::string image_path,
				   int grade);
	Product getProduct(int id);
	int deleteProduct(int id);
	void updateProductTitle(int id, std::string title);
	void updateProductCategory(int id, std::string category);
	void updateProductContent(int id, std::string content);
	void updateProductCount(int id, int count);
	void updateProductCost(int id, float cost);
	void updateProductGrade(int id, int grade);
	std::vector<Product> getProductsByOrder(int OrderId);
};

class ProductRepo : public InterfaceProductRepo
{
private:
	std::shared_ptr<pqxx::connection> connection;
	std::shared_ptr<pqxx::nontransaction> txn;

public:
	explicit ProductRepo()
		: connection(new pqxx::connection("postgresql://postgres:qwerty123@localhost/ppo"))
		, txn(new pqxx::nontransaction(*connection)){};
	~ProductRepo() = default;

	int addProduct(std::string title,
				   std::string category,
				   std::string content,
				   int count,
				   float cost,
				   std::string image_path,
				   int grade);
	Product getProduct(int id);
	int deleteProduct(int id);
	void updateProductTitle(int id, std::string title);
	void updateProductCategory(int id, std::string category);
	void updateProductContent(int id, std::string content);
	void updateProductCount(int id, int count);
	void updateProductCost(int id, float cost);
	void updateProductGrade(int id, int grade);
	std::vector<Product> getProductsByOrder(int OrderId);
};

#endif // PRODUCTREPO_H