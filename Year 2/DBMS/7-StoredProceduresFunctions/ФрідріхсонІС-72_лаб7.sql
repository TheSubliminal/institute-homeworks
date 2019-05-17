USE northwind;
-- 1. Створити збережену процедуру, що при виклику буде повертати ваше
-- прізвище, ім’я та по-батькові.
DELIMITER //

CREATE OR REPLACE PROCEDURE PrintName(OUT name CHAR(34))
  BEGIN
    SELECT 'Fridrikhson Mykhailo Anatoliyovych' INTO name;
  END;
//

DELIMITER ;

CALL PrintName(@myname);
SELECT @myname AS "Full Name";

-- 2. В контексті бази Northwind створити збережену процедуру, що приймає
-- текстовий параметр мінімальної довжини. При виклику процедури з
-- параметром «F» на екран виводяться усі співробітники-жінки, а для параметра
-- «M» – чоловіки. У протилежному випадку вивести на екран повідомлення про
-- те, що параметр не розпізнано.
DELIMITER //

CREATE OR REPLACE PROCEDURE PrintGender(IN gender CHAR)
  BEGIN
    IF gender="F"
      THEN SELECT FirstName, LastName FROM employees WHERE TitleOfCourtesy="Ms." OR TitleOfCourtesy="Mrs.";
    ELSEIF gender="M"
      THEN SELECT FirstName, LastName FROM employees WHERE TitleOfCourtesy="Mr.";
    ELSE
      SELECT "Unknown parameter value" AS Error;
    END IF;
  END;
//

DELIMITER ;

CALL PrintGender("F");

-- 3. В контексті бази Northwind створити збережену процедуру, що виводить усі
-- замовлення за заданий період. Якщо період не задано – вивести замовлення за
-- поточний день.
DELIMITER //

CREATE OR REPLACE PROCEDURE OrdersForPeriod(IN periodstart DATE, IN periodend DATE)
  BEGIN
    IF periodstart IS NULL OR periodend IS NULL
      THEN SELECT OrderID, ShipName, OrderDate FROM orders WHERE OrderDate=CURDATE();
    ELSE
      SELECT OrderID, ShipName, OrderDate FROM orders WHERE OrderDate BETWEEN periodstart AND periodend;
    END IF;
  END;
//

DELIMITER ;

CALL OrdersForPeriod("1996-07-04", "1996-07-10");

-- 4. В контексті бази Northwind створити збережену процедуру, що залежно від
-- переданого параметру категорії виводить категорію та перелік усіх продуктів за
-- цією категорією. Дозволити використання від однієї до п’яти категорій.
DELIMITER //

CREATE OR REPLACE PROCEDURE ProductsForCategory(IN category_id1 INT, IN category_id2 INT, IN category_id3 INT, IN category_id4 INT, IN category_id5 INT)
  BEGIN
    SELECT SelectedCategories.CategoryID, CategoryName, ProductName
    FROM (SELECT CategoryID, CategoryName FROM categories WHERE CategoryID=category_id1 OR CategoryID=category_id2
      OR CategoryID=category_id3 OR CategoryID=category_id4 OR CategoryID=category_id5) AS SelectedCategories
    INNER JOIN
    products ON SelectedCategories.CategoryID = products.CategoryID;
  END;
//

DELIMITER ;

CALL ProductsForCategory(1, 2, 3, 4, 5);
CALL ProductsForCategory(1, NULL, NULL, NULL, NULL);

-- 5. В контексті бази Northwind модифікувати збережену процедуру Ten Most
-- Expensive Products для виводу всієї інформації з таблиці продуктів, а також імен
-- постачальників та назви категорій.
DROP PROCEDURE `Ten Most Expensive Products`;

DELIMITER //

CREATE PROCEDURE `Ten Most Expensive Products`()
  BEGIN
    SELECT * FROM products;
    SELECT ContactName FROM suppliers;
    SELECT CategoryName FROM categories;
  END;
//

DELIMITER ;

CALL `Ten Most Expensive Products`();

-- 6. В контексті бази Northwind створити функцію, що приймає три параметри
-- (TitleOfCourtesy, FirstName, LastName) та виводить їх єдиним текстом.
-- Приклад: «Dr.», «Yevhen», «Nedashkivskyi» –> «Dr. Yevhen Nedashkivskyi».
DELIMITER //

CREATE OR REPLACE FUNCTION FullName(TitleOfCourtesy VARCHAR(5), FirstName VARCHAR(20), LastName VARCHAR(20)) RETURNS VARCHAR(30)
  BEGIN
    RETURN(SELECT CONCAT(TitleOfCourtesy, ' ', FirstName, ' ', LastName));
  END;

//
DELIMITER ;

SELECT FullName('Mr.', 'Michael', 'Fridrikhson') AS FullName;

-- 7. В контексті бази Northwind створити функцію, що приймає три параметри
-- (UnitPrice, Quantity, Discount) та виводить кінцеву ціну.
DELIMITER //

CREATE OR REPLACE FUNCTION CountPrice(UnitPrice DECIMAL, Quantity INT, Discount DECIMAL) RETURNS FLOAT
  BEGIN
    RETURN(SELECT UnitPrice*Quantity - (UnitPrice*Quantity)*Discount/100);
  END;

//
DELIMITER ;

SELECT CountPrice(UnitPrice, Quantity, Discount) AS Price FROM `order details` LIMIT 10;

-- 8. Створити функцію, що приймає параметр текстового типу і зводить його до
-- Pascal Case. Приклад: «Мій маленький поні» –> «МійМаленькийПоні».
DELIMITER //

CREATE OR REPLACE FUNCTION PascalCasify(str VARCHAR(40)) RETURNS VARCHAR(40)
  BEGIN
    DECLARE result VARCHAR(40) DEFAULT CONCAT(UPPER(SUBSTRING(str, 1, 1)), SUBSTRING(str, 2));
    DECLARE idx INT DEFAULT 1;

    WHILE idx < CHAR_LENGTH(result) DO
      IF STRCMP(SUBSTRING(result, idx, 1), ' ')=0
        THEN SET result = REPLACE(result, SUBSTRING(result, idx, 2), UPPER(SUBSTRING(result, idx + 1, 1)));
        SET idx = idx + 1;
      END IF;
      SET idx = idx + 1;
    END WHILE;
    RETURN(SELECT result);
  END;

//
DELIMITER ;

SELECT PascalCasify('My little pony') AS PascalCase;

-- 9. В контексті бази Northwind створити функцію, яка залежно від вказаної країни
-- повертає усі дані про співробітника у вигляді таблиці.
DELIMITER //
-- Can't return TABLE from stored function in MariaDB
CREATE OR REPLACE PROCEDURE EmployeeByCountry(IN CountryName CHAR(20))
  BEGIN
    SELECT * FROM employees WHERE Country=CountryName;
  END;
//

DELIMITER ;

CALL EmployeeByCountry('USA');

-- 10. В контексті бази Northwind створити функцію, яка залежно від імені
-- транспортної компанії повертає список клієнтів, якою вони обслуговуються.
DELIMITER //
-- Can't return TABLE from stored function in MariaDB
CREATE OR REPLACE PROCEDURE ShipperClients(IN ShipperName CHAR(20))
  BEGIN
    SELECT ContactName FROM customers WHERE CustomerID IN
          (SELECT CustomerID FROM orders WHERE ShipVia IN
                (SELECT ShipperID FROM shippers WHERE CompanyName=ShipperName));
  END;

//
DELIMITER ;

CALL ShipperClients('Speedy Express');
