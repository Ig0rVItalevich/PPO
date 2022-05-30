#include "productManager.hpp"

ProductManager::ProductManager(ProductRepo& repository)
{
	this->repository = &repository;
}

int ProductManager::addProduct(std::string title,
							   std::string category,
							   std::string content,
							   int count,
							   float cost,
							   std::string image_path,
							   int grade)
{
	return this->repository->addProduct(title, category, content, count, cost, image_path, grade);
}

Product ProductManager::getProduct(int id)
{
	Product product = this->repository->getProduct(id);

	return product;
}

void ProductManager::deleteProduct(int id)
{
	this->repository->deleteProduct(id);
}

void ProductManager::updateProductTitle(int id, std::string title)
{
	this->repository->updateProductTitle(id, title);
}

void ProductManager::updateProductCategory(int id, std::string category)
{
	this->repository->updateProductCategory(id, category);
}

void ProductManager::updateProductContent(int id, std::string content)
{
	this->repository->updateProductContent(id, content);
}

void ProductManager::updateProductCount(int id, int count)
{
	this->repository->updateProductCount(id, count);
}

void ProductManager::updateProductCost(int id, float cost)
{
	this->repository->updateProductCost(id, cost);
}

void ProductManager::updateProductGrade(int id, int grade)
{
	if(grade == 100000)
	{
		GradeRepo gradeRepo = GradeRepo();
		std::vector<Grade> grades = gradeRepo.getGradesByProduct(id);

		int res_grade = 0;
		for(Grade grade : grades)
		{
			res_grade += grade.getValue();
		}

		this->repository->updateProductGrade(id, res_grade);
	}
	else
	{
		this->repository->updateProductGrade(id, grade);
	}
}

std::vector<Product> ProductManager::getProductsByOrder(int OrderId)
{
	std::vector<Product> products = this->repository->getProductsByOrder(OrderId);

	return products;
}