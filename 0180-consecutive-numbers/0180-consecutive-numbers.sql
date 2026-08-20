# Write your MySQL query statement below
select distinct num as ConsecutiveNums
from (
    select id,num,
    lag(num) over (order by id) as p1,
    lag(num,2) over (order by id) as p2
    from Logs
)l
where num=p1 and num=p2