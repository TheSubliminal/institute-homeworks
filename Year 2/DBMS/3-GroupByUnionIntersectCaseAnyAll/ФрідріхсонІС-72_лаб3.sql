-- *********** ЗАДАЧА 1 ***********

-- 1. Використовуючи SELECT двічі, виведіть на екран своє ім’я, 
-- прізвище та по-батькові одним результуючим набором.
SELECT 'Mykhailo Anatoliyovych' UNION SELECT 'Fridrikhson';

-- 2. Порівнявши власний порядковий номер в групі з набором із 
-- всіх номерів в групі, вивести на екран ;-) якщо він менший 
-- за усі з них, або :-D в протилежному випадку.
-- CREATE TABLE IF NOT EXISTS groupids (id SMALLINT NOT NULL);
-- INSERT INTO groupids (id) VALUES (1), (2), (3), (4), (5), (6), (7), (8), (9), (10), (11), (12), (13), (14), (15), (16), (17), (18), (19), (20), (21), (22), (23), (24), (25), (26), (27), (28), (29);
SELECT CASE 
			WHEN 22 < ALL(SELECT id FROM groupids WHERE id BETWEEN 23 AND 28)
			THEN ';-)'
			ELSE ':-D'
		END AS result;
		
-- 3. Не використовуючи таблиці, вивести на екран прізвище та ім’я 
-- усіх дівчат своєї групи за вийнятком тих, хто має спільне ім’я 
-- з студентками іншої групи.
WITH is72 (name, surname) AS (VALUES
	('Katya', 'Berezyanko'), ('Karina', 'Doroshenko'), ('Katya', 'Krasnozhon'),
	('Sasha', 'Kravets'), ('Lena', 'Kravchuk'), ('Arina', 'Maiboroda'),
	('Alisa', 'Proschenko'), ('Rita', 'Khovanova')
), is71 (name, surname) AS (VALUES
	('Olesia', 'Dmytruk'), ('Julia', 'Alpaeva'), ('Katya', 'Novakivska'),
	('Darina','Mozolyova'), ('Lena', 'Motiashova')
)
SELECT surname, name FROM is72 WHERE name IN (
	SELECT name FROM is72 EXCEPT SELECT name FROM is71
);

-- 4. Вивести усі рядки з таблиці Numbers (Number INT). 
-- Замінити цифру від 0 до 9 на її назву літерами. Якщо цифра більше, 
-- або менша за названі, залишити її без змін.
-- CREATE TABLE IF NOT EXISTS numbers (number INT);
-- INSERT INTO numbers (number) VALUES (0), (1), (2), (3), (4), (5), (6), (7), (8), (9), (10), (11), (12), (13), (14), (15), (16), (17), (18), (19), (20), (21), (22), (23), (24), (25), (26), (27), (28), (29), (30);
SELECT 
CASE
	WHEN number >= 0 AND number <= 9 
	THEN 
		CASE
			WHEN number=0
			THEN 'Zero'
			WHEN number=1
			THEN 'One'
			WHEN number=2
			THEN 'Two'
			WHEN number=3
			THEN 'Three'
			WHEN number=4
			THEN 'Four'
			WHEN number=5
			THEN 'Five'
			WHEN number=6
			THEN 'Six'
			WHEN number=7
			THEN 'Seven'
			WHEN number=8
			THEN 'Eight'
			WHEN number=9
			THEN 'Nine'
		END
	ELSE number
END AS number
FROM numbers;

-- 5. Навести приклад синтаксису декартового об’єднання для вашої СУБД.
-- SELECT * FROM Table1 CROSS JOIN Table2;

-- *********** ЗАДАЧА 2 ***********

-- 1. Вивисти усі замовлення та їх службу доставки. В залежності від 
-- ідентифікатора служби доставки, переіменувати її на таку, що відповідає 
-- вашому імені, прізвищу, або по-батькові.
SELECT OrderID, ShipVia, CASE 
				 WHEN orders.ShipVia=1 
				 THEN 'Fridrikhson' 
				 ELSE shippers.CompanyName 
			 END
FROM orders INNER JOIN shippers ON orders.ShipVia=shippers.ShipperID;

-- 2. Вивести в алфавітному порядку усі країни, що фігурують в адресах клієнтів, 
-- працівників, та місцях доставки замовлень.
SELECT Country FROM customers UNION 
SELECT Country FROM employees UNION 
SELECT ShipCountry AS Country FROM orders 
ORDER BY Country;

-- 3. Вивести прізвище та ім’я працівника, а також кількість замовлень, що він обробив 
-- за перший квартал 1998 року.
SELECT LastName, FirstName, COUNT(OrderDate) 
FROM employees INNER JOIN orders ON employees.EmployeeID = orders.EmployeeID 
WHERE YEAR(OrderDate)=1998 AND MONTH(OrderDate) BETWEEN 1 AND 3 
GROUP BY orders.EmployeeID;


-- 4. Використовуючи СTE знайти усі замовлення, в які входять продукти, яких на складі 
-- більше 100 одиниць, проте по яким немає максимальних знижок.
WITH Products_CTE AS (
	SELECT * FROM orders WHERE  OrderID IN (
		SELECT OrderID FROM `order details` WHERE Discount NOT IN 
			(SELECT MAX(Discount) FROM `order details`) 
		AND ProductId IN 
			(SELECT ProductId FROM products WHERE UnitsInStock > 100)
		)
	)
SELECT * FROM Products_CTE;

-- 5. Знайти назви усіх продуктів, що не продаються в південному регіоні.
SELECT products.ProductName, suppliers.City FROM products INNER JOIN suppliers ON products.SupplierID = suppliers.SupplierID 
WHERE suppliers.City NOT IN 
	(SELECT TerritoryDescription FROM territories WHERE RegionID=4);

																						