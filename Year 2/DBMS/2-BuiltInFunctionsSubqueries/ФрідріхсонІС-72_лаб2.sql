-- *********** ЗАДАЧА 1 ***********

-- 1. Необхідно знайти кількість рядків в таблиці, що містить більше ніж 2147483647 записів. 
-- Напишіть код для MS SQL Server та ще однієї СУБД (на власний вибір).

-- SELECT COUNT_BIG(*) FROM Table; (MS SQL Server)
SELECT COUNT(*) FROM categories; -- Повертає за замовченням значення BIGINT

-- 2. Підрахувати довжину свого прізвища за допомогою SQL.
SELECT CHAR_LENGTH('Fridrikhson');

-- 3. У рядку з своїм прізвищем, іменем, та по-батькові замінити пробіли на знак ‘_’ (нижнє підкреслення).
SELECT REPLACE('Fridrikhson Mykhailo Anatoliyovich', ' ', '_');

-- 4. Створити генератор імені електронної поштової скриньки, що шляхом конкатенації об’єднував би дві 
-- перші літери з колонки імені, та чотири перші літери з колонки прізвища користувача, що зберігаються 
-- в базі даних, а також домену з вашим прізвищем.
-- CREATE TABLE IF NOT EXISTS people (id MEDIUMINT NOT NULL AUTO_INCREMENT, name VARCHAR(20), surname VARCHAR(20), birth DATE, PRIMARY KEY(id));
-- INSERT INTO people (name, surname, birth) VALUES ('Michael', 'Fridrikhson', '2000-01-17'), ('Elon', 'Musk', '1971-06-28');
SELECT CONCAT(SUBSTRING(name, 1, 2), SUBSTRING(surname, 1, 4), '@', LOWER(surname), '.com') FROM people WHERE id=1;

-- 5. За допомогою SQL визначити, в який день тиждня ви народилися.
SELECT DAYNAME(birth) FROM people WHERE id=1;

-- *********** ЗАДАЧА 2 ***********

-- 1. Вивести усі данні по продуктам, їх категоріям, та постачальникам, навіть якщо останні з певних 
-- причин відсутні
SELECT * FROM (products LEFT JOIN categories 
	ON products.CategoryID=categories.CategoryID) RIGHT JOIN suppliers 
		ON (products.SupplierID=suppliers.SupplierID);

-- 2. Показати усі замовлення, що були зроблені в квітні 1988 року та не були відправлені.
SELECT * FROM orders WHERE YEAR(OrderDate)=1998 AND MONTH(OrderDate)=3 AND ISNULL(ShippedDate);

-- 3. Відібрати усіх працівників, що відповідають за північний регіон.
-- INSERT INTO employees (LastName, FirstName, City, Notes) VALUES ('Lennon', 'John', 'Findlay', 'blah blah');
SELECT FirstName, LastName 
FROM employees
WHERE City IN (
	SELECT TerritoryDescription 
	FROM territories 
	WHERE RegionID=3
);

-- 4. Вирахувати загальну вартість з урахуванням знижки усіх замовлень, що були здійснені на непарну дату.
SELECT SUM((UnitPrice*Quantity) - ((UnitPrice*Quantity)/100)*Discount) AS TotalPrice 
FROM `order details` 
WHERE OrderID IN (
	SELECT OrderID 
	FROM orders 
	WHERE NOT DAYOFMONTH(OrderDate)%2=0
);

-- 5. Знайти адресу відправлення замовлення з найбільшою ціною (враховуючи усі позиції замовлення, 
-- їх вартість, кількість, та наявність знижки).
SELECT OrderID, ShipAddress 
FROM orders 
WHERE OrderID IN (
	SELECT OrderID
	FROM `order details`
	WHERE (UnitPrice*Quantity) - ((UnitPrice*Quantity)/100)*Discount IN (
		SELECT MAX((UnitPrice*Quantity) - ((UnitPrice*Quantity)/100)*Discount)
		FROM `order details`
	)
);
