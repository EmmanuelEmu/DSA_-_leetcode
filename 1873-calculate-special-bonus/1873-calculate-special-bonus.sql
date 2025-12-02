# Write your MySQL query statement below
select employee_id, CASE
                        when name not like "M%" and employee_id%2!=0 then salary
                        else 0
                    END AS bonus 
from Employees
order by employee_id;