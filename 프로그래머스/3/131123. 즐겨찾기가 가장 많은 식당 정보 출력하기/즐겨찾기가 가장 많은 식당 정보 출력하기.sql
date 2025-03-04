-- 코드를 입력하세요
SELECT
    A.FOOD_TYPE, A.REST_ID, A.REST_NAME, A.FAVORITES
FROM
    REST_INFO as A
WHERE
    FAVORITES=(select max(favorites) from rest_info as B where A.food_type=B.food_type)
order by
    food_type DESC