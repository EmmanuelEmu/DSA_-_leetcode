# Write your MySQL query statement below
SELECT 
    score AS score, 
    DENSE_RANK() OVER (ORDER BY score DESC) AS `rank`
FROM 
    Scores;
