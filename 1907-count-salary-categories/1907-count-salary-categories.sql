# Write your MySQL query statement below
select 'High Salary' as category,count(*) as accounts_count
from Accounts 
where income>50000
union all
select 'Average Salary',count(*)
from Accounts
where income >=20000 && income<=50000
union all
select 'Low Salary',count(*)
from Accounts
where income <20000