#include "reviewManager.hpp"

ReviewManager::ReviewManager(ReviewRepo& repository)
{
	this->repository = repository;
}

~ReviewManager::ReviewManager() { }

void ReviewManager::addReview(std::string content, std::string date, int user_id)
{
	this->repository->addReview(content, date, user_id);
}

Review ReviewManager::getReview(int id)
{
	Review review = this->repository->getReview(id);

	return review;
}

void ReviewManager::deleteReview(int id)
{
	this->repository->deleteReview(id);
}

void ReviewManager::updateReviewContent(int id, std::string content)
{
	this->repository->updateReviewContent(id, content);
}

std::vector<Review> ReviewManager::getReviewsByProduct(int productId)
{
	std::vector<Review> reviews = this->repository->getReviewsByProduct(productId);

	return reviews;
}