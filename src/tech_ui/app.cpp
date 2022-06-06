#include "app.hpp"

App::App(UserManager& userManager,
		ProductManager& productManager,
		OrderManager& orderManager,
		ReviewManager& reviewManager,
        GradeManager& gradeManager)
{
	this->userPres = new UserPresenter(userManager);
	this->productPres = new ProductPresenter(productManager);
	this->orderPres = new OrderPresenter(orderManager);
	this->reviewPres = new ReviewPresenter(reviewManager);
	this->gradePres = new GradePresenter(gradeManager);
}

void App::printMenu()
{
	std::cout << menu;
}

void App::processRequest()
{
	int position = -1;
	while(position != 0)
	{
        std::cout << "Введите номер действия: ";
        std::cin >> position;

		switch(position)
		{
		case 0:
			break;
		case 1:
            userPres->addUser();
			break;
		case 2:
            userPres->deleteUser();
			break;
		case 3:
            userPres->getUser();
			break;
		case 4:
            productPres->addProduct();
			break;
		case 5:
            productPres->deleteProduct();
			break;
		case 6:
            productPres->getProduct();
			break;
		case 7:
            productPres->getProductsByOrder();
			break;
		case 8:
            orderPres->addOrder();
			break;
		case 9:
            orderPres->deleteOrder();
			break;
		case 10:
            orderPres->getOrder();
			break;
		case 11:
            orderPres->getOrdersByUser();
			break;
		case 12:
            reviewPres->addReview();
			break;
		case 13:
            reviewPres->deleteReview();
			break;
		case 14:
            reviewPres->getReviewsByProduct();
			break;
		case 15:
            gradePres->addGrade();
			break;
		case 16:
            gradePres->deleteGrade();
			break;
		case 17:
            gradePres->getGradesByProduct();
			break;
		case 18:
            productPres->getProductsByCategory();
			break;
		case 19:
            productPres->getAllProducts();
			break;
		default:
			std::cout << "Неверный номер";
			break;
		}
	}
}