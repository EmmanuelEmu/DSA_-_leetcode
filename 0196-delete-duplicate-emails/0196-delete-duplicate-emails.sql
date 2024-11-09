# Write your MySQL query statement below
DELETE p
FROM Person p
JOIN (
    SELECT MIN(id) AS keep_id, email
    FROM Person
    GROUP BY email
    HAVING COUNT(email) > 1
) dup
ON p.email = dup.email
WHERE p.id != dup.keep_id;
