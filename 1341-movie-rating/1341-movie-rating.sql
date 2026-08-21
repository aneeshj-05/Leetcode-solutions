select results
from(
    select u.name as results,row_number() over (order by count(*) desc,u.name asc) as rn
    from MovieRating r
    join Users u
    on r.user_id=u.user_id
    group by u.user_id
) t
where rn=1
Union all
select results
from(
    select m.title as results,row_number() over (order by avg(r.rating) desc,m.title asc) as rno
    from MovieRating r
    join Movies m
    on r.movie_id=m.movie_id
    where r.created_at >='2020-02-01' and r.created_at<'2020-03-01'
    group by m.title
) h
where rno=1