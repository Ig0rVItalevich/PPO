#include "reviewPresenter.hpp"

ReviewPresenter::ReviewPresenter(ReviewManager& manager)
{
	this->manager = &manager;
	LOG(DEBUG) << "Создан ReviewPresenter";
}

void ReviewPresenter::addApp(App* application)
{
	LOG(DEBUG) << "Вызвано addApp Presenter";
	this->application = application;
}

void ReviewPresenter::addReview()
{
	LOG(DEBUG) << "Вызвано addReview Presenter";
	int user_id = 0, product_id = 0;
	std::string content = "", date = "2022-06-06";

	this->application->printer("Введите содержание отзыва: ");
	content = this->application->scanner();
	this->application->printer("Введите user_id: ");
	user_id = std::stoi(this->application->scanner());
	this->application->printer("Введите product_id: ");
	product_id = std::stoi(this->application->scanner());

	if(manager->addReview(content, date, user_id, product_id))
	{
		LOG(ERROR) << "Ошибка addReview Presenter";
		this->application->printer("Что-то пошло не так...");
	}
	else
	{
		this->application->printer("Операция прошла успешно.");
	}
}

void ReviewPresenter::deleteReview()
{
	LOG(DEBUG) << "Вызвано deleteReview Presenter";
	int id = 0;
	this->application->printer("Введите review_id: ");
	id = std::stoi(this->application->scanner());

	if(manager->getReview(id).getId() == 0)
	{
		LOG(WARNING) << "Отзыва с таким id не существует deleteReview Presenter";
		this->application->printer("Отзыва с таким id не существует.");
	}
	else
	{
		if(manager->deleteReview(id))
		{
			LOG(ERROR) << "Ошибка deleteReview Presenter";
			this->application->printer("Что-то пошло не так...");
		}
		else
		{
			this->application->printer("Операция прошла успешно.");
		}
	}
}

void ReviewPresenter::getReviewsByProduct()
{
	LOG(DEBUG) << "Вызвано getReviewsByProduct Presenter";
	int id = 0;
	this->application->printer("Введите product_id: ");
	id = std::stoi(this->application->scanner());

	std::vector<Review> reviews = manager->getReviewsByProduct(id);
	if(!reviews.size())
	{
		LOG(WARNING) << "Отзывы отсутствуют getReviewsByProduct Presenter";
		this->application->printer("Отзывы отсутствуют.");
	}
	else
	{
		for(Review review : reviews)
		{
			this->application->printer(review.toString());
		}
	}
}