# Write your MySQL query statement below
with modified as (
	select us.account, us.name, sum(tr.amount) as total_trnx
    from Users as us
    inner join Transactions as tr
    on us.account = tr.account
    group by us.account, us.name
)

select name, total_trnx as balance
from modified 
where total_trnx > 10000;