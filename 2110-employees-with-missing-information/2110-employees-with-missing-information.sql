# Write your MySQL query statement below
with filtered_emp as (
	select emp.employee_id
    from Employees as emp
    inner join Salaries as sl
    on emp.employee_id = sl.employee_id
)

select employee_id
from Employees
where employee_id not in (select employee_id from filtered_emp)
union all
select employee_id
from Salaries
where employee_id not in (select employee_id from filtered_emp)
order by employee_id asc;