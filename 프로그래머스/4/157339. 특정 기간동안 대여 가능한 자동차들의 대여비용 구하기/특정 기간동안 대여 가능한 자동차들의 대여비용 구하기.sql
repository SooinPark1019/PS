-- 코드를 입력하세요
with cte as(
    select car_id
    from CAR_RENTAL_COMPANY_CAR
    where car_id not in (select A.car_id from CAR_RENTAL_COMPANY_CAR as A join CAR_RENTAL_COMPANY_RENTAL_HISTORY as B on A.car_id=B.car_id WHERE START_DATE <= '2022-11-30' AND END_DATE >= '2022-11-01')
)
SELECT C.CAR_ID, C.CAR_TYPE, floor(30*C.daily_fee*(100-ifnull(
    (
        select D.discount_rate
        from CAR_RENTAL_COMPANY_DISCOUNT_PLAN as D
        where D.car_type=C.car_type and D.duration_type='30일 이상'
    ), 0
))/100) as FEE
from CAR_RENTAL_COMPANY_CAR as C
join cte as D
on C.car_id = D.car_id
where C.car_type in ('세단', 'SUV')
group by C.car_id
having fee<2000000 and 500000<=fee
order by fee desc, C.car_type, C.car_id desc
    