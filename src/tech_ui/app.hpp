#ifndef APP_HPP
#define APP_HPP

#include <string>

#include "../models/grade.hpp"
#include "../models/order.hpp"
#include "../models/product.hpp"
#include "../models/review.hpp"
#include "../models/user.hpp"

#include "../logic/gradeManager.hpp"
#include "../logic/orderManager.hpp"
#include "../logic/productManager.hpp"
#include "../logic/reviewManager.hpp"
#include "../logic/usersManager.hpp"

#include "gradePresenter.hpp"
#include "orderPresenter.hpp"
#include "productPresenter.hpp"
#include "reviewPresenter.hpp"
#include "userPresenter.hpp"

const std::string menu = "\
0. Завершить программу\n\
1. Добавить пользователя\n\
2. Удалить пользователя\n\
3. Получить пользователя\n\
4. Добавить продукт\n\
5. Удалить продукт\n\
6. Получить продукт\n\
7. Получить список продуктов из заказа\n\
8. Добавить заказ\n\
9. Удалить заказ\n\
10. Получить заказ\n\
11. Получить заказы пользователя\n\
12. Добавить отзыв\n\
13. Удалить отзыв\n\
14. Получить отзывы по продукту\n\
15. Добавить оценку\n\
16. Удалить оценку\n\
17. Получить список оценок продукта\n\
18. Получить список продуктов по выбранной категории\n\
19. Получить список всех продуктов\n";

class App
{
private:
	UserPresenter* userPres;
	ProductPresenter* productPres;
	OrderPresenter* orderPres;
	ReviewPresenter* reviewPres;
	GradePresenter* gradePres;

public:
	App(UserManager& userManager,
		ProductManager& productManager,
		OrderManager& orderManager,
		ReviewManager& reviewManager,
        GradeManager& gradeManager);
	~App() = default;

	void printMenu();
	void processRequest();
};

#endif