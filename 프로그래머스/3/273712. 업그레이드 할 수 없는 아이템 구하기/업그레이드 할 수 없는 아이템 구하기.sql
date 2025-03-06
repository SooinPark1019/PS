-- 코드를 작성해주세요
SELECT
    A.item_id, A.item_name, A.rarity
from 
    item_info as A
left join
    item_tree as B
on
    A.item_id=B.parent_item_id
where
    B.item_id is null
order by
    A.item_id desc
    