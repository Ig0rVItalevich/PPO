import psycopg2
import json
from random import randint
from faker import Faker

fake = Faker()

host = "127.0.0.1"
user = "postgres"
password = "qwerty123"
db_name = "ppo"

connection = None


def insert_users(connection, cursor):
    with open("users.json", "r") as read_file:
        users = json.load(read_file)

    insert_query = """ INSERT INTO users (user_name, mail, birth_date, sex, address, permissions, user_password)
                              VALUES (%s, %s, %s, %s, %s, %s, %s)"""

    for i in range(len(users)):
        user = users[i]
        item_tuple = (user["user_name"], user["mail"], user["birth_date"],
                      user["sex"], user["address"], user["permissions"], user["user_password"])
        cursor.execute(insert_query, item_tuple)

    connection.commit()


def insert_products(connection, cursor):
    with open("products.json", "r") as read_file:
        products = json.load(read_file) 

    insert_query = """ INSERT INTO products(title, category, content, count, cost, image_path, grade)
                              VALUES (%s, %s, %s, %s, %s, %s, %s)"""

    for i in range(len(products)):
        product = products[i]
        item_tuple = (product["title"], product["category"], product["content"],
                      product["count"], product["cost"], product["image_path"], product["grade"])
        cursor.execute(insert_query, item_tuple)

    connection.commit()


def insert_orders(connection, cursor):
    with open("orders.json", "r") as read_file:
        orders = json.load(read_file)

    insert_query = """ INSERT INTO orders (order_date, status, comment, user_id)
                              VALUES (%s, %s, %s, %s)"""

    for i in range(len(orders)):
        order = orders[i]
        item_tuple = (order["order_date"], order["status"],
                      order["comment"], order["user_id"])
        cursor.execute(insert_query, item_tuple)

    connection.commit()


def insert_grades(connection, cursor):
    with open("grades.json", "r") as read_file:
        grades = json.load(read_file)

    insert_query = """ INSERT INTO grades (value, grade_date, user_id)
                              VALUES (%s, %s, %s)"""

    for i in range(len(grades)):
        grade = grades[i]
        item_tuple = (grade["value"], grade["grade_date"], grade["user_id"])
        cursor.execute(insert_query, item_tuple)

    connection.commit()


def insert_reviews(connection, cursor):
    with open("reviews.json", "r") as read_file:
        reviews = json.load(read_file)

    insert_query = """ INSERT INTO reviews (content, review_date, user_id)
                              VALUES (%s, %s, %s)"""

    for i in range(len(reviews)):
        review = reviews[i]
        item_tuple = (review["content"],
                      review["review_date"], review["user_id"])
        cursor.execute(insert_query, item_tuple)

    connection.commit()


def insert_op(connection, cursor):
    with open("orders_products.json", "r") as read_file:
        ops = json.load(read_file)

    insert_query = """ INSERT INTO orders_products (order_id, product_id)
                              VALUES (%s, %s)"""

    for i in range(len(ops)):
        op = ops[i]
        item_tuple = (op["order_id"], op["product_id"])
        cursor.execute(insert_query, item_tuple)

    connection.commit()


def insert_pg(connection, cursor):
    with open("products_grades.json", "r") as read_file:
        pgs = json.load(read_file)

    insert_query = """ INSERT INTO products_grades (product_id, grade_id)
                              VALUES (%s, %s)"""

    for i in range(len(pgs)):
        pg = pgs[i]
        item_tuple = (pg["product_id"], pg["grade_id"])
        cursor.execute(insert_query, item_tuple)

    connection.commit()


def insert_pr(connection, cursor):
    with open("products_reviews.json", "r") as read_file:
        prs = json.load(read_file)

    insert_query = """ INSERT INTO products_reviews (product_id, review_id)
                              VALUES (%s, %s)"""

    for i in range(len(prs)):
        pr = prs[i]
        item_tuple = (pr["product_id"], pr["review_id"])
        cursor.execute(insert_query, item_tuple)

    connection.commit()


def delete_data(connection, cursor):
    delete_query = """DELETE FROM users"""
    cursor.execute(delete_query)
    delete_query = """DELETE FROM products"""
    cursor.execute(delete_query)
    delete_query = """DELETE FROM orders"""
    cursor.execute(delete_query)
    delete_query = """DELETE FROM grades"""
    cursor.execute(delete_query)
    delete_query = """DELETE FROM reviews"""
    cursor.execute(delete_query)
    delete_query = """DELETE FROM orders_products"""
    cursor.execute(delete_query)
    delete_query = """DELETE FROM products_grades"""
    cursor.execute(delete_query)
    delete_query = """DELETE FROM products_reviews"""
    cursor.execute(delete_query)

    connection.commit()

def restart_data(connection, cursor):
    delete_query = """SELECT setval('users_user_id_seq', 1);"""
    cursor.execute(delete_query)
    delete_query = """SELECT setval('products_product_id_seq', 1);"""
    cursor.execute(delete_query)
    delete_query = """SELECT setval('orders_order_id_seq', 1);"""
    cursor.execute(delete_query)
    delete_query = """SELECT setval('grades_grade_id_seq', 1);"""
    cursor.execute(delete_query)
    delete_query = """SELECT setval('reviews_review_id_seq', 1);"""
    cursor.execute(delete_query)
    delete_query = """SELECT setval('orders_products_order_id_seq', 1);"""
    cursor.execute(delete_query)
    delete_query = """SELECT setval('products_grades_product_id_seq', 1);"""
    cursor.execute(delete_query)
    delete_query = """SELECT setval('products_reviews_product_id_seq', 1);"""
    cursor.execute(delete_query)

    connection.commit()


try:
    connection = psycopg2.connect(
        host=host,
        user=user,
        password=password,
        database=db_name
    )
    connection.autocommit = True

    cursor = connection.cursor()

    delete_data(connection, cursor)
    restart_data(connection, cursor)
    insert_users(connection, cursor)
    insert_products(connection, cursor)
    insert_orders(connection, cursor)
    insert_reviews(connection, cursor)
    insert_grades(connection, cursor)
    insert_op(connection, cursor)
    insert_pg(connection, cursor)
    insert_pr(connection, cursor)

except Exception as _ex:
    print("[INFO] Error while working with PostgreSQL", _ex)
finally:
    if connection:
        cursor.close()
        connection.close()
        print("[INFO] PostgreSQL connection closed")
