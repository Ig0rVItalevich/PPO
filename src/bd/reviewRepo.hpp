#ifndef REVIEWREPO_H
#define REVIEWREPO_H

#include "../models/review.hpp"
#include <iostream>
#include <string>

class InterfaceReviewRepo
{
public:
	InterfaceReviewRepo();
	~InterfaceReviewRepo() = default;

	void addReview(std::string content, std::string date, int user_id, int product_id);
	Review getReview(int id);
	void deleteReview(int id);
	void updateReviewContent(int id, std::string content);
	std::vector<Review> getReviewsByProduct(int productId);
};

class ReviewRepo : public InterfaceReviewRepo
{
private:
	std::shared_ptr<pqxx::connection> connection;
	std::shared_ptr<pqxx::work> txn;

public:
	explicit ReviewRepo()
		: connection(new pqxx::connection("postgresql://postgres:qwerty123@localhost/ppo"))
		, txn(new pqxx::work(*connection)){};
	~ReviewRepo() = default;

	void addReview(std::string content, std::string date, int user_id, int product_id);
	Review getReview(int id);
	void deleteReview(int id);
	void updateReviewContent(int id, std::string content);
	std::vector<Review> getReviewsByProduct(int productId);
};

#endif // REVIEWREPO_H