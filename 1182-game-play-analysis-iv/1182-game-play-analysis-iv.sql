# Write your MySQL query statement below
WITH one_player AS (
    SELECT 
        player_id, 
        MIN(event_date) AS login_date, 
        DATE_ADD(MIN(event_date), INTERVAL 1 DAY) AS next_day
    FROM Activity
    GROUP BY player_id
)

SELECT ROUND(COUNT(ac.player_id)/(SELECT count(distinct player_id) from Activity), 2) as fraction
FROM Activity as ac
inner join one_player
on one_player.player_id = ac.player_id
where one_player.next_day = ac.event_date;