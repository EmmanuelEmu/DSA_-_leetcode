# Write your MySQL query statement below
SELECT DISTINCT transaction_date, 
    SUM(CASE WHEN amount % 2 != 0 THEN amount ELSE 0 END) 
        OVER (PARTITION BY transaction_date) AS odd_sum,
    SUM(CASE WHEN amount % 2 = 0 THEN amount ELSE 0 END) 
        OVER (PARTITION BY transaction_date) AS even_sum
FROM transactions;