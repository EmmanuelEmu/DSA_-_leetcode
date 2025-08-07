# Write your MySQL query statement below
WITH latest AS (
    SELECT p1.product_id AS pid, p1.new_price AS pnew, p1.change_date AS pchange
    FROM Products p1
    WHERE p1.change_date = (
        SELECT MAX(p2.change_date)
        FROM Products p2
        WHERE p2.product_id = p1.product_id
          AND p2.change_date <= '2019-08-16'
    )
)

-- Products with latest price change before or on '2019-08-16'

select distinct mainTable.product_id as product_id, case
								when mainTable.product_id not in (SELECT pid FROM latest) then 10
                                else mainTable.new_price
								end
							as price
from 
(SELECT 
    l.pid AS product_id, 
    l.pnew AS new_price, 
    l.pchange AS change_date
FROM latest l

UNION ALL

-- Products with NO price change before or on '2019-08-16'
SELECT 
    p.product_id, 
    p.new_price, 
    p.change_date
FROM Products p
WHERE p.product_id NOT IN (SELECT pid FROM latest)) as mainTable 