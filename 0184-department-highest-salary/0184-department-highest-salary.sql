# Write your MySQL query statement below
WITH cte AS (
    SELECT d.name AS Department, e.name AS Employee,
           e.salary,
           MAX(e.salary) OVER (PARTITION BY e.departmentId) AS MaxSalary
    FROM Employee AS e
    LEFT JOIN Department AS d
    ON e.departmentId = d.id
)

SELECT Department, Employee, salary
FROM cte
WHERE salary = MaxSalary;


    