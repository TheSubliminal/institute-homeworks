-- 1. Вивести на екран імена усіх таблиць в базі даних та кількість рядків в них.
SELECT TABLE_NAME, TABLE_ROWS
FROM INFORMATION_SCHEMA.TABLES
WHERE TABLE_SCHEMA='northwind' AND NOT TABLE_COMMENT='VIEW';
-- 2. Видати дозвіл на читання бази даних Northwind усім користувачам вашої СУБД.
-- Код повинен працювати незалежно від наявних імен існуючих користувачів.
CREATE USER IF NOT EXISTS 'TestUser'@'localhost' IDENTIFIED BY 'pruvet17kek';

DELIMITER //

CREATE OR REPLACE PROCEDURE UserPrivileges()
BEGIN
  DECLARE done INT DEFAULT FALSE;
  DECLARE host_var CHAR(60);
  DECLARE user_var CHAR(80);
  DECLARE users_cur CURSOR FOR SELECT user, host FROM mysql.user;
  DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;

  OPEN users_cur;

  read_loop: LOOP
    FETCH users_cur INTO user_var, host_var;
    IF done THEN
      LEAVE read_loop;
    END IF;

    SET @SQL := CONCAT("GRANT SELECT ON northwind.* TO ", user_var, '@', host_var);
    PREPARE apply_privs FROM @SQL;
    EXECUTE apply_privs;
    FLUSH PRIVILEGES;
    DEALLOCATE PREPARE apply_privs;

  END LOOP;

  CLOSE users_cur;

END; //

DELIMITER ;

CALL UserPrivileges();

-- 3. За допомогою курсору заборонити користувачеві TestUser доступ до всіх таблиць
-- поточної бази даних, імена котрих починаються на префікс ‘prod_’.
GRANT ALL PRIVILEGES ON northwind.prod_test TO TestUser@localhost;

DELIMITER //

CREATE OR REPLACE PROCEDURE UserPrivilegeDeny()
BEGIN
  DECLARE done INT DEFAULT FALSE;
  DECLARE table_var VARCHAR(64);

  DECLARE table_cur CURSOR FOR SELECT TABLE_NAME
  FROM INFORMATION_SCHEMA.TABLES
  WHERE TABLE_SCHEMA='northwind' AND NOT TABLE_COMMENT='VIEW' AND TABLE_NAME RLIKE '^prod_';

  DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = TRUE;

  OPEN table_cur;

  read_loop: LOOP
    FETCH table_cur INTO table_var;
    IF done THEN
      LEAVE read_loop;
    END IF;

    SET @SQL := CONCAT("REVOKE ALL PRIVILEGES ON northwind.", table_var, " FROM TestUser@localhost"); -- No DENY in MariaDB
    PREPARE revoke_privs FROM @SQL;
    EXECUTE revoke_privs;
    FLUSH PRIVILEGES;
    DEALLOCATE PREPARE revoke_privs;

  END LOOP;

  CLOSE table_cur;

END; //

DELIMITER ;

CALL UserPrivilegeDeny();

-- 4. Створити тригер на таблиці Customers, який при вставці нового телефонного номеру
-- буде видаляти усі символи, крім цифр.
CREATE TRIGGER IF NOT EXISTS fix_number
BEFORE INSERT ON customers
FOR EACH ROW
SET NEW.Phone = REGEXP_REPLACE(NEW.Phone, '[^0-9]', '');

-- 5. Створити таблицю Contacts (ContactId, LastName, FirstName, PersonalPhone, WorkPhone,
-- Email, PreferableNumber). Створити тригер, який при вставці даних в таблицю Contacts вставить
-- в якості PreferableNumber WorkPhone, якщо такий є, або PersonalPhone, якщо робочий номер телефона не вказано.
CREATE TABLE IF NOT EXISTS Contacts (ContactId SMALLINT AUTO_INCREMENT PRIMARY KEY,
LastName VARCHAR(20), FirstName VARCHAR(20), PersonalPhone VARCHAR(20), WorkPhone VARCHAR(20),
Email VARCHAR(20), PreferableNumber VARCHAR(20));

CREATE TRIGGER IF NOT EXISTS insert_prefnumber
BEFORE INSERT ON Contacts
FOR EACH ROW
SET NEW.PreferableNumber=IFNULL(NEW.WorkPhone, NEW.PersonalPhone);

-- 6. Створити таблицю OrdersArchive, що дублює таблицію Orders та має додаткові атрибути
-- DeletionDateTime та DeletedBy. Створити тригер, який при видаленні рядків з таблиці Orders буде
-- додавати їх в таблицю OrdersArchive та заповнювати відповідні колонки.
CREATE TABLE IF NOT EXISTS OrdersArchive LIKE orders;
ALTER TABLE OrdersArchive ADD (DeletionDateTime DATETIME, DeletedBy VARCHAR(20));

CREATE TRIGGER IF NOT EXISTS insert_into_archive
BEFORE DELETE ON orders
FOR EACH ROW
INSERT INTO OrdersArchive VALUES (OLD.OrderID, OLD.CustomerID, OLD.EmployeeID, OLD.OrderDate,
OLD.RequiredDate, OLD.ShippedDate, OLD.ShipVia, OLD.Freight, OLD.ShipName, OLD.ShipAddress, OLD.ShipCity,
OLD.ShipRegion, OLD.ShipPostalCode, OLD.ShipCountry, NOW(), CURRENT_USER());

-- 7. Створити три таблиці: TriggerTable1, TriggerTable2 та TriggerTable3. Кожна з таблиць
-- має наступну структуру: TriggerId(int) – первинний ключ з автоінкрементом, TriggerDate(Date).
-- Створити три тригери. Перший тригер повинен при будь-якому записі в таблицю TriggerTable1 додати
-- дату запису в таблицю TriggerTable2. Другий тригер повинен при будь-якому записі в таблицю TriggerTable2
-- додати дату запису в таблицю TriggerTable3. Третій тригер працює аналогічно з таблицями TriggerTable3
-- та TriggerTable1. Вставте один рядок в таблицю TriggerTable1. Опишіть, що сталося, в коментарі до коду.
-- Чому це сталося?
CREATE TABLE IF NOT EXISTS TriggerTable1 (TriggerId INT PRIMARY KEY AUTO_INCREMENT, TriggerDate DATE);
CREATE TABLE IF NOT EXISTS TriggerTable2 (TriggerId INT PRIMARY KEY AUTO_INCREMENT, TriggerDate DATE);
CREATE TABLE IF NOT EXISTS TriggerTable3 (TriggerId INT PRIMARY KEY AUTO_INCREMENT, TriggerDate DATE);

CREATE TRIGGER IF NOT EXISTS add_date_to_2
BEFORE INSERT ON TriggerTable1
FOR EACH ROW
INSERT INTO TriggerTable2 (TriggerDate) VALUES (CURDATE());

CREATE TRIGGER IF NOT EXISTS add_date_to_3
BEFORE INSERT ON TriggerTable2
FOR EACH ROW
INSERT INTO TriggerTable3 (TriggerDate) VALUES (CURDATE());

CREATE TRIGGER IF NOT EXISTS add_date_to_1
BEFORE INSERT ON TriggerTable3
FOR EACH ROW
INSERT INTO TriggerTable1 (TriggerDate) VALUES (CURDATE());

-- Отримано помилку:
-- Can't update table 'triggertable1' in stored function/trigger because it is already used by statement
-- which invoked this stored function/trigger.
-- Дана помилка виникає, через те, що в таблиці відбувся запис данних, який викликав запис даних у цю ж таблицю.
-- Зтригерену операцію запису було заблоковано. Це запобігає нескінченному зацикленню наступних операцій.



