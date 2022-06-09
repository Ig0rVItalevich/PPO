#ifndef ORDERPRESENTER_H
#define ORDERPRESENTER_H

#include "../logging/easylogging++.h"
#include "../logic/orderManager.hpp"
#include "../models/order.hpp"
#include "app.hpp"

#include <vector>
#include <iostream>
#include <string>

class App;

class OrderPresenter
{
private:
	OrderManager* manager;
	App* application;

public:
	OrderPresenter(OrderManager& manager);
	~OrderPresenter() = default;

	void addApp(App* application);

	void addOrder();
    void deleteOrder();
    void getOrder();
    void getOrdersByUser();
};

#endif // ORDERPRESENTER_H