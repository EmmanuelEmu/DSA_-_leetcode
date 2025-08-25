# Write your MySQL query statement below
with main_Table as (
	SELECT 
		stock_name,
		SUM(CASE WHEN operation = 'Buy' THEN price ELSE 0 END) AS total_expense,
		SUM(CASE WHEN operation = 'Sell' THEN price ELSE 0 END) AS total_gain
	FROM Stocks
	GROUP BY stock_name
)

select stock_name, total_gain-total_expense as capital_gain_loss
from main_table;