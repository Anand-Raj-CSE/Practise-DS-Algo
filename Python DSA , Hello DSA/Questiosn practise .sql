--Question:
--Table: orders(order_id, customer_id, order_date, amount)
--👉 Find customers who have placed more than 5 orders.
Select customer_id from orders group by customer_id having count(order_id)>5


/*⚡ SQL Quiz – Q6

Question:
Table: orders(order_id, customer_id, order_date, amount)

👉 Write a query to get cumulative (running) total of order amounts per customer, ordered by order_date.
*/
