#ifndef PRODUCTPRESENTER_H
#define PRODUCTPRESENTER_H

#include "../logging/easylogging++.h"
#include "../logic/productManager.hpp"
#include "../models/product.hpp"
#include "app.hpp"

#include <iostream>
#include <string>
#include <vector>

class App;

class ProductPresenter
{
private:
	ProductManager* manager;
	App* application;

public:
	ProductPresenter(ProductManager& manager);
	~ProductPresenter() = default;

	void addApp(App* application);

	void addProduct();
	void deleteProduct();
	void getProduct();
	void getProductsByOrder();
	void getProductsByCategory();
	void getAllProducts();
	void getProductsByGrade();
};

#endif // PRODUCTPRESENTER_H