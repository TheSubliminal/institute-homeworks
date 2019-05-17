DELIMITER //

CREATE PROCEDURE `Ten Most Expensive Products`()
  BEGIN
    SELECT Products.ProductName AS TenMostExpensiveProducts, Products.UnitPrice
    FROM Products
    ORDER BY Products.UnitPrice DESC
    LIMIT 10;
  END;

//

DELIMITER ;

CALL `Ten Most Expensive Products`();