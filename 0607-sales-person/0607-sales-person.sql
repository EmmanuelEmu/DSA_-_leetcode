# Write your MySQL query statement below
with red_sale as (
	SELECT ord.order_id, ord.order_date, ord.com_id, com.name as com_name, ord.sales_id as red_id, amount
	FROM Orders AS ord
	LEFT JOIN Company AS com
	ON ord.com_id = com.com_id
)


select name 
from salesperson as slp
where slp.sales_id not in (select red_id from red_sale where com_name = "RED");