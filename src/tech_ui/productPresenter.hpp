#ifndef PRODUCTPRESENTER_H
#define PRODUCTPRESENTER_H

#include "../logic/productManager.hpp"
#include "../models/product.hpp"

#include <vector>
#include <iostream>
#include <string>

class ProductPresenter
{
private:
	ProductManager* manager;

public:
	ProductPresenter(ProductManager& manager);
	~ProductPresenter() = default;

	void addProduct();
    void deleteProduct();
    void getProduct();
    void getProductsByOrder();
};

#endif // PRODUCTPRESENTER_H