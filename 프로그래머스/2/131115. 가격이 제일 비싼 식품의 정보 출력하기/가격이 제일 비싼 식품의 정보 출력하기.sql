-- 코드를 입력하세요
SELECT product_id, product_name, product_cd, category, price
from food_product as f
where f.price = (select max(ff.price)
                from food_product as ff)