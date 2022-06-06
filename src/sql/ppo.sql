CREATE TABLE "users" (
  "user_id" SERIAL PRIMARY KEY,
  "user_name" varchar(100) UNIQUE NOT NULL,
  "birth_date" date,
  "address" varchar(100),
  "mail" varchar(60),
  "user_password" varchar(50) NOT NULL,
  "sex" varchar(10),
  "permissions" int
);

CREATE TABLE "products" (
  "product_id" SERIAL PRIMARY KEY,
  "title" varchar(100),
  "category" varchar(100),
  "content" text,
  "count" int,
  "cost" int,
  "image_path" varchar(100) UNIQUE NOT NULL,
  "grade" int,
);

CREATE TABLE "orders" (
  "order_id" SERIAL PRIMARY KEY,
  "order_date" date,
  "status" varchar(50),
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
  "content" varchar(100),
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

ALTER TABLE "grades" ADD FOREIGN KEY ("user_id") REFERENCES "users" ("user_id") ON DELETE CASCADE;

ALTER TABLE "orders" ADD FOREIGN KEY ("user_id") REFERENCES "users" ("user_id") ON DELETE CASCADE;

ALTER TABLE "products_reviews" ADD FOREIGN KEY ("product_id") REFERENCES "products" ("product_id") ON DELETE CASCADE;

ALTER TABLE "products_reviews" ADD FOREIGN KEY ("review_id") REFERENCES "reviews" ("review_id") ON DELETE CASCADE;

ALTER TABLE "products_grades" ADD FOREIGN KEY ("product_id") REFERENCES "products" ("product_id") ON DELETE CASCADE;

ALTER TABLE "products_grades" ADD FOREIGN KEY ("grade_id") REFERENCES "grades" ("grade_id") ON DELETE CASCADE;

ALTER TABLE "reviews" ADD FOREIGN KEY ("user_id") REFERENCES "users" ("user_id") ON DELETE CASCADE;

ALTER TABLE "orders_products" ADD FOREIGN KEY ("order_id") REFERENCES "orders" ("order_id") ON DELETE CASCADE;

ALTER TABLE "orders_products" ADD FOREIGN KEY ("product_id") REFERENCES "products" ("product_id") ON DELETE CASCADE;
