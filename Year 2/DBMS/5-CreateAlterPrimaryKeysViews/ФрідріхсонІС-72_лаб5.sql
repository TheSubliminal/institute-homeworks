-- 1. Створити базу даних з іменем, яке відповідає вашому прізвищу англійською мовою.
CREATE DATABASE IF NOT EXISTS fridrikhson;
USE fridrikhson;

-- 2. Створити в новій базі таблицю Student з атрибутами StudentId, SecondName, FirstName, Sex.
-- Обрати для них оптимальний тип даних в вашій СУБД.
CREATE TABLE IF NOT EXISTS Student (StudentID INT NOT NULL,
                                    SecondName VARCHAR(50) NOT NULL,
                                    FirstName VARCHAR(50) NOT NULL,
                                    Sex CHAR(1) NOT NULL );

-- 3. Модифікувати таблицю Student. Атрибут StudentId має стати первинним ключем.
ALTER TABLE student ADD PRIMARY KEY(StudentID);

-- 4. Модифікувати таблицю Student. Атрибут StudentId повинен заповнюватися автоматично починаючи з 1 і з кроком в 1.
ALTER TABLE student MODIFY StudentID INT AUTO_INCREMENT;

-- 5. Модифікувати таблицю Student. Додати необов’язковий атрибут BirthDate з відповідним типом даних.
ALTER TABLE student ADD BirthDate DATE NULL;

-- 6. Модифікувати таблицю Student. Додати атрибут CurrentAge, що генерується
-- автоматично на базі існуючих в таблиці даних.
ALTER TABLE student ADD CurrentAge SMALLINT UNSIGNED DEFAULT(DATEDIFF(CURDATE(), BirthDate) DIV 365);

-- 7. Реалізувати перевірку вставлення даних. Значення атрибуту Sex може бути тільки «m» або «f».
ALTER TABLE student ADD CHECK(Sex IN ('f', 'm'));

-- 8. В таблицю Student додати себе та двох «сусідів» у списку групи.
INSERT INTO student (SecondName, FirstName, Sex, BirthDate)
VALUES ('Fridrikhson', 'Michael', 'm', '2000-01-17'),
       ('Tkachenko', 'Egor', 'm', '2000-06-12'),
       ('Khovanova', 'Margarita', 'f', '2000-04-24');

-- 9. Створити представлення vMaleStudent та vFemaleStudent, що надають відповідну інформацію.
CREATE VIEW vMaleStudent AS SELECT * FROM student WHERE Sex='m';
CREATE VIEW vFemaleStudent AS SELECT * FROM student WHERE Sex='f';

-- 10. Змінити тип даних первинного ключа на TinyInt (або SmallInt), не втрачаючи дані.
ALTER TABLE student MODIFY StudentID SMALLINT AUTO_INCREMENT;