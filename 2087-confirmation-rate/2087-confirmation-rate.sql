# Write your MySQL query statement below
SELECT s.user_id, ROUND(SUM(CASE WHEN c.action = "confirmed" THEN 1 ELSE 0 END) / COUNT(c.action OR c.action IS null),2) AS confirmation_rate
FROM Signups AS s
LEFT JOIN Confirmations AS c
ON s.user_id = c.user_id
GROUP BY s.user_id;