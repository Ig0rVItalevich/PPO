#include "productPresenter.hpp"

ProductPresenter::ProductPresenter(ProductManager& manager)
{
	this->manager = &manager;
}

void ProductPresenter::addProduct()
{
	std::string title = "", category = "", content = "", image_path = "";
	int count = 0, grade = 0;
	float cost = 0;

	std::cout << "Введите название: ";
	std::cin >> title;
	std::cout << "Введите категорию: ";
	std::cin >> category;
	std::cout << "Введите описание: ";
	std::cin >> content;
	std::cout << "Введите количество: ";
	std::cin >> count;
	std::cout << "Введите стоимость: ";
	std::cin >> cost;

	if(manager->addProduct(title, category, content, count, cost, image_path, grade))
	{
		std::cout << "Что-то пошло не так... " << std::endl;
	}
	else
	{
		std::cout << "Операция прошла успешно." << std::endl;
	}
}

void ProductPresenter::deleteProduct()
{
	int id = 0;
	std::cout << "Введите product_id: ";
	std::cin >> id;

	if(manager->getProduct(id).getId() == 0)
	{
		std::cout << "Продукта с таким id не существует." << std::endl;
	}
	else
	{
		if(manager->deleteProduct(id))
		{
			std::cout << "Что-то пошло не так..." << std::endl;
		}
		else
		{
			std::cout << "Операция прошла успешно." << std::endl;
		}
	}
}

void ProductPresenter::getProduct()
{
	int id = 0;
	std::cout << "Введите product_id: ";
	std::cin >> id;

	Product product = manager->getProduct(id);
	if(product.getId() == 0)
	{
		std::cout << "Продукта с таким id не существует." << std::endl;
	}
	else
	{
		std::cout << product.toString() << std::endl;
	}
}

void ProductPresenter::getProductsByOrder()
{
	int id = 0;
	std::cout << "Введите order_id: ";
	std::cin >> id;

	std::vector<Product> products = manager->getProductsByOrder(id);
	if(!products.size())
	{
		std::cout << "Продукты отсутствуют." << std::endl;
	}
	else
	{
		for(Product product : products)
		{
			std::cout << product.toString() << std::endl;
		}
	}
}