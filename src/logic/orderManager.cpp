#include "orderManager.hpp"

OrderManager::OrderManager(OrderRepo& repository)
{
	this->repository = &repository;
	LOG(DEBUG) << "Создан OrderManager";
}

int OrderManager::addOrder(std::string comment,
						   std::string status,
						   std::string date,
						   int user_id,
						   std::vector<Product> products)
{
	LOG(DEBUG) << "Вызов addOrder BusinessLogic";
	return this->repository->addOrder(comment, status, date, user_id, products);
}

Order OrderManager::getOrder(int id)
{
	LOG(DEBUG) << "Вызов getOrder BusinessLogic";
	Order order = this->repository->getOrder(id);

	return order;
}

int OrderManager::deleteOrder(int id)
{
	LOG(DEBUG) << "Вызов deleteOrder BusinessLogic";
	return this->repository->deleteOrder(id);
}

void OrderManager::updateOrderStatus(int id, std::string status)
{
	LOG(DEBUG) << "Вызов updateOrderStatus BusinessLogic";
	this->repository->updateOrderStatus(id, status);
}

void OrderManager::updateOrderProducts(int id, std::vector<Product> products)
{
	LOG(DEBUG) << "Вызов updateOrderProducts BusinessLogic";
	this->repository->updateOrderProducts(id, products);
}

std::vector<Order> OrderManager::getOrdersByUser(int userId)
{
	LOG(DEBUG) << "Вызов getOrdersByUser BusinessLogic";
	std::vector<Order> orders = this->repository->getOrdersByUser(userId);

	return orders;
}