# Write your MySQL query statement below
select name
from Employee as emp
inner join
	(select managerId as mngId, count(managerId) as noOfReports 
	from Employee
	group by managerId
	having count(managerID)>=5) as mng
on emp.id = mng.mngId;