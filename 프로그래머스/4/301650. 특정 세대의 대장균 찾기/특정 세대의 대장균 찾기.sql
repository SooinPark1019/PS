-- 코드를 작성해주세요
with gen1 as(
    select id
    from ECOLI_DATA
    where parent_id is null
),
gen2 as(
    select g2.id
    from ECOLI_DATA as g2
    join gen1 as g1
    on g1.id=g2.parent_id
)
select g3.id
from ecoli_data as g3
join gen2 as g2
on g2.id=g3.parent_id
order by 1