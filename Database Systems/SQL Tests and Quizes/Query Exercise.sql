#1
SELECT DISTINCT
    e.lastName AS 'Last Name'
FROM
    employees e
ORDER BY e.lastName;

#2
SELECT 
    o.city AS 'City', o.state AS 'State'
FROM
    offices o
WHERE
    o.country = 'USA'
ORDER BY o.postalCode;

#3
SELECT 
    COUNT(c.customerNumber) as 'Foreign Customers with High Credit'
FROM
    customers c
WHERE
    c.country != 'USA'
        AND c.creditLimit > 10000;
        
#4
SELECT 
    c.customerName AS 'Customer Name', c.state AS 'State'
FROM
    customers c
WHERE
    c.state = 'CA' OR c.state = 'MA'
ORDER BY c.state , c.customerName;

#5
SELECT 
    COUNT(c.customerName) AS 'Number of Customers with Mi Contact'
FROM
    customers c
WHERE
    c.contactFirstName LIKE 'Mi%';
    
#6
SELECT 
    CONCAT('$', FORMAT(AVG(c.creditLimit), 2)) AS 'Average Credit Limit'
FROM
    customers c
WHERE
    c.creditLimit > 0;
    
#7
SELECT 
    c.customerName AS 'Name', c.creditLimit AS 'Credit Limit'
FROM
    customers c
WHERE
    c.country = 'USA'
        AND c.creditLimit > (SELECT 
            AVG(creditLimit)
        FROM
            customers
        WHERE
            creditLimit > 0);
            
#8
SELECT DISTINCT
    c.customerName AS 'Name'
FROM
    customers c
        JOIN
    orders o ON c.customerNumber = o.customerNumber;
    
#9
SELECT DISTINCT
    c.customerName AS 'Name'
FROM
    customers c
        JOIN
    orders o ON c.customerNumber = o.customerNumber
        JOIN
    orderdetails od ON o.orderNumber = od.orderNumber
        JOIN
    products p ON od.productCode = p.productCode
WHERE
    p.productName = 'The Titanic';
    
#10
SELECT 
    COUNT(o.orderNumber) AS 'Number of Mayflower Orders'
FROM
    orders o
        JOIN
    orderdetails od ON o.orderNumber = od.orderNumber
        JOIN
    products p ON od.productCode = p.productCode
WHERE
    p.productName = 'The Mayflower';
    
#11
SELECT 
    p.productLine AS 'Product Line',
    COUNT(*) AS 'Number of Items'
FROM
    products p
GROUP BY p.productLine;

#12
SELECT DISTINCT
    CONCAT('$', FORMAT(SUM(p.amount), 2)) AS 'Total Checks'
FROM
    payments p;
    
#13
SELECT 
    c.customerName AS 'Customer Name',
    CONCAT('$', FORMAT(SUM(p.amount), 2)) AS 'Total Spent'
FROM
    customers c
        JOIN
    payments p ON c.customerNumber = p.customerNumber
GROUP BY c.customerNumber;

#14
SELECT 
    p.productLine AS 'Product Line',
    AVG(p.MSRP) AS 'Average MSRP'
FROM
    products p
GROUP BY p.productLine
HAVING AVG(p.msrp) BETWEEN 80 AND 100;

#15
SELECT 
    CONCAT(ROUND(COUNT(*) / (SELECT 
                            COUNT(*)
                        FROM
                            orders) * 100,
                    1),
            '%') AS '% of Orders not Shipped in 1 Day'
FROM
    orders o
WHERE
    o.orderNumber NOT IN (SELECT 
            orderNumber
        FROM
            orders
        WHERE
            DATEDIFF(shippedDate, orderDate) = 1);
            
#16
SELECT 
    c.customerName AS 'Customer Name'
FROM
    customers c
        LEFT JOIN
    payments p ON c.customerNumber = p.customerNumber
WHERE
    p.checkNumber IS NULL
ORDER BY c.customerName;

#17
SELECT 
    CONCAT(e.lastName, ' ', e.firstName) AS Employee,
    CONCAT(b.firstName, ' ', b.lastName) AS Boss
FROM
    employees b
        JOIN
    employees e ON b.employeeNumber = e.reportsTo
ORDER BY e.lastName , e.firstName;

#18
UPDATE orders 
SET 
    shippedDate = CURRENT_DATE()
WHERE
    orderNumber > 10421;
    
/*
To undo, run:
UPDATE orders
SET
	shippedDate = NULL
WHERE orderNumber > 10421;
*/