# Write your MySQL query statement below
WITH mp AS (
    -- Get employees with a primary department
    SELECT employee_id, department_id
    FROM Employee
    WHERE primary_flag = 'Y'

    UNION

    -- Get employees who are in only one department
    SELECT e.employee_id, e.department_id
    FROM Employee AS e
    JOIN (
        SELECT employee_id, ANY_VALUE(department_id) AS department_id
        FROM Employee
        GROUP BY employee_id
        HAVING COUNT(*) = 1
    ) AS one_dept
    ON e.employee_id = one_dept.employee_id
)

-- Final output
SELECT * FROM mp
order by mp.employee_id;