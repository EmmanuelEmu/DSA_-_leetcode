# Write your MySQL query statement below
SELECT person_name
FROM (
    SELECT 
        person_name,
        turn,
        SUM(weight) OVER (ORDER BY turn) AS total
    FROM Queue
) AS mo
WHERE mo.total <= 1000
ORDER BY mo.turn DESC
LIMIT 1;