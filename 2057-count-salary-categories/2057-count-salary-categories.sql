# Write your MySQL query statement below
select 'Low Salary' as category, COUNT(CASE WHEN income < 20000 THEN account_id END) AS accounts_count
from Accounts
union all
select 'Average Salary' as category, COUNT(CASE WHEN income >= 20000 and income<=50000 THEN account_id END) AS accounts_count
from Accounts
union all
select 'High Salary' as category, COUNT(CASE WHEN income > 50000 THEN account_id END) AS accounts_count
from Accounts;