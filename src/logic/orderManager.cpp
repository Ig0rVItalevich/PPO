#include "orderManager.hpp"

OrderManager::OrderManager(OrderRepo &repository)
{
	this->repository = &repository;
}

int OrderManager::addOrder(std::string comment,
							std::string status,
							std::string date,
							int user_id,
							std::vector<Product> products)
{
	return this->repository->addOrder(comment, status, date, user_id, products);
}

Order OrderManager::getOrder(int id)
{
	Order order = this->repository->getOrder(id);

	return order;
}

void OrderManager::deleteOrder(int id)
{
	this->repository->deleteOrder(id);
}

void OrderManager::updateOrderStatus(int id, std::string status)
{
	this->repository->updateOrderStatus(id, status);
}

void OrderManager::updateOrderProducts(int id, std::vector<Product> products)
{
	this->repository->updateOrderProducts(id, products);
}

std::vector<Order> OrderManager::getOrdersByUser(int userId)
{
	std::vector<Order> orders = this->repository->getOrdersByUser(userId);

	return orders;
}