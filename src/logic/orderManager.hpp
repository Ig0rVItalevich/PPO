#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H

#include "../db/orderRepo.hpp"
#include "../models/order.hpp"
#include "..models/product.hpp"

#include <vector>

class OrderManager
{
private:
	OrderRepo* repository;

public:
	OrderManager(OrderRepo& repository);
	~OrderManager();

	void addOrder(std::string comment,
				  std::string status,
				  std::string date,
				  int user_id,
				  std::vector<Product> products);
	Order getOrder(int id);
	void deleteOrder(int id);
	void updateOrderStatus(int id, std::string status);
	void updateOrderProducts(int id, std::vector<Product> products);
	std::vector<Order> getOrdersByUser(int userId);
};

#endif // ORDERMANAGER_H