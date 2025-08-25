# Write your MySQL query statement below
with managers as (
	select reports_to, count(reports_to) as cnt, round(avg(age)) as average_age
	from Employees
	where reports_to is not null
	group by reports_to
)

select emp.employee_id, emp.name, managers.cnt as reports_count, managers.average_age
from Employees as emp
inner join managers
on managers.reports_to = emp.employee_id
order by emp.employee_id;