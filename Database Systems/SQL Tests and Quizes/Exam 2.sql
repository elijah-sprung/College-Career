# Elijah Sprung

#1
SELECT 
    c.city AS 'City Name'
FROM
    customers c
WHERE
    c.country = 'France'
GROUP BY c.city
HAVING COUNT(c.city) = 1
ORDER BY c.city;

#2
SELECT 
    CONCAT(c.contactLastName,
            ', ',
            c.contactFirstName) AS 'Contact Name'
FROM
    customers c
WHERE
    c.city LIKE 'San%'
ORDER BY c.contactLastName , c.contactFirstName;

#3
SELECT 
    CONCAT('$',
            FORMAT(SUM(od.quantityOrdered * priceEach),
                2)) AS 'Grand Total'
FROM
    orderdetails od;
    
#4
SELECT DISTINCT
    p.productVendor AS 'Vendor Name'
FROM
    orderdetails od
        JOIN
    products p ON od.productCode = p.productCode
WHERE
    od.priceEach >= (2.5 * buyPrice)
ORDER BY p.productVendor;
    
#5
SELECT DISTINCT
    b.firstName AS 'First Name',
    b.lastName AS 'Last Name',
    bb.firstName AS 'Sup First',
    bb.lastName AS 'Sup Last'
FROM
    employees e
        JOIN
    employees b ON e.reportsTo = b.employeeNumber
        JOIN
    employees bb ON b.reportsTo = bb.employeeNumber
ORDER BY b.lastName , b.firstName;

#6
SELECT 
    c.customerName AS 'Customer Name'
FROM
    customers c
        LEFT JOIN
    orders o ON c.customerNumber = o.customerNumber
WHERE
    o.status = 'Cancelled'
        OR o.status IS NULL
ORDER BY c.customerName;

#7
SELECT 
    date_check.num_orders as 'Number of Times the Customer With the Most Orders Had Their Order Shipped Within 5 Days of Placing the Order'
FROM
    (SELECT 
        COUNT(c.customerNumber) AS count,
            c.customerNumber AS cus_num
    FROM
        customers c
    JOIN orders o ON c.customerNumber = o.customerNumber
    GROUP BY c.customerNumber) AS max_col
        JOIN
    (SELECT 
        COUNT(c.customerNumber) AS num_orders,
            c.customerNumber AS cus_num
    FROM
        customers c
    JOIN orders o ON c.customerNumber = o.customerNumber
    WHERE
        o.shippedDate < o.orderDate + 5
    GROUP BY c.customerNumber) AS date_check ON max_col.cus_num = date_check.cus_num
WHERE
    max_col.count = (SELECT 
            MAX(max_col.count)
        FROM
            (SELECT 
                COUNT(c.customerNumber) AS count,
                    c.customerNumber AS cus_num
            FROM
                customers c
            JOIN orders o ON c.customerNumber = o.customerNumber
            GROUP BY c.customerNumber) AS max_col);

#8
SELECT DISTINCT
    c.customerName AS 'Customer Name'
FROM
    payments p
        JOIN
    customers c ON p.customerNumber = c.customerNumber
        JOIN
    orders o ON c.customerNumber = o.customerNumber
        JOIN
    orderdetails od ON o.orderNumber = od.orderNumber
        JOIN
    products pr ON od.productCode = pr.productCode
WHERE
    p.amount > 50000
        AND DATEDIFF(o.shippedDate, o.orderDate) < 3
        AND pr.productLine = 'Ships'
ORDER BY c.customerName;