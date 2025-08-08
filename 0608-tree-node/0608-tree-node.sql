# Write your MySQL query statement below
WITH prt AS (
    SELECT DISTINCT p_id AS parent_nodes
    FROM Tree
    WHERE p_id IS NOT NULL
)

SELECT 
    id, 
    CASE 
        WHEN p_id IS NULL THEN 'Root'
        WHEN id IN (SELECT parent_nodes FROM prt) THEN 'Inner'
        ELSE 'Leaf'
    END AS type
FROM Tree;
