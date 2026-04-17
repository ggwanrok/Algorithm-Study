-- 코드를 입력하세요
SELECT distinct USER_ID, PRODUCT_ID 
from online_sale
where (user_id, product_id) in (select user_id, product_id from online_sale group by user_id, product_id having count(user_id) > 1)
order by user_id asc, product_id desc 