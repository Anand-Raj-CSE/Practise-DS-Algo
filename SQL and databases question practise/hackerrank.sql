--https://www.hackerrank.com/challenges/the-report/problem?isFullScreen=true
with cte as (
    Select s.Name as name , (CASE
    WHEN s.Marks between 90 and 100 THEN 10
    WHEN s.Marks between 80 and 89 THEN 9
    WHEN s.Marks between 70 and 79 THEN 8
    WHEN s.Marks between 60 and 69 THEN 7
    WHEN s.Marks between 50 and 59 THEN 6
    WHEN s.Marks between 40 and 49 THEN 5
    WHEN s.Marks between 30 and 39 THEN 4
    WHEN s.Marks between 20 and 29 THEN 3
    WHEN s.Marks between 10 and 19 THEN 2
    WHEN s.Marks between 0 and 9 THEN 1
    END
    ) as grade, s.Marks as marks from Students s 
), cte1 as (
    Select name , rank() over (order by marks desc) as ranking, marks from cte 
)

Select CASE when ranking>7 then name else NULL END as name , ranking , marks from cte1 
where ranking>=7 order by ranking desc

---------------------------------Correct Answer----------------------
Select name , CASE WHEN grade>7 then name else NULL END , marks
FROM (
    Select s.Name as name , CASE
    WHEN s.Marks between 90 and 100 THEN 10
    WHEN s.Marks between 80 and 89 THEN 9
    WHEN s.Marks between 70 and 79 THEN 8
    WHEN s.Marks between 60 and 69 THEN 7
    WHEN s.Marks between 50 and 59 THEN 6
    WHEN s.Marks between 40 and 49 THEN 5
    WHEN s.Marks between 30 and 39 THEN 4
    WHEN s.Marks between 20 and 29 THEN 3
    WHEN s.Marks between 10 and 19 THEN 2
    WHEN s.Marks between 0 and 9 THEN 1
    END
    as grade, s.Marks as marks from Students s 
)
where grade>=8 order by grade desc,name ASC

