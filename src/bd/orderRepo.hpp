#ifndef ORDERREPO_H
#define ORDERREPO_H

#include "../models/order.hpp"
#include <iostream>
#include <string>

class InterfaceOrderRepo
{
public:
	InterfaceOrderRepo();
	~InterfaceOrderRepo() = default;

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

class OrderRepo : public InterfaceOrderRepo
{
private:
	std::shared_ptr<pqxx::connection> connection;
	std::shared_ptr<pqxx::work> txn;

public:
	explicit OrderRepo()
		: connection(new pqxx::connection("postgresql://postgres:qwerty123@localhost/ppo"))
		, txn(new pqxx::work(*connection)){};
	~OrderRepo() = default;

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

#endif // ORDERREPO_H