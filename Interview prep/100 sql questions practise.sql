--- get the new and repeated customers data

with first_visit as (
    Select customer_id,min(order_date) as first_visit_date from customer_orders
    group by customer_id
)

Select o.order_date , 
sum(case when o.order_date = fv.first_visit_date then 1 else 0 end) as new_customers , 
sum(case when o.order_date > fv.first_visit_date then 1 else 0 end) as repeat_customers  
from customer_orders o inner join first_visit fv on o.customer_id = fv.customer_id 
group by order_date