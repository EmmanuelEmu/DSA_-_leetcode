# Write your MySQL query statement below
WITH singleDay AS (
    SELECT visited_on, 
           SUM(amount) AS total_amount,
           COUNT(customer_id) AS user_count
    FROM Customer
    GROUP BY visited_on
)

SELECT main.visited_on, main.total_sell as amount, ROUND(total_sell/7, 2) as average_amount
from
(SELECT visited_on,
       SUM(total_amount) OVER (
           ORDER BY visited_on
           ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
       ) AS total_sell,
       SUM(user_count) OVER (
           ORDER BY visited_on
           ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
       ) AS total_user,
       row_number() over (order by visited_on) as rn
FROM singleDay
ORDER BY visited_on) as main
where main.rn > 6;