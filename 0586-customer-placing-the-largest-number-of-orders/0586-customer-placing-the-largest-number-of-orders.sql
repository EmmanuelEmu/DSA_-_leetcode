# Write your MySQL query statement below
with order_count as (
    select customer_number , count(order_number) as no_of_orders
    from Orders
    group by customer_number
    order by no_of_orders desc
)

select customer_number
from order_count
limit 1;