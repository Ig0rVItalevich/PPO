#ifndef ORDERPRESENTER_H
#define ORDERPRESENTER_H

#include "../logic/orderManager.hpp"
#include "../models/order.hpp"

#include <vector>
#include <iostream>
#include <string>

class OrderPresenter
{
private:
	OrderManager* manager;

public:
	OrderPresenter(OrderManager& manager);
	~OrderPresenter() = default;

	void addOrder();
    void deleteOrder();
    void getOrder();
    void getOrdersByUser();
};

#endif // ORDERPRESENTER_H