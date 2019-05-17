-- 1. Вивести за допомогою команди SELECT своє прізвище, ім’я та по-батькові на екран.
-- INSERT INTO Customers VALUES ("MCFRD", "Fridrikhson'n'Co", "Mykhailo Anatolich Fridrkhson", "IT", "Khreshatyk st., 1", "Kyiv", "Kyiv oblast", "02154", "Ukraine", "+380664400467", "2282281488");
SELECT ContactName FROM Customers WHERE ContactName="Mykhailo Anatolich Fridrkhson"; 

-- 2. Вибрати всі дані з таблиці Products.
SELECT * FROM Products;

-- 3. Обрати всі назви продуктів з тієї ж таблиці, продаж яких припинено.
SELECT ProductName, Discontinued FROM Products WHERE discontinued=1;

-- 4. Вивести всі міста клієнтів уникаючи дублікатів.
SELECT DISTINCT City FROM Customers;

-- 5. Вибрати всі назви компаній-постачальників в порядку зворотньому алфавітному.
SELECT CompanyName FROM Suppliers ORDER BY CompanyName DESC;

-- 6. Отримати всі деталі замовлень, замінивши назви стовбчиків на їх порядковий номер.
SELECT OrderID as `1`, ProductID as `2`, UnitPrice as `3`, Quantity as `4`, Discount as `5` FROM `order details`;

-- 7. Вивести всі контактні імена клієнтів, що починаються з першої літери вашого прізвища, імені, по-батькові.
SELECT ContactName FROM customers WHERE ContactName RLIKE '^[afm]';

-- 8. Показати усі замовлення, в адресах доставки яких є пробіл.
SELECT ShipAddress FROM orders WHERE ShipAddress RLIKE '.[[:blank:]].';

-- 9. Вивести назви тих продуктів, що починаються на знак % або _, а закінчуються на останню літеру вашого імені.
SELECT ProductName FROM products WHERE ProductName RLIKE '^[%_].*o$';