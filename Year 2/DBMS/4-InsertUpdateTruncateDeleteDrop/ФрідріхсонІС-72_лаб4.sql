-- 1. Додати себе як співробітника компанії на позицію Intern.
INSERT INTO employees (LastName, FirstName, Title, TitleOfCourtesy, BirthDate, HireDate, Address, City,
                       PostalCode, Country, HomePhone, Extension, Photo, Notes, PhotoPath, Salary)
                       VALUES ('Fridrikhson', 'Michael', 'Intern', 'Mr.','2000-01-17 17:00:00', UTC_TIMESTAMP(),
                               'Pushkin Street, 1', 'Kyiv', '04132', 'Ukraine', '(255) 535-3535', 500 ,'Photo', 'Note',
                               'Path', 2500.2);

-- 2. Змінити свою посаду на Director.
UPDATE employees SET Title='Director' WHERE LastName='Fridrikhson';

-- 3. Скопіювати таблицю Orders в таблицю OrdersArchive.
CREATE TABLE IF NOT EXISTS OrdersArchive AS SELECT * FROM orders;

-- 4. Очистити таблицю OrdersArchive.
TRUNCATE TABLE OrdersArchive;

-- 5. Не видаляючи таблицю OrdersArchive, наповнити її інформацією повторно.
INSERT INTO OrdersArchive SELECT * FROM orders;

-- 6. З таблиці OrdersArchive видалити усі замовлення, які були зроблені замовниками із Берліну.
DELETE FROM OrdersArchive WHERE ShipCity='Berlin';
-- SELECT ShipCity FROM OrdersArchive WHERE ShipCity='Berlin';

-- 7. Внести в базу два продукти – з власним іменем та назвою групи.
INSERT INTO Products (ProductName, SupplierID, CategoryID, QuantityPerUnit, UnitPrice, UnitsInStock,
                      UnitsOnOrder, ReorderLevel, Discontinued)
                      VALUES ('Michael', '1', '1', '1 body', 500, 1, 0, 0, FALSE),
                             ('IS72', '1', '2', '1 group', 500, 1, 0, 0, FALSE);

-- 8. Помітити продукти, що не фігурують в замовленнях, як такі, що більше не виробляються.
UPDATE products SET Discontinued=TRUE WHERE ProductID NOT IN (
  SELECT ProductID FROM `order details`
  );

-- 9. Видалити таблицю OrdersArchive.
DROP TABLE OrdersArchive;

-- 10. Видалити базу Northwind.
-- DROP DATABASE northwind;