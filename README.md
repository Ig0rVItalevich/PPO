# Интернет магазин парфюмерии

## Лабораторная работа № 1

### Краткое описание идеи проекта

Необходимо реализовать БД, а также интерфейс для доступа к данным.

Данное приложение дает возможность выбора продукции, совершения заказа через менеджера, добавления отзывово и оценок к товарам магазина.

Типы пользователей: покупатель, менеджер, администратор.

### Краткое описание предметной области 

Предметной областью является парфюмерный бизнес. Продукция магазина представляет собой огромный выбор духов различных видов и производителей, а также, возможно, сопутствующих косметических товаров. Покупатель при заказе продукции должен пройти регистрацию. Заказ осуществляется после подтвеждения менеджером. Менеджер также осуществляет модерацию отзывов, обновление списка продукции и т.д.

### Краткий анализ аналогичных решений по 3 критериям

| Название      | Программа лояльности | Обязательная регистрация | Отображение оценки пользователей  | Косметические товары | Статистика изменения цены |
| -------------- | ------------ | ----- | --------- | ------| ----- |
| духи.рф   | Да | Нет | Да | Да | Да |
| fragrancex.com   | Нет | Нет | Да | Нет | Нет|
| perfume.com | Да | Нет | Да | Нет | Нет |

### Use-Case - диаграмма

![USE_CASE](./diagrams/use_case.png)

### ER-диаграмма сущностей

![ER](./diagrams/er.png)

## Лабораторная работа № 2

### Описание типа приложения и выбранного технологического стека
Тип приложения - Desktop

Технологический стек - C++, Qt, PostgreSQL

### Верхнеуровневое разбиение на компоненты
![VR](./diagrams/prototype.png)


### UML диаграммы классов для двух отдельных компонентов - компонента доступа к данным и компонента с бизнес-логикой
#### Компонент доступа к данным
![DBD](./lab_02/docs/ppo_dbd.png)

#### Компонент с бизнес-логикой
![BL](./lab_02/docs/ppo_bl.png)

### Сущности БД
![DB](./lab_02/docs/ppo_db.png)