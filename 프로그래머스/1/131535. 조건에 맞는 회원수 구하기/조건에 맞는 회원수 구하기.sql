-- 코드를 입력하세요
SELECT
    COUNT(USER_ID) as USERS
FROM
    USER_INFO
WHERE
    (AGE between 20 and 29) AND YEAR(JOINED)=2021