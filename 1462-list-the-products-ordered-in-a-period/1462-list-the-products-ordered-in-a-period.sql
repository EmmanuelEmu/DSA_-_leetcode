# Write your MySQL query statement below
with modified as (
	SELECT pd.product_id, pd.product_name, od.total_sale as unit
	FROM Products AS pd
	INNER JOIN (
		SELECT product_id, SUM(unit) AS total_sale
		FROM Orders
        where order_date like "2020-02-%"
		GROUP BY product_id
	) AS od
	ON pd.product_id = od.product_id
	GROUP BY pd.product_id, pd.product_name
)
select product_name, unit from modified
where unit >= 100;