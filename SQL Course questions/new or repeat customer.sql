--- New and repeat customer
with first_visit as (
    Select cust_id, min(order_date) as first_ord_dtm from customer group by cust_id
)

Select c.cust_id , c.order_date ,CASE 
WHEN  f.first_ord_dtm < c.order_date then 'Repeat Customer' ELSE 'New Customer' END 
as repeatOrNewCust from customer c inner join first_visit f on c.cust_id = f.cust_id 
order by c.cust_id,c.order_date