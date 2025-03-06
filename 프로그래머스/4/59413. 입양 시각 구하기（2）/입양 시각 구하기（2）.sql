-- 코드를 입력하세요
with recursive hours AS(
    select 0 as h
    UNION ALL
    select h+1
    from hours
    where h<23
)
select a.h, (select count(*) from animal_outs as c where a.h=hour(c.datetime)) as count
from hours as a
left join animal_outs as b
on a.h=HOUR(b.datetime)
group by a.h
order by a.h