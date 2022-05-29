#ifndef PRODUCTREPO_H
#define PRODUCTREPO_H

#include "../models/product.hpp"
#include <iostream>
#include <string>

class InterfaceProductRepo
{
public:
	InterfaceProductRepo();
	~InterfaceProductRepo() = default;

	void addProduct(std::string title,
					std::string category,
					std::string content,
					int count,
					float cost,
					std::string image_path,
					int grade);
	Product getProduct(int id);
	void deleteProduct(int id);
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
	std::shared_ptr<pqxx::work> txn;

public:
	explicit ProductRepo()
		: connection(new pqxx::connection("postgresql://postgres:qwerty123@localhost/ppo"))
		, txn(new pqxx::work(*connection)){};
	~ProductRepo() = default;

	void addProduct(std::string title,
					std::string category,
					std::string content,
					int count,
					float cost,
					std::string image_path,
					int grade) override;
	Product getProduct(int id) override;
	void deleteProduct(int id) override;
	void updateProductTitle(int id, std::string title) override;
	void updateProductCategory(int id, std::string category) override;
	void updateProductContent(int id, std::string content) override;
	void updateProductCount(int id, int count) override;
	void updateProductCost(int id, float cost) override;
	void updateProductGrade(int id, int grade) override;
	std::vector<Product> getProductsByOrder(int OrderId) override;
};

#endif // PRODUCTREPO_H