#include "orderPresenter.hpp"

OrderPresenter::OrderPresenter(OrderManager& manager)
{
	this->manager = &manager;
}

void OrderPresenter::addOrder()
{
	std::string comment = "", status = "", date = "2022-06-06";
	int user_id = 0;
	std::vector<Product> products = {};

	std::cout << "Введите комментарий к заказу: ";
	std::cin >> comment;
	std::cout << "Введите статус заказа: ";
	std::cin >> status;
	std::cout << "Введите user_id: ";
	std::cin >> user_id;

	if(manager->addOrder(comment, status, date, user_id, products))
	{
		std::cout << "Что-то пошло не так..." << std::endl;
	}
	else
	{
		std::cout << "Операция прошла успешно." << std::endl;
	}
}

void OrderPresenter::deleteOrder()
{
	int id = 0;
	std::cout << "Введите order_id: ";
	std::cin >> id;

	if(manager->getOrder(id).getId() == 0)
	{
		std::cout << "Заказа с таким id не существует." << std::endl;
	}
	else
	{
		if(manager->deleteOrder(id))
		{
			std::cout << "Что-то пошло не так..." << std::endl;
		}
		else
		{
			std::cout << "Операция прошла успешно." << std::endl;
		}
	}
}

void OrderPresenter::getOrder()
{
	int id = 0;
	std::cout << "Введите order_id: ";
	std::cin >> id;

	Order order = manager->getOrder(id);
	if(order.getId() == 0)
	{
		std::cout << "Заказа с таким id не существует." << std::endl;
	}
	else
	{
		std::cout << order.toString() << std::endl;
	}
}

void OrderPresenter::getOrdersByUser()
{
	int id = 0;
	std::cout << "Введите user_id: ";
	std::cin >> id;

	std::vector<Order> orders = manager->getOrdersByUser(id);
	if(!orders.size())
	{
		std::cout << "Заказы отсутствуют." << std::endl;
	}
	else
	{
		for(Order order : orders)
		{
			std::cout << order.toString() << std::endl;
		}
	}
}