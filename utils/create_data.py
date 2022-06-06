import json
from faker import Faker
from random import randint

fake = Faker()

gender = ['male', 'female']

def users():
    users = []
    for i in range(30):
        user = {}
        user['user_name'] = fake.name()
        user['user_password'] = fake.word() + str(randint(1, 1000))
        user['mail'] = fake.ascii_email()
        user['birth_date'] = fake.date()
        user['sex'] = gender[randint(0, 1)]
        user['address'] = fake.address()
        user['permissions'] = 0

        users.append(user)

    with open("users.json","w") as write_file: 
        json.dump(users, write_file, indent = 4, separators = (',', ': '))

def products():
    products = []
    for i in range(20):
        product = {}
        product['title'] = fake.paragraph(1)
        product['content'] = fake.paragraph(2)
        product['category'] = fake.word()
        product['count'] = randint(1, 100)
        product['cost'] = randint(1, 50000) / 10
        product['image_path'] = "./images" + str(i)
        product['grade'] = randint(1, 10)

        products.append(product)

    with open("products.json","w") as write_file: 
        json.dump(products, write_file, indent = 4, separators = (',', ': '))

def orders():
    orders = []
    for i in range(40):
        order = {}
        order['comment'] = fake.paragraph(2)
        order['user_id'] = randint(2, 31)
        order['status'] = fake.word()
        order['order_date'] = fake.date()

        orders.append(order)

    with open("orders.json","w") as write_file: 
        json.dump(orders, write_file, indent = 4, separators = (',', ': '))

def reviews():
    reviews = []
    for i in range(60):
        review = {}
        review['content'] = fake.paragraph(1)
        review['user_id'] = randint(2, 31)
        review['review_date'] = fake.date()

        reviews.append(review)

    with open("reviews.json","w") as write_file: 
        json.dump(reviews, write_file, indent = 4, separators = (',', ': '))

def grades():
    grades = []
    for i in range(60):
        grade = {}
        grade['value'] = randint(1, 10)
        grade['user_id'] = randint(2, 31)
        grade['grade_date'] = fake.date()

        grades.append(grade)

    with open("grades.json","w") as write_file: 
        json.dump(grades, write_file, indent = 4, separators = (',', ': '))

def products_reviews():
    products_reviews = []
    for i in range(10):
        item = {}
        item['product_id'] = randint(2, 21)
        item['review_id'] = randint(2, 61)

        products_reviews.append(item)

    with open("products_reviews.json","w") as write_file: 
        json.dump(products_reviews, write_file, indent = 4, separators = (',', ': '))

def products_grades():
    products_grades = []
    for i in range(10):
        item = {}
        item['product_id'] = randint(2, 21)
        item['grade_id'] = randint(2, 61)

        products_grades.append(item)

    with open("products_grades.json","w") as write_file: 
        json.dump(products_grades, write_file, indent = 4, separators = (',', ': '))

def orders_products():
    orders_products = []
    for i in range(10):
        item = {}
        item['order_id'] = randint(2, 41)
        item['product_id'] = randint(2, 21)

        orders_products.append(item)

    with open("orders_products.json","w") as write_file: 
        json.dump(orders_products, write_file, indent = 4, separators = (',', ': '))
        
users()
products()
orders()
reviews()
grades()
products_reviews()
products_grades()
orders_products()