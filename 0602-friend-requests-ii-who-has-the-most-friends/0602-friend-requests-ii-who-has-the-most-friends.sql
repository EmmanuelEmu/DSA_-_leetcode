# Write your MySQL query statement below
with users as (
		SELECT id,
		   SUM(cnt) AS total_count
		FROM (
		  SELECT requester_id AS id, COUNT(*) AS cnt
		  FROM RequestAccepted
		  GROUP BY requester_id

		  UNION ALL

		  SELECT accepter_id AS id, COUNT(*) AS cnt
		  FROM RequestAccepted
		  GROUP BY accepter_id
		) AS t
		GROUP BY id
		ORDER BY total_count desc
)

select id, total_count as num
from users
limit 1;