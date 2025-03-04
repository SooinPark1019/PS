-- 코드를 입력하세요
SELECT
    a.CAR_ID,
    case
        when (select count(*) from CAR_RENTAL_COMPANY_RENTAL_HISTORY as b where a.car_id=b.car_id and start_date<=str_to_date('2022-10-16', '%Y-%m-%d') and str_to_date('2022-10-16', '%Y-%m-%d') <= end_date) >= 1 then '대여중'
        else '대여 가능'
    end as AVAILABILITY
from CAR_RENTAL_COMPANY_RENTAL_HISTORY as a
group by a.car_id
order by a.car_id desc