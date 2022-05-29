#include "reviewRepo.hpp"

void ReviewRepo::addReview(std::string content, std::string date, int user_id, int product_id)
{
	txn->exec(
		"INSERT INTO grades (value, grade_date, user_id)
              VALUES (" + txn->quote(value) + ", " + txn->quote(date) + ", " + txn->quote(user_id) + ");");

	int id = 0;
	pqxx::result res{txn->exec(
		"SELECT max(review_id) FROM reviews;")};
	for(auto row : res)
	{
		id = row[0].as<int>();
	}

	txn->exec(
		"INSERT INTO products_reviews (product_id, review_id)
              VALUES (" + txn->quote(product_id) + ", " + txn->quote(id + 1) + ");");

	txn->commit();
}

Review ReviewRepo::getReview(int id)
{
	Review review = Review();
	pqxx::result res{txn->exec(
		"SELECT content, review_date, user_id FROM reviews WHERE review_id = " + txn->quote(id) +
		";")};

	for(auto row : res)
	{
		review = Review(id, row[0].as<std::string>(), row[1].as<std::string>(), row[2].as<int>());
	}

	return review;
}

void ReviewRepo::deleteReview(int id)
{
	txn->exec("DELETE FROM reviews WHERE review_id = " + txn->quote(id) + ";");

	txn->commit();
}

void ReviewRepo::updateReviewContent(int id, std::string content)
{
	txn->exec("UPDATE reviews SET content  = " + txn->quote(content) +
			  "WHERE review_id = " + txn->quote(id) + ";");

	txn->commit();
}

std::vector<Review> ReviewRepo::getReviewsByProduct(int productId)
{
	std::vector<Review> reviews;
	pqxx::result res{
		txn->exec("SELECT review_id, content, review_date, user_id FROM grades JOIN products_reviews "
				  "USING(review_id) WHERE product_id = " +
				  txn->quote(productId) + ";")};

	for(auto row : res)
	{
		Review review =
			Review(row[0].as<int>(), row[1].as<std::string>(), row[2].as<std::string>(), row[3].as<int>());
		reviews.push_back(review);
	}

	return reviews;
}