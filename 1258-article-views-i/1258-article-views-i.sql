# Write your MySQL query statement below
SELECT author_id AS id
FROM Views
WHERE author_id = viewer_id
GROUP BY author_id
HAVING COUNT(author_id) >= 1
ORDER BY author_id ASC;
