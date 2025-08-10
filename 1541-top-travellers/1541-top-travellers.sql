# Write your MySQL query statement below
select usr.name, case
						when usr.id not in (select user_id from Rides) then 0
                        else sum(rid.distance)
				  end 
							as travelled_distance
from Users as usr
left join Rides as rid 
on usr.id = rid.user_id
group by usr.id, usr.name
order by travelled_distance desc, usr.name asc;