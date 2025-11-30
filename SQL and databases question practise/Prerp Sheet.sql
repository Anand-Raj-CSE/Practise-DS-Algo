-- Write a SQL query to find unique active users per product in a rolling 3-month window.
with cte as (
    Select user_id , sum(user_id) over (order by date)
) 
Select distinct(user_id) 