#include "app.hpp"

#include "../bd/gradeRepo.hpp"
#include "../bd/orderRepo.hpp"
#include "../bd/productRepo.hpp"
#include "../bd/reviewRepo.hpp"
#include "../bd/userRepo.hpp"
#include "../logging/easylogging++.h"

#include <iostream>
#include <fstream>
#include <string>

INITIALIZE_EASYLOGGINGPP

int main()
{
    std::string logging, bd_conf;
    std::ifstream in("../config.txt");
    if (in.is_open())
    {
        in >> bd_conf >> logging;
    }
    if (logging == "file")
    {
        el::Loggers::reconfigureAllLoggers(el::ConfigurationType::ToStandardOutput, "false");
        el::Loggers::reconfigureAllLoggers(el::ConfigurationType::ToFile, "true");
    }
    else
    {
        el::Loggers::reconfigureAllLoggers(el::ConfigurationType::ToStandardOutput, "true");
        el::Loggers::reconfigureAllLoggers(el::ConfigurationType::ToFile, "false");
    }

    GradeRepo gradeRepo = GradeRepo(bd_conf);
    OrderRepo orderRepo = OrderRepo(bd_conf);
    ProductRepo productRepo = ProductRepo(bd_conf);
    ReviewRepo reviewRepo = ReviewRepo(bd_conf);
    UserRepo userRepo = UserRepo(bd_conf);

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