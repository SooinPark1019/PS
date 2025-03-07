-- 코드를 입력하세요
with t as(
    select * from FIRST_HALF
    union
    select * from JULY
)

select flavor
from t
group by flavor
order by sum(total_order) desc
limit 3