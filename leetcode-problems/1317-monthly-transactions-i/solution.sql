# Write your MySQL query statement below
select 
left (trans_date, 7) as month,
country,
count(id) as trans_count,
sum(state = 'approved') as approved_count,
sum(amount) as trans_total_amount, 
SUM(CASE WHEN state = 'approved' THEN amount ELSE 0 END) AS approved_total_amount
from transactions
group by month, country
