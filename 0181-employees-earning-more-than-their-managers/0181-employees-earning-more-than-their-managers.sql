# Write your MySQL query statement below
select name as Employee
from Employee emp
where emp.managerId is not null
  and emp.salary > (
    select mgr.salary
    from Employee mgr
    where mgr.id = emp.managerId
);
