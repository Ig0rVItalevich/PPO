#include "app.hpp"

#include "../bd/gradeRepo.hpp"
#include "../bd/orderRepo.hpp"
#include "../bd/productRepo.hpp"
#include "../bd/reviewRepo.hpp"
#include "../bd/userRepo.hpp"
#include "../logging/easylogging++.h"

INITIALIZE_EASYLOGGINGPP

int main()
{
    // el::Loggers::reconfigureAllLoggers(el::ConfigurationType::ToStandardOutput, "false");
    el::Loggers::reconfigureAllLoggers(el::ConfigurationType::ToFile, "true");

    GradeRepo gradeRepo = GradeRepo();
    OrderRepo orderRepo = OrderRepo();
    ProductRepo productRepo = ProductRepo();
    ReviewRepo reviewRepo = ReviewRepo();
    UserRepo userRepo = UserRepo();

    GradeManager gradeManager = GradeManager(gradeRepo);
    OrderManager orderManager = OrderManager(orderRepo);
    ProductManager productManager = ProductManager(productRepo);
    ReviewManager reviewManager = ReviewManager(reviewRepo);
    UserManager userManager = UserManager(userRepo);

    App app = App(userManager, productManager, orderManager, reviewManager, gradeManager);
    app.addApp();
    app.printMenu();
    app.processRequest();

    return 0;
}