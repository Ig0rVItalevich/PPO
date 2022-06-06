#include "reviewPresenter.hpp"

ReviewPresenter::ReviewPresenter(ReviewManager& manager)
{
	this->manager = &manager;
}

void ReviewPresenter::addReview()
{
	int user_id = 0, product_id = 0;
	std::string content = "", date = "2022-06-06";

	std::cout << "Введите содержание отзыва: ";
	std::cin >> content;
	std::cout << "Введите user_id: ";
	std::cin >> user_id;
	std::cout << "Введите product_id: ";
	std::cin >> product_id;

	if(manager->addReview(content, date, user_id, product_id))
	{
		std::cout << "Что-то пошло не так..." << std::endl;
	}
	else
	{
		std::cout << "Операция прошла успешно." << std::endl;
	}
}

void ReviewPresenter::deleteReview()
{
	int id = 0;
	std::cout << "Введите review_id: ";
	std::cin >> id;

	if(manager->getReview(id).getId() == 0)
	{
		std::cout << "Отзыва с таким id не существует." << std::endl;
	}
	else
	{
		if(manager->deleteReview(id))
		{
			std::cout << "Что-то пошло не так..." << std::endl;
		}
		else
		{
			std::cout << "Операция прошла успешно." << std::endl;
		}
	}
}

void ReviewPresenter::getReviewsByProduct()
{
	int id = 0;
	std::cout << "Введите product_id: ";
	std::cin >> id;

	std::vector<Review> reviews = manager->getReviewsByProduct(id);
	if(!reviews.size())
	{
		std::cout << "Отзывы отсутствуют." << std::endl;
	}
	else
	{
		for(Review review : reviews)
		{
			std::cout << review.toString() << std::endl;
		}
	}
}