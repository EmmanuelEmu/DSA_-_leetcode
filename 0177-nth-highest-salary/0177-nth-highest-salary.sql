CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    DECLARE result INT;
    
    WITH ranked_salaries AS (
        SELECT 
            salary,
            DENSE_RANK() OVER (ORDER BY salary DESC) as salary_rank,
            COUNT(*) OVER () as total_employees
        FROM Employee
    )
    SELECT 
        CASE 
            WHEN N > total_employees OR N <= 0 THEN NULL
            ELSE salary
        END INTO result
    FROM ranked_salaries 
    WHERE salary_rank = N
    LIMIT 1;
    
    RETURN result;
END;