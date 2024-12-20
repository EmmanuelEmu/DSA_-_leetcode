# Write your MySQL query statement below
SELECT 
    q.query_name, 
    ROUND(AVG(q.rating / q.position), 2) AS quality,
    ROUND(SUM(CASE WHEN q.rating < 3 THEN 1 ELSE 0 END) * 100.0 / COUNT(q.query_name), 2) AS poor_query_percentage
FROM 
    Queries AS q
WHERE
    q.query_name IS NOT null
GROUP BY 
    q.query_name;