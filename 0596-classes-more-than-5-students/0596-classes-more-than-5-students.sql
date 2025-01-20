# Write your MySQL query statement below
SELECT st_cl.Class as class
FROM
(SELECT class AS Class, COUNT(student) AS stu
 FROM Courses
 GROUP BY class) AS st_cl
WHERE st_cl.stu >= 5;
