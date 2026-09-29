# Write your MySQL query statement below
select product_name, year, price
from sales as sales
left join product as prod
on sales.product_id = prod.product_id
