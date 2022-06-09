#include "reviewManager.hpp"

ReviewManager::ReviewManager(ReviewRepo& repository)
{
	LOG(DEBUG) << "Создан ReviewManager";
	this->repository = &repository;
}

int ReviewManager::addReview(std::string content, std::string date, int user_id, int product_id)
{
	LOG(DEBUG) << "Вызов addReview BusinessLogic";
	return this->repository->addReview(content, date, user_id, product_id);
}

Review ReviewManager::getReview(int id)
{
	LOG(DEBUG) << "Вызов getReview BusinessLogic";
	Review review = this->repository->getReview(id);

	return review;
}

int ReviewManager::deleteReview(int id)
{
	LOG(DEBUG) << "Вызов deleteReview BusinessLogic";
	return this->repository->deleteReview(id);
}

void ReviewManager::updateReviewContent(int id, std::string content)
{
	LOG(DEBUG) << "Вызов updateReviewContent BusinessLogic";
	this->repository->updateReviewContent(id, content);
}

std::vector<Review> ReviewManager::getReviewsByProduct(int productId)
{
	LOG(DEBUG) << "Вызов getReviewsByProduct BusinessLogic";
	std::vector<Review> reviews = this->repository->getReviewsByProduct(productId);

	return reviews;
}