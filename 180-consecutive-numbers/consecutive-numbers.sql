# Write your MySQL query statement below

Select Distinct 
l1.num as ConsecutiveNums
From 
    Logs l1,
    Logs l2,
    Logs l3
Where 
l1.id=l2.id-1
AND l2.id=l3.id-1
AND l1.num=l2.num
And l1.num=l3.num
;

