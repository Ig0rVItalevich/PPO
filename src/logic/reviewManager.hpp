#ifndef REVIEWMANAGER_H
#define REVIEWMANAGER_H

#include "../db/reviewRepo.hpp"
#include "../models/review.hpp"
#include <vector>

class ReviewManager
{
private:
	ReviewRepo* repository;

public:
	ReviewManager(ReviewRepo& repository);
	~ReviewManager();

	void addReview(std::string content, std::string date, int user_id);
	Review getReview(int id);
	void deleteReview(int id);
	void updateReviewContent(int id, std::string content);
	std::vector<Review> getReviewsByProduct(int productId);
};

#endif // REVIEWMANAGER_H