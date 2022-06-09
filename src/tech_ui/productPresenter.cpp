#include "productPresenter.hpp"

ProductPresenter::ProductPresenter(ProductManager& manager)
{
	this->manager = &manager;
	LOG(DEBUG) << "Создан ProductPresenter";
}

void ProductPresenter::addApp(App* application)
{
	LOG(DEBUG) << "Вызвано addApp Presenter";
	this->application = application;
}

void ProductPresenter::addProduct()
{
	LOG(DEBUG) << "Вызвано addProduct Presenter";
	std::string title = "", category = "", content = "", image_path = "";
	int count = 0, grade = 0;
	float cost = 0;

	this->application->printer("Введите название: ");
	title = this->application->scanner();
	this->application->printer("Введите категорию: ");
	category = this->application->scanner();
	this->application->printer("Введите описание: ");
	content = this->application->scanner();
	this->application->printer("Введите количество: ");
	count = std::stoi(this->application->scanner());
	this->application->printer("Введите стоимость: ");
	cost = std::stof(this->application->scanner());

	if(manager->addProduct(title, category, content, count, cost, image_path, grade))
	{
		LOG(ERROR) << "Ошибка addProduct Presenter";
		this->application->printer("Что-то пошло не так...");
	}
	else
	{
		this->application->printer("Операция прошла успешно.");
	}
}

void ProductPresenter::deleteProduct()
{
	LOG(DEBUG) << "Вызвано deleteProduct Presenter";
	int id = 0;
	this->application->printer("Введите product_id: ");
	id = std::stoi(this->application->scanner());

	if(manager->getProduct(id).getId() == 0)
	{
		LOG(WARNING) << "Продукта с таким id не существует deleteProduct Presenter";
		this->application->printer("Продукта с таким id не существует.");
	}
	else
	{
		if(manager->deleteProduct(id))
		{
			LOG(ERROR) << "Ошибка deleteProduct Presenter";
			this->application->printer("Что-то пошло не так...");
		}
		else
		{
			this->application->printer("Операция прошла успешно.");
		}
	}
}

void ProductPresenter::getProduct()
{
	LOG(DEBUG) << "Вызвано getProduct Presenter";
	int id = 0;
	this->application->printer("Введите product_id: ");
	id = std::stoi(this->application->scanner());

	Product product = manager->getProduct(id);
	if(product.getId() == 0)
	{
		LOG(WARNING) << "Продукта с таким id не существует getProduct Presenter";
		this->application->printer("Продукта с таким id не существует.");
	}
	else
	{
		this->application->printer(product.toString());
	}
}

void ProductPresenter::getProductsByOrder()
{
	LOG(DEBUG) << "Вызвано getProductsByOrder Presenter";
	int id = 0;
	this->application->printer("Введите order_id: ");
	id = std::stoi(this->application->scanner());

	std::vector<Product> products = manager->getProductsByOrder(id);
	if(!products.size())
	{
		LOG(WARNING) << "Продукты отсутствуют getProductsByOrder Presenter";
		this->application->printer("Продукты отсутствуют.");
	}
	else
	{
		for(Product product : products)
		{
			this->application->printer(product.toString());
		}
	}
}

void ProductPresenter::getProductsByCategory()
{
	LOG(DEBUG) << "Вызвано getProductsByCategory Presenter";
	std::string category = "";
	this->application->printer("Введите категорию: ");
	category = this->application->scanner();

	std::vector<Product> products = manager->getProductsByCategory(category);
	if(!products.size())
	{
		LOG(WARNING) << "Продукты отсутствуют getProductsByCategory Presenter";
		this->application->printer("Продукты отсутствуют.");
	}
	else
	{
		for(Product product : products)
		{
			this->application->printer(product.toString());
		}
	}
}

void ProductPresenter::getAllProducts()
{
	LOG(DEBUG) << "Вызвано getAllProducts Presenter";
	std::vector<Product> products = manager->getAllProducts();
	if(!products.size())
	{
		LOG(WARNING) << "Продукты отсутствуют getAllProducts Presenter";
		this->application->printer("Продукты отсутствуют.");
	}
	else
	{
		for(Product product : products)
		{
			this->application->printer(product.toString());
		}
	}
}

void ProductPresenter::getProductsByGrade()
{
	LOG(DEBUG) << "Вызвано getProductsByGrade Presenter";
	int grade = 0;
	this->application->printer("Введите минимальную оценку продуктов: ");
	grade = std::stoi(this->application->scanner());

	std::vector<Product> products = manager->getProductsByGrade(grade);
	if(!products.size())
	{
		LOG(WARNING) << "Продукты отсутствуют getProductsByGrade Presenter";
		this->application->printer("Продукты отсутствуют.");
	}
	else
	{
		for(Product product : products)
		{
			this->application->printer(product.toString());
		}
	}
}