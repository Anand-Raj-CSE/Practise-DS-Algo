/* Question is that we have a table that has date and temperature column, most recorded temperature of that day.
Make another column that has average temperature , averagh temperature is sum of previous day temp + curr day temp + coming day temp.
*/
Select dtm, temp, ((lead(temp) + temp + lag(temp))/3) as avg_temp from data


---------------------- Window function always need over, so correct code ------------------
Select dtm , temp, (COALESCE(LAG(temp) over (order by dtm desc),0) + temp + 
COALESCE(LEAD(temp) over (ORDER BY dtm DESC),0))/3.0 as avg_temp from data

------------------------ Using Row between function-------------------
Select dtm, temp , AVG(temp) over (Order BY date rows between 1 preeceding AND 1 Following) as Average_temp 
from data