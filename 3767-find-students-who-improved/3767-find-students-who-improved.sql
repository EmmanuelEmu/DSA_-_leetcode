# Write your MySQL query statement below
with rowNumber as (
			SELECT *,
				ROW_NUMBER() OVER (PARTITION BY student_id, subject ORDER BY exam_date) AS rn,
				COUNT(*) OVER (PARTITION BY student_id, subject) AS points
			FROM Scores
)

SELECT 
    f.student_id,
    f.subject,
    f.score AS first_score,
    l.score AS latest_score
FROM (
    SELECT *
    FROM rowNumber
    WHERE rn = 1 AND points > 1
) AS f
JOIN (
    SELECT *
    FROM rowNumber
    WHERE rn = points AND points > 1
) AS l
ON f.student_id = l.student_id
AND f.subject = l.subject
where f.score < l.score
order by f.student_id, f.subject asc;