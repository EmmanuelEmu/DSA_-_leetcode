# Write your MySQL query statement below
SELECT COALESCE(
    (SELECT num
     FROM (SELECT num, COUNT(num) as cnt FROM MyNumbers GROUP BY num) as single_num
     WHERE single_num.cnt = 1
     ORDER BY num DESC
     LIMIT 1),
    NULL
) AS num;
