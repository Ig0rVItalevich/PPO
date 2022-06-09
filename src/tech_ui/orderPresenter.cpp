#include "orderPresenter.hpp"

OrderPresenter::OrderPresenter(OrderManager& manager)
{
	this->manager = &manager;
	LOG(DEBUG) << "Создан OrderPresenter";
}

void OrderPresenter::addApp(App* application)
{
	LOG(DEBUG) << "Вызвано addApp Presenter";
	this->application = application;
}

void OrderPresenter::addOrder()
{
	LOG(DEBUG) << "Вызвано addOrder Presenter";
	std::string comment = "", status = "", date = "2022-06-06";
	int user_id = 0;
	std::vector<Product> products = {};

	this->application->printer("Введите комментарий к заказу: ");
	comment = this->application->scanner();
	this->application->printer("Введите статус заказа: ");
	status = this->application->scanner();
	this->application->printer("Введите user_id: ");
	user_id = std::stoi(this->application->scanner());

	if(manager->addOrder(comment, status, date, user_id, products))
	{
		LOG(ERROR) << "Ошибка addOrder Presenter";
		this->application->printer("Что-то пошло не так...");
	}
	else
	{
		this->application->printer("Операция прошла успешно.");
	}
}

void OrderPresenter::deleteOrder()
{
	LOG(DEBUG) << "Вызвано deleteOrder Presenter";
	int id = 0;
	this->application->printer("Введите order_id: ");
	id = std::stoi(this->application->scanner());

	if(manager->getOrder(id).getId() == 0)
	{
		LOG(WARNING) << "Заказа с таким id не существует getOrder Presenter";
		this->application->printer("Заказа с таким id не существует.");
	}
	else
	{
		if(manager->deleteOrder(id))
		{
			LOG(ERROR) << "Ошибка deleteOrder Presenter";
			this->application->printer("Что-то пошло не так...");
		}
		else
		{
			this->application->printer("Операция прошла успешно.");
		}
	}
}

void OrderPresenter::getOrder()
{
	LOG(DEBUG) << "Вызвано getOrder Presenter";
	int id = 0;
	this->application->printer("Введите order_id: ");
	id = std::stoi(this->application->scanner());

	Order order = manager->getOrder(id);
	if(order.getId() == 0)
	{
		LOG(WARNING) << "Заказа с таким id не существует getOrder Presenter";
		this->application->printer("Заказа с таким id не существует.");
	}
	else
	{
		this->application->printer(order.toString());
	}
}

void OrderPresenter::getOrdersByUser()
{
	LOG(DEBUG) << "Вызвано getOrdersByUser Presenter";
	int id = 0;
	this->application->printer("Введите user_id: ");
	id = std::stoi(this->application->scanner());

	std::vector<Order> orders = manager->getOrdersByUser(id);
	if(!orders.size())
	{
		LOG(WARNING) << "Заказы отсутствуют getOrdersByUser Presenter";
		this->application->printer("Заказы отсутствуют.");
	}
	else
	{
		for(Order order : orders)
		{
			this->application->printer(order.toString());
		}
	}
}