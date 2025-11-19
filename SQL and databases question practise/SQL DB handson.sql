/*LinkedIn 𝐒𝐐𝐋 𝐏𝐫𝐚𝐜𝐭𝐢𝐜𝐞 - Given a table containing information about bank deposits and withdrawals 
made using an UPI app, write a query to retrieve the final account balance for each account, 
taking into account all the transactions recorded in the table with the assumption that there
are no missing transactions.

𝐭𝐫𝐚𝐧𝐬𝐚𝐜𝐭𝐢𝐨𝐧𝐬 𝐓𝐚𝐛𝐥𝐞:
transaction_id int,
account_id int,
amount decimal(4,2),
transaction_type varchar(30)

𝐄𝐱𝐚𝐦𝐩𝐥𝐞 𝐈𝐧𝐩𝐮𝐭:
transaction_id account_id amount transaction_type
123 101 10.00 Deposit
124 101 20.00 Deposit
125 101 5.00 Withdrawal
126 201 36.00 Deposit
127 201 10.00 Withdrawal
128 301 50.00 Deposit 
129 301 8.00 Withdrawal
130 301 20.00 Deposit

𝐄𝐱𝐚𝐦𝐩𝐥𝐞 𝐎𝐮𝐭𝐩𝐮𝐭:
account_id final_balance
101 25.00 
201 26.00
301 62.00
*/

Select account_id , (SUM(CASE WHEN transaction_type = 'Deposit' THEN amount ESLE 0) - 
SUM(CASE WHEN transaction_type = 'Withdrawal' THEN amount ESLE 0))
as final_balance from transnsaction Group by account_id