#ifndef PRODUCTMANAGER_H
#define PRODUCTMANAGER_H

#include "../db/gradeRepo.hpp"
#include "../db/productRepo.hpp"
#include "../models/product.hpp"

#include <vector>

class ProductManager
{
private:
	ProductRepo* repository;

public:
	ProductManager(ProductRepo& repository);
	~ProductManager();

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
	void updateProductGrade(int id, int grade = 10 * *5);
	std::vector<Product> getProductsByOrder(int OrderId);
};

#endif // PRODUCTMANAGER_H