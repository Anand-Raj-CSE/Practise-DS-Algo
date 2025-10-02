''' Q1. DataFrame Basics
You have a PySpark DataFrame orders(order_id, customer_id, order_date, amount).
👉 Write PySpark code to: Select only customer_id, amount.Filter orders where amount > 1000.
Show the first 5 results. '''
df = orders.select("customer_id","amount").fileter(column("amount")>1000).show(5)

"""
Q2. Add Discount Column
You have a DataFrame orders(order_id, customer_id, order_date, amount).
👉 Write PySpark code to add a new column discounted_amount which is 90% of amount 
(i.e., apply a 10% discount). Then display the first 5 rows.
"""
df = orders.withColumn("Discounted_amount",col("amount")*0.9).show(5)
"""
Sum of orders per customer
"""
from pyspark.sql.functions import * 
df = orders.groupBY('customer_id').agg(sum(col('amount')).alias("Total_sales"))\
    .orderBy(desc("Total_sales"))
"""
Task 3: Find top N customers by sales
Description:
Using the total sales per customer (like from Task 2), get the top 3 customers by total_amount.
Output should include: customer_id and total_amount.
"""
df = orders.groupBY('customer_id').agg(sum(col('amount')).alias("Total_sales"))\
    .orderBy(desc("Total_sales")).show(3)
# Through window function
df =orders.groupBY('customer_id').agg(sum(col('amount')).alias("Total_sales"))
ordered_df = df.orderBy(desc("Total_sales"))
ordered_df = ordered_df.withColumn('Ranked_column',rank().over(ordered_df))
ordered_df.show(3)
## Over only expects a window specific object , so cotrect code
df =orders.groupBY('customer_id').agg(sum(col('amount')).alias("Total_sales"))
ordered_df = Window.orderBy(desc("Total_sales"))
ordered_df = ordered_df.withColumn('Ranked_column',rank().over(ordered_df))
ordered_df.show(3)
"""
Task 4: Handle missing data
Description:
You have a DataFrame df with columns:
name (string)
age (integer)
salary (float)
Goal:
Replace null values in age with 0.
Replace null values in salary with the mean salary of the column.
"""