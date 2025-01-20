# Write your MySQL query statement below
SELECT customer_id
FROM (SELECT customer_id, COUNT(distinct product_key) AS cnt FROM Customer GROUP BY customer_id) as single_customer
WHERE single_customer.cnt = (SELECT COUNT(distinct product_key) FROM Product);