#ifndef ORDERREPO_H
#define ORDERREPO_H

#include "../logging/easylogging++.h"
#include "../models/order.hpp"
#include "../models/product.hpp"
#include <iostream>
#include <string>

#include <pqxx/pqxx>

class InterfaceOrderRepo
{
public:
	InterfaceOrderRepo(){};
	~InterfaceOrderRepo() = default;

	int addOrder(std::string comment,
				 std::string status,
				 std::string date,
				 int user_id,
				 std::vector<Product> products);
	Order getOrder(int id);
	int deleteOrder(int id);
	void updateOrderStatus(int id, std::string status);
	void updateOrderProducts(int id, std::vector<Product> products);
	std::vector<Order> getOrdersByUser(int userId);
};

class OrderRepo : public InterfaceOrderRepo
{
private:
	std::shared_ptr<pqxx::connection> connection;
	std::shared_ptr<pqxx::nontransaction> txn;

public:
	explicit OrderRepo(std::string bd_str)
		: connection(new pqxx::connection(bd_str))
		, txn(new pqxx::nontransaction(*connection)){};
	~OrderRepo() = default;

	int addOrder(std::string comment,
				 std::string status,
				 std::string date,
				 int user_id,
				 std::vector<Product> products);
	Order getOrder(int id);
	int deleteOrder(int id);
	void updateOrderStatus(int id, std::string status);
	void updateOrderProducts(int id, std::vector<Product> products);
	std::vector<Order> getOrdersByUser(int userId);
};

#endif // ORDERREPO_H