-- 코드를 작성해주세요
with recursive cte as(
    select id, parent_id, 1 as gen_num
    from ecoli_data
    where parent_id is null
    union all
    select cur.id, cur.parent_id, prev.gen_num+1 as gen_num
    from ecoli_data as cur, cte as prev
    where prev.id=cur.parent_id
)

select count(e.id) count,  d.gen_num generation
from ecoli_data as e
join cte as d
on e.id=d.id
where (
    select count(e2.id)
    from ecoli_data as e2
    where e2.parent_id=e.id
) =0
group by d.gen_num
order by 2