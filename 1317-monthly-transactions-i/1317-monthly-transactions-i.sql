# Write your MySQL query statement below
SELECT 
    DATE_FORMAT(t.trans_date, '%Y-%m') AS month, 
    t.country, 
    COUNT(t.country OR t.country is null) AS trans_count,
    SUM(CASE WHEN t.state = "approved" THEN 1 ELSE 0 END) AS approved_count,
    SUM(t.amount) AS trans_total_amount,
    SUM(CASE WHEN t.state = "approved" THEN t.amount ELSE 0 END) AS approved_total_amount
FROM 
    Transactions AS t
GROUP BY 
    DATE_FORMAT(t.trans_date, '%Y-%m'), t.country;