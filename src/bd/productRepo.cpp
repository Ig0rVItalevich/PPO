#include "productRepo.hpp"

void productRepo::addProduct(std::string title,
							 std::string category,
							 std::string content,
							 int count,
							 float cost,
							 std::string image_path,
							 int grade)
{
	txn->exec(
		"INSERT INTO orders (title, category, content, count, cost, image_path, grade)
              VALUES (" + txn->quote(title) + ", " + txn->quote(category) + ", " + txn->quote(content) + \
			  ", " + txn->quote(count) + txn->quote(cost) + ", " + txn->quote(image_path) + ", " + txn->quote(grade) + ");");

	txn->commit();
}

Product productRepo::getProduct(int id)
{
	Product product = Product();
	pqxx::result res{txn->exec("SELECT title, category, content, count, cost, image_path, grade "
							   "FROM products WHERE product_id = " +
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

void productRepo::deleteProduct(int id)
{
	txn->exec("DELETE FROM products WHERE product_id = " + txn->quote(id) + ";");

	txn->commit();
}

void productRepo::updateProductTitle(int id, std::string title)
{
	txn->exec("UPDATE products SET title  = " + txn->quote(title) +
			  "WHERE product_id = " + txn->quote(id) + ";");

	txn->commit();
}

void productRepo::updateProductCategory(int id, std::string category)
{
	txn->exec("UPDATE products SET category  = " + txn->quote(category) +
			  "WHERE product_id = " + txn->quote(id) + ";");

	txn->commit();
}

void productRepo::updateProductContent(int id, std::string content)
{
	txn->exec("UPDATE products SET content  = " + txn->quote(content) +
			  "WHERE product_id = " + txn->quote(id) + ";");

	txn->commit();
}

void productRepo::updateProductCount(int id, int count)
{
	txn->exec("UPDATE products SET count  = " + txn->quote(count) +
			  "WHERE product_id = " + txn->quote(id) + ";");

	txn->commit();
}

void productRepo::updateProductCost(int id, float cost)
{
	txn->exec("UPDATE products SET cost  = " + txn->quote(cost) +
			  "WHERE product_id = " + txn->quote(id) + ";");

	txn->commit();
}

void productRepo::updateProductGrade(int id, int grade)
{
	txn->exec("UPDATE products SET grade  = " + txn->quote(grade) +
			  "WHERE product_id = " + txn->quote(id) + ";");

	txn->commit();
}

std::vector<Product> productRepo::getProductsByOrder(int OrderId)
{
	std::vector<Product> products;
	pqxx::result res{
		txn->exec("SELECT product_id, title, category, content, count, cost, image_path, grade "
				  "FROM products JOIN orders_products USING(product_id) WHERE order_id = " +
				  txn->quote(id) + ";")};

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