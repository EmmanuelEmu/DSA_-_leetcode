# Write your MySQL query statement below
select t1.machine_id as machine_id, ROUND((t2.endTime - t1.startTime)/t1.ps_id, 3) as processing_time
from
	(select machine_id, SUM(timestamp) as startTime, COUNT(process_id) as ps_id
	from Activity
	where activity_type = "start"
	group by machine_id) as t1
	join 
	(select machine_id, SUM(timestamp) as endTime
	from Activity
	where activity_type = "end"
	group by machine_id) as t2
on t1.machine_id = t2.machine_id
group by machine_id;