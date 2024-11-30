# Write your MySQL query statement below
SELECT 
    ROUND((COUNT(customer_id)*100)/(SELECT COUNT(DISTINCT customer_id) FROM Delivery),2) AS immediate_percentage 
FROM 
    Delivery AS d
WHERE 
    d.order_date = d.customer_pref_delivery_date AND d.order_date = (SELECT MIN(order_date) FROM Delivery as ds WHERE ds.customer_id = d.customer_id GROUP BY ds.customer_id);