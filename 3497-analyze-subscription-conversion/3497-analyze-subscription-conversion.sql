# Write your MySQL query statement below
select t1.user_id, t1.trial_avg_duration, t2.paid_avg_duration 
from
(
	select user_id, round(avg(activity_duration), 2) as trial_avg_duration
	from UserActivity
    where activity_type = "free_trial"
    group by user_id
) as t1
inner join 
(
	select user_id, round(avg(activity_duration), 2) as paid_avg_duration
	from UserActivity
    where activity_type = "paid"
    group by user_id
) as t2
on t1.user_id = t2.user_id;