--Question:
--Table: orders(order_id, customer_id, order_date, amount)
--👉 Find customers who have placed more than 5 orders.
Select customer_id from orders group by customer_id having count(order_id)>5


/*⚡ SQL Quiz – Q6
Question:
Table: orders(order_id, customer_id, order_date, amount)
👉 Write a query to get cumulative (running) total of order amounts per customer, 
ordered by order_date.
*/
Select customer_id,sum(amount) from orders 
group by customer_id , order_date order by order_date desc --- not runnig sum
--correct 
SELECT
    customer_id,
    order_date,
    amount,
    SUM(amount) OVER (PARTITION BY customer_id ORDER BY order_date) AS running_total
FROM orders
ORDER BY customer_id, order_date;

/*⚡ SQL Quiz – Q7

Question:Write a query to get the top 2 highest orders (by amount) per customer.
Table: orders(order_id, customer_id, order_date, amount)
 */
 Select order_id , dense_rank() OVER (PARTITION by customer_id ORDER By amount) as rn 
 from orders where rn >=2      -- again incorrect we cannot use rn in where as where is executed first.
 -- Correct query 
  Select order_id , customer_id,amount FROM (SELECT order_id ,customer_id,amount, dense_rank()
   OVER (PARTITION by customer_id ORDER By amount DESC) as rn from orders) t
   where rn<=2

/*SQL Quiz – Q8
Table: orders(order_id, customer_id, order_date, amount)
👉 Find customers who placed orders in January 2025 but did not place any orders in February 2025. */
WITH A as (
    SELECT customer_id from order where month(order_date) = 1 and year(order_date) = 2025
), B as (
    SELECT customer_id from order where month(order_date) =2 and year(order_date) = 2025
)

Select * from A where customer_id not in (Select customer_id from B)

/*SQL Quiz – Q9
Table: orders(order_id, customer_id, order_date, amount)
👉 Write a query to get cumulative (running) total of order amounts per customer, 
ordered by order_date. */
Select customer_id,order_id,
    sum(amount) over (PARTITION by customer_id order by order_date DESC) as t from orders
    order by customer_id,order_date