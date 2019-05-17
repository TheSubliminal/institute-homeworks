-- 1. Створити базу даних «LazyStudent» підприємства, що займається допомогою
-- студентам ВУЗів з пошуком репетиторів, проходженням практики та
-- розмовними курсами за кордоном.
-- 2. Самостійно спроектувати структуру бази для виконання на ній наступних
-- завдань.
-- 3. База даних повинна передбачати реєстрацію клієнтів через сайт компанії та
-- збереження їхньої основної інформації. Збереженої інформації повинно бути
-- достатньо для контактів та проведення поштових розсилок.
-- 4. Через сайт компанії може також зареєструватися репетитор, що надає освітні
-- послуги через посередника «LazyStudent». Репетитор має профільні
-- дисципліни (довільна кількість) та рейтинг, що визначається клієнтами, які з
-- ним уже працювали.
-- 5. Компанії, з якими співпрацює підприємство, також мають зберігатися в БД.
-- 6. Співробітники підприємства повинні мати можливість відстежувати замовлення
-- клієнтів та їхній поточний статус. Передбачити можливість побудови звітності (в
-- тому числі і фінансової) в розрізі періоду, клієнта, репетитора/компанії.
-- 7. Передбачити ролі адміністратора, рядового працівника та керівника.
-- Відповідним чином розподілити права доступу.
-- 8. Передбачити історію видалень інформації з БД. Відповідна інформація не
-- повинна відображатися на сайті, але керівник та адміністратор мусять мати
-- можливість переглянути – хто, коли і яку інформацію видалив.
-- 9. Передбачити систему знижок залежно від дати реєстрації клієнта. 1 рік – 5%, 2
-- роки – 8%, 3 роки – 11%, 4 роки – 15%.
-- 10.Передбачити можливість проведення акцій зі знижками на послуги компанійпартнерів
-- залежно від компанії та дати проведення акції.


-- 1. Створити базу даних «LazyStudent» підприємства, що займається допомогою
-- студентам ВУЗів з пошуком репетиторів, проходженням практики та
-- розмовними курсами за кордоном.
-- 2. Самостійно спроектувати структуру бази для виконання на ній наступних
-- завдань.

-- https://dbdesigner.page.link/JisCGmMbcuyrEuDq5
CREATE OR REPLACE DATABASE LazyStudent;
USE LazyStudent;

-- Creating tables for database
CREATE OR REPLACE TABLE UserRoles (UserRole VARCHAR(30) PRIMARY KEY NOT NULL);

-- 3. База даних повинна передбачати реєстрацію клієнтів через сайт компанії та
-- збереження їхньої основної інформації. Збереженої інформації повинно бути
-- достатньо для контактів та проведення поштових розсилок.
CREATE OR REPLACE TABLE Users (UserID INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
                                 UserRole VARCHAR(30) NOT NULL,
                                 CONSTRAINT FK_UserRole FOREIGN KEY (UserRole) REFERENCES UserRoles(UserRole),
                                 FirstName VARCHAR(40) NOT NULL, LastName VARCHAR(40) NOT NULL,
                                 Email VARCHAR(40) NOT NULL, Password VARCHAR(40) NOT NULL,
                                 Phone VARCHAR(40) NOT NULL, RegistrationDate DATE DEFAULT (CURDATE())) ENGINE = INNODB;

CREATE OR REPLACE TABLE Students (StudentID INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
                                  UserID INT NOT NULL,
                                  CONSTRAINT FK_StudentClientID FOREIGN KEY (UserID) REFERENCES Users (UserID)) ENGINE = INNODB;

-- 5. Компанії, з якими співпрацює підприємство, також мають зберігатися в БД.
CREATE OR REPLACE TABLE PartnerCompanies (CompanyID INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
                                          CompanyName VARCHAR(50) UNIQUE NOT NULL);

-- 4. Через сайт компанії може також зареєструватися репетитор, що надає освітні
-- послуги через посередника «LazyStudent». Репетитор має профільні
-- дисципліни (довільна кількість) та рейтинг, що визначається клієнтами, які з
-- ним уже працювали.
CREATE OR REPLACE TABLE Teachers (TeacherID INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
                                  UserID INT NOT NULL,
                                  CompanyID INT NOT NULL,
                                  CONSTRAINT FK_TeacherClientID FOREIGN KEY (UserID) REFERENCES Users (UserID),
                                  CONSTRAINT FK_CompanyID FOREIGN KEY (CompanyID) REFERENCES PartnerCompanies (CompanyID),
                                  Rating FLOAT DEFAULT (0)) ENGINE = INNODB;

CREATE OR REPLACE TABLE Disciplines (Discipline VARCHAR(50) PRIMARY KEY NOT NULL);

CREATE OR REPLACE TABLE Courses (CourseID INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
                                 CourseName VARCHAR(50) NOT NULL,
                                 TeacherID INT NOT NULL,
                                 Discipline VARCHAR(50) NOT NULL,
                                 CONSTRAINT FK_DisciplineTeacherID FOREIGN KEY (TeacherID) REFERENCES Teachers (TeacherID),
                                 CONSTRAINT FK_Discipline FOREIGN KEY (Discipline) REFERENCES Disciplines (Discipline),
                                 CourseDescription TEXT(200))
                                 ENGINE = INNODB;

-- 10.Передбачити можливість проведення акцій зі знижками на послуги компанійпартнерів
-- залежно від компанії та дати проведення акції.
CREATE OR REPLACE TABLE SpecialOffers (OfferID INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
                                       CompanyID INT NOT NULL,
                                       CONSTRAINT FK_OfferCompanyID FOREIGN KEY (CompanyID) REFERENCES PartnerCompanies (CompanyID),
                                       Discount INT NOT NULL, StartDate DATE NOT NULL,
                                       EndDate DATE NOT NULL)
                                       ENGINE = INNODB;

CREATE OR REPLACE TABLE Orders (OrderID INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
                                CourseID INT NOT NULL,
                                CONSTRAINT FK_CourseID FOREIGN KEY (CourseID) REFERENCES Courses (CourseID),
                                StudentID INT NOT NULL,
                                CONSTRAINT FK_CourseStudentID FOREIGN KEY (StudentID) REFERENCES Students (StudentID),
                                StartDate DATE NOT NULL, EndDate DATE NOT NULL, Cost DECIMAL,
                                Grade FLOAT, Rating FLOAT) ENGINE = INNODB;

-- 8. Передбачити історію видалень інформації з БД. Відповідна інформація не
-- повинна відображатися на сайті, але керівник та адміністратор мусять мати
-- можливість переглянути – хто, коли і яку інформацію видалив.

-- UserRoles Archive
CREATE TABLE IF NOT EXISTS UserRolesArchive LIKE UserRoles;
ALTER TABLE UserRolesArchive ADD (DeletionDateTime DATETIME, DeletedBy VARCHAR(20));

CREATE TRIGGER IF NOT EXISTS insert_into_user_roles_archive
BEFORE DELETE ON UserRoles
FOR EACH ROW
INSERT INTO UserRolesArchive VALUES (OLD.UserRole,  NOW(), CURRENT_USER());

-- Clients Archive
CREATE TABLE IF NOT EXISTS UsersArchive LIKE Users;
ALTER TABLE UsersArchive ADD (DeletionDateTime DATETIME, DeletedBy VARCHAR(20));

CREATE TRIGGER IF NOT EXISTS insert_into_users_archive
BEFORE DELETE ON Users
FOR EACH ROW
INSERT INTO UsersArchive VALUES (OLD.UserID, OLD.UserRole, OLD.FirstName, OLD.LastName,
                                   OLD.Email, OLD.Password, OLD.Phone ,OLD.RegistrationDate, NOW(), CURRENT_USER());

-- Students Archive
CREATE TABLE IF NOT EXISTS StudentsArchive LIKE Students;
ALTER TABLE StudentsArchive ADD (DeletionDateTime DATETIME, DeletedBy VARCHAR(20));

CREATE TRIGGER IF NOT EXISTS insert_into_students_archive
BEFORE DELETE ON Students
FOR EACH ROW
INSERT INTO StudentsArchive VALUES (OLD.StudentID, OLD.UserID, NOW(), CURRENT_USER());

-- Teachers Archive
CREATE TABLE IF NOT EXISTS TeachersArchive LIKE Teachers;
ALTER TABLE TeachersArchive ADD (DeletionDateTime DATETIME, DeletedBy VARCHAR(20));

CREATE TRIGGER IF NOT EXISTS insert_into_teachers_archive
BEFORE DELETE ON Teachers
FOR EACH ROW
INSERT INTO TeachersArchive VALUES (OLD.TeacherID, OLD.UserID, OLD.CompanyID, OLD.Rating, NOW(), CURRENT_USER());

-- TeacherDisciplines Archive
CREATE TABLE IF NOT EXISTS CoursesArchive LIKE Courses;
ALTER TABLE CoursesArchive ADD (DeletionDateTime DATETIME, DeletedBy VARCHAR(20));

CREATE TRIGGER IF NOT EXISTS insert_into_courses_archive
BEFORE DELETE ON Courses
FOR EACH ROW
INSERT INTO CoursesArchive VALUES (OLD.CourseID, OLD.CourseName, OLD.TeacherID, OLD.Discipline, OLD.CourseDescription, NOW(), CURRENT_USER());

-- Disciplines Archive
CREATE TABLE IF NOT EXISTS DisciplinesArchive LIKE Disciplines;
ALTER TABLE DisciplinesArchive ADD (DeletionDateTime DATETIME, DeletedBy VARCHAR(20));

CREATE TRIGGER IF NOT EXISTS insert_into_disciplines_archive
BEFORE DELETE ON Disciplines
FOR EACH ROW
INSERT INTO DisciplinesArchive VALUES (OLD.Discipline, NOW(), CURRENT_USER());

-- Partner Companies Archive
CREATE TABLE IF NOT EXISTS PartnerCompaniesArchive LIKE PartnerCompanies;
ALTER TABLE PartnerCompaniesArchive ADD (DeletionDateTime DATETIME, DeletedBy VARCHAR(20));

CREATE TRIGGER IF NOT EXISTS insert_into_partnercompanies_archive
BEFORE DELETE ON PartnerCompanies
FOR EACH ROW
INSERT INTO PartnerCompaniesArchive VALUES (OLD.CompanyID, OLD.CompanyName, NOW(), CURRENT_USER());

-- Special Offers Archive
CREATE TABLE IF NOT EXISTS SpecialOffersArchive LIKE SpecialOffers;
ALTER TABLE SpecialOffersArchive ADD (DeletionDateTime DATETIME, DeletedBy VARCHAR(20));

CREATE TRIGGER IF NOT EXISTS insert_into_specialoffers_archive
BEFORE DELETE ON SpecialOffers
FOR EACH ROW
INSERT INTO SpecialOffersArchive VALUES (OLD.OfferID, OLD.CompanyID, OLD.Discount, OLD.StartDate, OLD.EndDate, NOW(), CURRENT_USER());

-- Courses Archive
CREATE TABLE IF NOT EXISTS OrdersArchive LIKE Orders;
ALTER TABLE OrdersArchive ADD (DeletionDateTime DATETIME, DeletedBy VARCHAR(20));

CREATE TRIGGER IF NOT EXISTS insert_into_orders_archive
BEFORE DELETE ON Orders
FOR EACH ROW
INSERT INTO OrdersArchive VALUES (OLD.OrderID, OLD.CourseID, OLD.StudentID, OLD.StartDate,
                                   OLD.EndDate, OLD.Cost, OLD.Grade, OLD.Rating, NOW(), CURRENT_USER());

-- Creating triggers before inserting any data

-- Add student to the table Students when the user with the student roles is inserted into the Clients table
CREATE OR REPLACE TRIGGER AddStudent
    AFTER INSERT ON Users
    FOR EACH ROW
IF NEW.UserRole='Student'
    THEN INSERT INTO Students (UserID) VALUES (NEW.UserID);
END IF;

-- Recalculate teacher's rating on adding new course
CREATE OR REPLACE TRIGGER CountRating
    AFTER INSERT ON Orders
    FOR EACH ROW
BEGIN
    SET @NumOfOrders = (SELECT COUNT(*) FROM Orders WHERE CourseID IN
                              (SELECT CourseID FROM Courses WHERE TeacherID IN
                                      (SELECT TeacherID FROM Courses WHERE CourseID=NEW.CourseID)));
    UPDATE Teachers
        SET Teachers.Rating = (Teachers.Rating + NEW.Rating)/@NumOfCourses
    WHERE TeacherID IN (SELECT TeacherID FROM Courses WHERE CourseID=NEW.CourseID);
END;

-- 9. Передбачити систему знижок залежно від дати реєстрації клієнта. 1 рік – 5%, 2
-- роки – 8%, 3 роки – 11%, 4 роки – 15%.
DELIMITER //

CREATE OR REPLACE TRIGGER CountCost
    BEFORE INSERT ON Orders
    FOR EACH ROW
BEGIN
    SET @DateDisc = 0;
    SET @CompanyDisc = 0;
    SET @RegDate = (SELECT RegistrationDate FROM Users WHERE UserID IN (
        SELECT UserID FROM Students WHERE StudentID=NEW.StudentID));
    CASE
        WHEN TIMESTAMPDIFF(YEAR, @RegDate, CURDATE())=1 THEN SET @DateDisc = 5;
        WHEN TIMESTAMPDIFF(YEAR, @RegDate, CURDATE())=2 THEN SET @DateDisc = 8;
        WHEN TIMESTAMPDIFF(YEAR, @RegDate, CURDATE())=3 THEN SET @DateDisc = 11;
        WHEN TIMESTAMPDIFF(YEAR, @RegDate, CURDATE())>=4 THEN SET @DateDisc = 15;
        ELSE SET @DateDisc = 0;
    END CASE;

    SET @TeacherId = (SELECT TeacherID FROM Courses WHERE CourseID=NEW.CourseID);

    IF @TeacherId IN (SELECT TeacherID FROM Teachers INNER JOIN SpecialOffers
        ON Teachers.CompanyID=SpecialOffers.CompanyID
        WHERE SpecialOffers.StartDate < CURDATE() AND SpecialOffers.EndDate > CURDATE())

        THEN SET @CompanyDisc = (SELECT DISTINCT Discount FROM Teachers INNER JOIN SpecialOffers
        ON Teachers.CompanyID=SpecialOffers.CompanyID
        WHERE SpecialOffers.StartDate < CURDATE() AND SpecialOffers.EndDate > CURDATE());

    END IF;
    SET NEW.Cost = NEW.Cost - (NEW.Cost)*(@DateDisc + @CompanyDisc)/100;
END; //

DELIMITER ;

-- 6. Співробітники підприємства повинні мати можливість відстежувати замовлення
-- клієнтів та їхній поточний статус. Передбачити можливість побудови звітності (в
-- тому числі і фінансової) в розрізі періоду, клієнта, репетитора/компанії.

-- Period reports
DELIMITER //

CREATE PROCEDURE CoursesForPeriod(IN periodstart DATE, IN periodend DATE)
    BEGIN
        SELECT * FROM Orders WHERE StartDate > periodstart AND EndDate < periodend;
    END;
//

DELIMITER ;

DELIMITER //

CREATE PROCEDURE IncomeForPeriod(IN periodstart DATE, IN periodend DATE)
    BEGIN
        SELECT SUM(Cost) FROM Orders WHERE StartDate > periodstart AND EndDate < periodend;
    END;
//

DELIMITER ;

-- Student reports
DELIMITER //

CREATE PROCEDURE CoursesForStudent(IN StudentFirstName VARCHAR(40), IN StudentLastName VARCHAR(40))
    BEGIN
        SELECT * FROM Orders WHERE StudentID IN (
            SELECT StudentID FROM Students WHERE UserID IN(
                SELECT UserID FROM Users WHERE FirstName=StudentFirstName AND LastName=StudentLastName));
    END;
//

DELIMITER ;

DELIMITER //

CREATE PROCEDURE IncomeForStudent(IN StudentFirstName VARCHAR(40), IN StudentLastName VARCHAR(40))
    BEGIN
        SELECT SUM(Cost) FROM Orders WHERE StudentID IN (
            SELECT StudentID FROM Students WHERE UserID IN(
                SELECT UserID FROM Users WHERE FirstName=StudentFirstName AND LastName=StudentLastName));
    END;
//

DELIMITER ;

-- Teacher reports
DELIMITER //

CREATE PROCEDURE OrdersForTeacher(IN TeacherFirstName VARCHAR(40), IN TeacherLastName VARCHAR(40))
    BEGIN
        SELECT * FROM Orders WHERE CourseID IN (
            SELECT CourseID FROM Courses WHERE TeacherID IN(
                SELECT TeacherID FROM Teachers WHERE UserID IN(
                    SELECT UserID FROM Users WHERE FirstName=TeacherFirstName AND LastName=TeacherLastName)));
    END;
//

DELIMITER ;

DELIMITER //

CREATE PROCEDURE IncomeForTeacher(IN TeacherFirstName VARCHAR(40), IN TeacherLastName VARCHAR(40))
    BEGIN
        SELECT SUM(Cost) FROM Orders WHERE CourseID IN (
            SELECT CourseID FROM Courses WHERE TeacherID IN(
                SELECT TeacherID FROM Teachers WHERE UserID IN(
                    SELECT UserID FROM Users WHERE FirstName=TeacherFirstName AND LastName=TeacherLastName)));
    END;
//

DELIMITER ;

-- Company reports
DELIMITER //

CREATE PROCEDURE CoursesForCompany(IN Company_Name VARCHAR(50))
    BEGIN
        SELECT * FROM Orders WHERE CourseID IN (
            SELECT CourseID FROM Courses WHERE TeacherID IN(
                SELECT TeacherID FROM Teachers WHERE CompanyID IN(
                    SELECT CompanyID FROM PartnerCompanies WHERE CompanyName=Company_Name)));
    END;
//

DELIMITER ;

DELIMITER //

CREATE PROCEDURE IncomeForCompany(IN Company_Name VARCHAR(50))
    BEGIN
        SELECT SUM(Cost) FROM Orders WHERE CourseID IN (
            SELECT CourseID FROM Courses WHERE TeacherID IN(
                SELECT TeacherID FROM Teachers WHERE CompanyID IN(
                    SELECT CompanyID FROM PartnerCompanies WHERE CompanyName=Company_Name)));
    END;
//

DELIMITER ;

-- 7. Передбачити ролі адміністратора, рядового працівника та керівника.
-- Відповідним чином розподілити права доступу.

CREATE OR REPLACE ROLE administrator;
GRANT ALL PRIVILEGES ON LazyStudent.* TO administrator;

CREATE OR REPLACE ROLE manager;
GRANT SELECT, INSERT, UPDATE, DELETE ON LazyStudent.* TO manager;

CREATE OR REPLACE ROLE employee;
GRANT SELECT ON LazyStudent.* TO employee;

-- Inserting data in the tables
INSERT INTO UserRoles (UserRole) VALUES ('Student'), ('Teacher');
INSERT INTO Users (UserRole, FirstName, LastName, Email, Password, Phone) VALUES
    ('Student', 'John', 'Jenkins', 'jen@gmail.com', 'password123', '+121 345 654'),
    ('Student', 'Jake', 'Stephens', 'steph@gmail.com', 'pass2134', '+123 742 426'),
    ('Student', 'James', 'Anders', 'jam.and@gmail.com', 'pass6422', '+380 64 238 94 16'),
    ('Student', 'Jake', 'Stevens', 'jak@yahoo.com', 'bdfg223svhW', '+123 523 222'),
    ('Student', 'Josh', 'Miller', 'jo.miller21@gmail.com', '4#fgn%ggfE', '+124 432 111'),
    ('Teacher', 'Jeff', 'Jameson', 'jam.jeff@gmail.com', 'mgn234o5icv7', '+127 543 225'),
    ('Teacher', 'Rob', 'Burden', 'rob.burd@gmail.com', 'fgd45kvioiw', '+124 234 532'),
    ('Teacher', 'Fred', 'Roberts', 'fred.robertson22@gmail.com', '46ivbm4mn8v8', '+120 555 644'),
    ('Teacher', 'Bob', 'Stanley', 'bob.stan@gmail.com', '656kksk434gg', '+127 634 663'),
    ('Teacher', 'Dan', 'Donaldson', 'dan.donaldson52@gmail.com', 'n;oeG436^ee', '+123 543 345');
INSERT INTO PartnerCompanies (CompanyName) VALUES ('TeacherOnline'), ('TutorForU'), ('Improve Yourself');
INSERT INTO Teachers (UserID, CompanyID) VALUES (6, 1), (7, 2), (8, 1), (9, 3), (10, 3);
INSERT INTO Disciplines (Discipline) VALUES ('Phisics'), ('English'), ('History'), ('Linear Algebra'),
                                            ('Theory of Probabilities'), ('Programming Basics'), ('Algorithms'),
                                            ('Philosophy'), ('Organic Chemistry'), ('Electronics'), ('Discrete Maths'),
                                            ('Psychology'), ('Calculus');
INSERT INTO Courses (CourseName, TeacherID, Discipline, CourseDescription) VALUES
          ('Introduction To Phisics', 1, 'Phisics', 'Course on phisics fundamentals'),
          ('Introduction To Linear Algebra', 1, 'Linear Algebra', 'Course on linear algebra fundamentals'),
          ('Introduction To Calculus', 1, 'Calculus', 'Course on calculus fundamentals'),
          ('American Literature', 2, 'English', 'Course about famous american writers'),
          ('Python for beginners', 3, 'Programming Basics', 'Fundamentals of Python 3'),
          ('Simple electronics with Arduino', 3, 'Electronics', 'Starter course about Arduino'),
          ('Antique philosophy' ,4, 'Philosophy', 'Course about antique philosopher schools'),
          ('Ancient history', 4, 'History', 'Course on BC period of history'),
          ('Discrete Maths. Part 1',5, 'Discrete Maths', 'First part of discrete maths course'),
          ('Sorting algorithms', 5, 'Algorithms', 'Overview of the most popular sorting algorithms and their principles'),
          ('Calculus. Part 2', 5, 'Calculus', 'Part 2 of calculus course for university students');
INSERT INTO Orders (CourseID, StudentID, StartDate, EndDate, Cost, Grade, Rating) VALUES
        (1, 1, '2018-02-04', '2018-03-04', 12, 5, 5),
        (2, 1, '2018-05-06', '2018-06-06', 12, 5, 3);
INSERT INTO SpecialOffers (CompanyID, Discount, StartDate, EndDate) VALUES (1, 10, '2019-04-01', '2019-04-14'),
                                                                           (2, 15, '2018-04-01', '2018-04-14');

