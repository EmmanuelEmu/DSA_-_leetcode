# Write your MySQL query statement below
select *, CASE
			when x>0 and y>0 and z>0 and x+y>z and z+y>x and z+x>y then "Yes"
            else "No"
			END AS triangle
from Triangle;