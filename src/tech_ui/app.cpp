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

	LOG(DEBUG) << "Создано Application";
}

void App::addApp()
{
	this->productPres->addApp(this);
	this->userPres->addApp(this);
	this->orderPres->addApp(this);
	this->reviewPres->addApp(this);
	this->gradePres->addApp(this);

	LOG(DEBUG) << "Заполнение поля Application в Presenters";
}

void App::printMenu()
{
	LOG(DEBUG) << "Вызов printMenu Application";
	std::cout << menu;
}

void App::processRequest()
{
	LOG(DEBUG) << "Вызов processRequest Application";
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
		case 20:
            productPres->getProductsByGrade();
			break;
		default:
			LOG(WARNING) << "Введено неверный номер действия Application";
			std::cout << "Неверный номер";
			break;
		}
	}
}

void App::printer(std::string str)
{
	LOG(DEBUG) << "Вызов printer Application";
	std::cout<< str << std::endl;
}

std::string App::scanner()
{
	LOG(DEBUG) << "Вызов scanner Application";
	std::string str = "";
	std::cin >> str;

	return str;
}