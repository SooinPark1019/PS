-- 코드를 입력하세요
with total as(
    select count(distinct(user_id)) as c
    from user_info
    where year(joined)=2021
)
SELECT year(b.sales_date) as year, month(b.sales_date) as month, count(distinct(a.user_id)) as purchased_users, round(count(distinct(a.user_id))/(select c from total), 1) as PUCHASED_RATIO
    from user_info as a
    join online_sale as b
    on a.user_id=b.user_id
    where year(a.joined)=2021
    group by year(b.sales_date), month(b.sales_date)
    order by 1, 2
    