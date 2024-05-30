#1
SELECT 
    s.firstName, COUNT(s.firstName)
FROM
    student s
GROUP BY s.firstName
HAVING COUNT(s.firstName) > 1
ORDER BY COUNT(s.firstName) DESC , s.firstName;

#2
SELECT 
    s.major, COUNT(s.major)
FROM
    student s
        JOIN
    enroll e ON s.studentid = e.studentID
        JOIN
    class cl ON e.classCode = cl.classCode
        JOIN
    course co ON cl.courseCode = co.courseCode
WHERE
    transfer = 'N' AND co.courseCredit = 4
GROUP BY s.major
ORDER BY COUNT(s.major) DESC;

#3
SELECT DISTINCT
    s.firstName
FROM
    student s
        JOIN
    enroll e ON s.studentid = e.studentID
WHERE
    e.enrollSemester = '1'
        AND enrollYear = 2018
        AND s.studentid IN (SELECT 
            s.studentid
        FROM
            student s
                JOIN
            enroll e ON s.studentid = e.studentID
        WHERE
            e.enrollGrade = 'B'
        GROUP BY s.studentid
        HAVING COUNT(e.enrollGrade) = 1)
ORDER BY s.firstName;
    
#4
SELECT 
    CONCAT('GPA=', FORMAT(AVG(s.GPA), 2)) AS 'Average'
FROM
    student s
        JOIN
    enroll e ON s.studentid = e.studentID
        JOIN
    class c ON e.classCode = c.classCode
WHERE
    c.classTime LIKE 'Th%';
    
#5
SELECT 
    co.courseDescription, COUNT(e.classCode)
FROM
    student s
        JOIN
    enroll e ON s.studentid = e.studentID
        JOIN
    class cl ON e.classCode = cl.classCode
        JOIN
    course co ON cl.courseCode = co.courseCode
WHERE
    e.enrollSemester = '2'
GROUP BY co.courseCode
ORDER BY COUNT(e.classCode) DESC;

#BONUS
UPDATE enroll 
SET 
    enrollGrade = 'A'
WHERE
    studentID IN (SELECT 
            s.studentid
        FROM
            student s
                JOIN
            enroll e ON s.studentid = e.studentID
                JOIN
            class cl ON e.classCode = cl.classCode
                JOIN
            course co ON cl.courseCode = co.courseCode
        WHERE
            co.courseCode = 'CIS-420')
        AND classCode = 20040;