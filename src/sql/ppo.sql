CREATE TABLE "users" (
  "user_id" SERIAL PRIMARY KEY,
  "name" varchar(100) UNIQUE NOT NULL,
  "birth_date" date,
  "address" varchar(50),
  "mail" varchar(50),
  "password" varchar(20) NOT NULL,
  "sex" varchar(10),
  "permissions" int
);

CREATE TABLE "products" (
  "product_id" SERIAL PRIMARY KEY,
  "title" varchar(100),
  "category" varchar(20),
  "content" text,
  "count" int,
  "cost" int,
  "image_path" varchar(100) UNIQUE NOT NULL
);

CREATE TABLE "orders" (
  "order_id" SERIAL PRIMARY KEY,
  "order_date" date,
  "status" varchar(20),
  "comment" varchar(100),
  "user_id" int
);

CREATE TABLE "grades" (
  "grade_id" SERIAL PRIMARY KEY,
  "value" int,
  "grade_date" date,
  "user_id" int
);

CREATE TABLE "reviews" (
  "review_id" SERIAL PRIMARY KEY,
  "content" varchar(50),
  "review_date" date,
  "user_id" int
);

CREATE TABLE "products_reviews" (
  "product_id" SERIAL,
  "review_id" SERIAL,
  PRIMARY KEY ("product_id", "review_id")
);

CREATE TABLE "products_grades" (
  "product_id" SERIAL,
  "grade_id" SERIAL,
  PRIMARY KEY ("product_id", "grade_id")
);

CREATE TABLE "orders_products" (
  "order_id" SERIAL,
  "product_id" SERIAL,
  PRIMARY KEY ("order_id", "product_id")
);

ALTER TABLE "grades" ADD FOREIGN KEY ("user_id") REFERENCES "users" ("user_id");

ALTER TABLE "orders" ADD FOREIGN KEY ("user_id") REFERENCES "users" ("user_id");

ALTER TABLE "products_reviews" ADD FOREIGN KEY ("product_id") REFERENCES "products" ("product_id");

ALTER TABLE "products_reviews" ADD FOREIGN KEY ("review_id") REFERENCES "reviews" ("review_id");

ALTER TABLE "products_grades" ADD FOREIGN KEY ("product_id") REFERENCES "products" ("product_id");

ALTER TABLE "products_grades" ADD FOREIGN KEY ("grade_id") REFERENCES "grades" ("grade_id");

ALTER TABLE "reviews" ADD FOREIGN KEY ("user_id") REFERENCES "users" ("user_id");

ALTER TABLE "orders_products" ADD FOREIGN KEY ("order_id") REFERENCES "orders" ("order_id");

ALTER TABLE "orders_products" ADD FOREIGN KEY ("product_id") REFERENCES "products" ("product_id");