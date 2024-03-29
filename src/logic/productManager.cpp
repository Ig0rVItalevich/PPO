#include "productManager.hpp"

ProductManager::ProductManager(ProductRepo& repository)
{
	this->repository = &repository;
	LOG(DEBUG) << "Создан ProductManager";
}

int ProductManager::addProduct(std::string title,
							   std::string category,
							   std::string content,
							   int count,
							   float cost,
							   std::string image_path,
							   int grade)
{
	LOG(DEBUG) << "Вызов addProduct BusinessLogic";
	return this->repository->addProduct(title, category, content, count, cost, image_path, grade);
}

Product ProductManager::getProduct(int id)
{
	LOG(DEBUG) << "Вызов getProduct BusinessLogic";
	Product product = this->repository->getProduct(id);

	return product;
}

int ProductManager::deleteProduct(int id)
{
	LOG(DEBUG) << "Вызов deleteProduct BusinessLogic";
	return this->repository->deleteProduct(id);
}

void ProductManager::updateProductTitle(int id, std::string title)
{
	LOG(DEBUG) << "Вызов updateProductTitle BusinessLogic";
	this->repository->updateProductTitle(id, title);
}

void ProductManager::updateProductCategory(int id, std::string category)
{
	LOG(DEBUG) << "Вызов updateProductCategory BusinessLogic";
	this->repository->updateProductCategory(id, category);
}

void ProductManager::updateProductContent(int id, std::string content)
{
	LOG(DEBUG) << "Вызов updateProductContent BusinessLogic";
	this->repository->updateProductContent(id, content);
}

void ProductManager::updateProductCount(int id, int count)
{
	LOG(DEBUG) << "Вызов updateProductCount BusinessLogic";
	this->repository->updateProductCount(id, count);
}

void ProductManager::updateProductCost(int id, float cost)
{
	LOG(DEBUG) << "Вызов updateProductCost BusinessLogic";
	this->repository->updateProductCost(id, cost);
}

void ProductManager::updateProductGrade(int id, int grade)
{
	LOG(DEBUG) << "Вызов updateProductGrade BusinessLogic";
	if(grade == 100000)
	{
		GradeRepo gradeRepo = GradeRepo("postgresql://postgres:qwerty123@localhost/ppo");
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
	LOG(DEBUG) << "Вызов getProductsByOrder BusinessLogic";
	std::vector<Product> products = this->repository->getProductsByOrder(OrderId);

	return products;
}

std::vector<Product> ProductManager::getProductsByCategory(std::string category)
{
	LOG(DEBUG) << "Вызов getProductsByCategory BusinessLogic";
	std::vector<Product> products = this->repository->getProductsByCategory(category);

	return products;
}

std::vector<Product> ProductManager::getAllProducts()
{
	LOG(DEBUG) << "Вызов getAllProducts BusinessLogic";
	std::vector<Product> products = this->repository->getAllProducts();

	return products;
}

std::vector<Product> ProductManager::getProductsByGrade(int grade)
{
	LOG(DEBUG) << "Вызов getProductsByGrade BusinessLogic";
	std::vector<Product> products = this->repository->getProductsByGrade(grade);

	return products;
}