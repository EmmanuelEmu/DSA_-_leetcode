# Write your MySQL query statement below
select modified.event_day as day, modified.emp_id, SUM(modified.total_time_spent) as total_time 
from (
	select *, (out_time-in_time) as total_time_spent
    from Employees
) as modified
group by modified.event_day, modified.emp_id;