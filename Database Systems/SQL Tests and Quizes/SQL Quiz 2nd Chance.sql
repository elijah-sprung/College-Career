#1
SELECT 
    b.BOOK_SUBJECT, COUNT(b.BOOK_SUBJECT) AS Books_In_Subject
FROM
    BOOK b
GROUP BY b.BOOK_SUBJECT
ORDER BY Books_In_Subject DESC
LIMIT 3;

#2
SELECT 
    CONCAT(p.PAT_FNAME, ' ', p.PAT_LNAME) AS 'Full Name'
FROM
    PATRON p
WHERE
    p.PAT_ID IN (SELECT 
            p.PAT_ID
        FROM
            PATRON p
                JOIN
            CHECKOUT c ON p.PAT_ID = c.PAT_ID
        WHERE
            c.CHECK_IN_DATE > c.CHECK_DUE_DATE)
ORDER BY p.PAT_LNAME;

#3
SELECT 
    UPPER(a.AU_LNAME) AS 'Author\'s Last Name',
    b.BOOK_TITLE AS 'Book Title',
    b.BOOK_COST AS 'Book Cost'
FROM
    AUTHOR a
        JOIN
    WRITES w ON a.AU_ID = w.AU_ID
        JOIN
    BOOK b ON w.BOOK_NUM = b.BOOK_NUM
WHERE
    b.BOOK_COST > 60 AND b.BOOK_COST < 81
ORDER BY b.BOOK_COST DESC , a.AU_LNAME;