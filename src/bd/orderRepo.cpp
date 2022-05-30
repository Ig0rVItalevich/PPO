#include "orderRepo.hpp"

int OrderRepo::addOrder(std::string comment,
						std::string status,
						std::string date,
						int user_id,
						std::vector<Product> products)
{
	txn->exec("INSERT INTO orders (order_date, status, comment, user_id) \
              VALUES (" +
			  txn->quote(date) + ", " + txn->quote(status) + ", " + txn->quote(comment) + ", " +
			  txn->quote(user_id) + ");");

	int id = 0;
	pqxx::result res{txn->exec("SELECT max(order_id) FROM orders;")};
	for(auto row : res)
	{
		id = row[0].as<int>();
	}

	for(Product tmp : products)
	{
		txn->exec("INSERT INTO orders_products (order_id, product_id) \
              VALUES (" +
				  txn->quote(id) + ", " + txn->quote(tmp.getId()) + ");");
	}

	return 0;
}

Order OrderRepo::getOrder(int id)
{
	Order order = Order();
	pqxx::result res{
		txn->exec("SELECT order_date, status, comment, user_id FROM orders WHERE order_id = " +
				  txn->quote(id) + ";")};

	for(auto row : res)
	{
		order = Order(id,
					  row[2].as<std::string>(),
					  row[1].as<std::string>(),
					  row[0].as<std::string>(),
					  row[3].as<int>());
	}

	return order;
}

void OrderRepo::deleteOrder(int id)
{
	txn->exec("DELETE FROM orders WHERE order_id = " + txn->quote(id) + ";");
}

void OrderRepo::updateOrderStatus(int id, std::string status)
{
	txn->exec("UPDATE orders SET status  = " + txn->quote(status) +
			  "WHERE order_id = " + txn->quote(id) + ";");
}

void OrderRepo::updateOrderProducts(int id, std::vector<Product> products)
{
	txn->exec("DELETE FROM orders_products WHERE order_id = " + txn->quote(id) + ";");

	for(Product tmp : products)
	{
		txn->exec("INSERT INTO orders_products (order_id, product_id) \
              VALUES (" +
				  txn->quote(id) + ", " + txn->quote(tmp.getId()) + ");");
	}
}

std::vector<Order> OrderRepo::getOrdersByUser(int userId)
{
	std::vector<Order> orders;
	pqxx::result res{txn->exec(
		"SELECT order_id, order_date, status, comment, user_id FROM orders WHERE user_id = " +
		txn->quote(userId) + ";")};

	for(auto row : res)
	{
		Order order = Order(row[0].as<int>(),
							row[3].as<std::string>(),
							row[2].as<std::string>(),
							row[1].as<std::string>(),
							row[4].as<int>());
		orders.push_back(order);
	}

	return orders;
}