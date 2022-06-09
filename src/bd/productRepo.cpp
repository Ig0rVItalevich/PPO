#include "productRepo.hpp"

int ProductRepo::addProduct(std::string title,
							std::string category,
							std::string content,
							int count,
							float cost,
							std::string image_path,
							int grade)
{
	LOG(DEBUG) << "Вызов addProduct Database";
	try
	{
		txn->exec("INSERT INTO products(title, category, content, count, cost, image_path, grade) \
              VALUES (" +
				  txn->quote(title) + ", " + txn->quote(category) + ", " + txn->quote(content) +
				  ", " + txn->quote(count) + ", " + txn->quote(cost) + ", " +
				  txn->quote(image_path) + ", " + txn->quote(grade) + ");");
	}
	catch(std::exception& e)
	{
		LOG(ERROR) << "Ошибка addProduct Database" << e.what();
		return 1;
	}

	return 0;
}

Product ProductRepo::getProduct(int id)
{
	LOG(DEBUG) << "Вызов getProduct Database";
	Product product = Product();
	pqxx::result res{txn->exec("SELECT title, category, content, count, cost, image_path, grade \
							   FROM products WHERE product_id = " +
							   txn->quote(id) + ";")};

	for(auto row : res)
	{
		product = Product(id,
						  row[0].as<std::string>(),
						  row[1].as<std::string>(),
						  row[2].as<std::string>(),
						  row[3].as<int>(),
						  row[4].as<int>(),
						  row[5].as<std::string>(),
						  row[6].as<int>());
	}

	return product;
}

int ProductRepo::deleteProduct(int id)
{
	LOG(DEBUG) << "Вызов deleteProduct Database";
	try
	{
		txn->exec("DELETE FROM products WHERE product_id = " + txn->quote(id) + ";");
	}
	catch(std::exception& e)
	{
		LOG(ERROR) << "Ошибка deleteProduct Database" << e.what();
		return 1;
	}

	return 0;
}

void ProductRepo::updateProductTitle(int id, std::string title)
{
	LOG(DEBUG) << "Вызов updateProductTitle Database";
	txn->exec("UPDATE products SET title  = " + txn->quote(title) +
			  "WHERE product_id = " + txn->quote(id) + ";");
}

void ProductRepo::updateProductCategory(int id, std::string category)
{
	LOG(DEBUG) << "Вызов updateProductCategory Database";
	txn->exec("UPDATE products SET category  = " + txn->quote(category) +
			  "WHERE product_id = " + txn->quote(id) + ";");
}

void ProductRepo::updateProductContent(int id, std::string content)
{
	LOG(DEBUG) << "Вызов updateProductContent Database";
	txn->exec("UPDATE products SET content  = " + txn->quote(content) +
			  "WHERE product_id = " + txn->quote(id) + ";");
}

void ProductRepo::updateProductCount(int id, int count)
{
	LOG(DEBUG) << "Вызов updateProductCount Database";
	txn->exec("UPDATE products SET count  = " + txn->quote(count) +
			  "WHERE product_id = " + txn->quote(id) + ";");
}

void ProductRepo::updateProductCost(int id, float cost)
{
	LOG(DEBUG) << "Вызов updateProductCost Database";
	txn->exec("UPDATE products SET cost  = " + txn->quote(cost) +
			  "WHERE product_id = " + txn->quote(id) + ";");
}

void ProductRepo::updateProductGrade(int id, int grade)
{
	LOG(DEBUG) << "Вызов updateProductGrade Database";
	txn->exec("UPDATE products SET grade  = " + txn->quote(grade) +
			  "WHERE product_id = " + txn->quote(id) + ";");
}

std::vector<Product> ProductRepo::getProductsByOrder(int OrderId)
{
	LOG(DEBUG) << "Вызов getProductsByOrder Database";
	std::vector<Product> products;
	pqxx::result res{
		txn->exec("SELECT product_id, title, category, content, count, cost, image_path, grade "\
				  "FROM products JOIN orders_products USING(product_id) WHERE order_id = " +
				  txn->quote(OrderId) + ";")};

	for(auto row : res)
	{
		Product product = Product(row[0].as<int>(),
								  row[1].as<std::string>(),
								  row[2].as<std::string>(),
								  row[3].as<std::string>(),
								  row[4].as<int>(),
								  row[5].as<float>(),
								  row[6].as<std::string>(),
								  row[7].as<int>());
		products.push_back(product);
	}

	return products;
}

std::vector<Product> ProductRepo::getProductsByCategory(std::string category)
{
	LOG(DEBUG) << "Вызов getProductsByCategory Database";
	std::vector<Product> products;
	pqxx::result res{
		txn->exec("SELECT product_id, title, category, content, count, cost, image_path, grade "\
				  "FROM products WHERE category = " + txn->quote(category) + ";")};

	for(auto row : res)
	{
		Product product = Product(row[0].as<int>(),
								  row[1].as<std::string>(),
								  row[2].as<std::string>(),
								  row[3].as<std::string>(),
								  row[4].as<int>(),
								  row[5].as<float>(),
								  row[6].as<std::string>(),
								  row[7].as<int>());
		products.push_back(product);
	}

	return products;
}

std::vector<Product> ProductRepo::getAllProducts()
{
	LOG(DEBUG) << "Вызов getAllProducts Database";
	std::vector<Product> products;
	pqxx::result res{
		txn->exec("SELECT product_id, title, category, content, count, cost, image_path, grade "\
				  "FROM products;")};

	for(auto row : res)
	{
		Product product = Product(row[0].as<int>(),
								  row[1].as<std::string>(),
								  row[2].as<std::string>(),
								  row[3].as<std::string>(),
								  row[4].as<int>(),
								  row[5].as<float>(),
								  row[6].as<std::string>(),
								  row[7].as<int>());
		products.push_back(product);
	}

	return products;
}

std::vector<Product> ProductRepo::getProductsByGrade(int grade)
{
	LOG(DEBUG) << "Вызов getProductsByGrade Database";
	std::vector<Product> products;
	pqxx::result res{
		txn->exec("SELECT product_id, title, category, content, count, cost, image_path, grade "\
				  "FROM products WHERE grade >= " + txn->quote(grade) + ";")};

	for(auto row : res)
	{
		Product product = Product(row[0].as<int>(),
								  row[1].as<std::string>(),
								  row[2].as<std::string>(),
								  row[3].as<std::string>(),
								  row[4].as<int>(),
								  row[5].as<float>(),
								  row[6].as<std::string>(),
								  row[7].as<int>());
		products.push_back(product);
	}

	return products;
}