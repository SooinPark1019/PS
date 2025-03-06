-- 코드를 작성해주세요
select
    A.ID,
    case
        WHEN A.NTILE_RANK = 1 THEN 'CRITICAL'
        WHEN A.NTILE_RANK = 2 THEN 'HIGH'
        WHEN A.NTILE_RANK = 3 THEN 'MEDIUM'
        else 'LOW'
    end as COLONY_NAME
from
    (
        select
            ID, NTILE(4) over (order by size_of_colony desc) as NTILE_RANK
        from
            ecoli_data
    ) A
order by A.ID
