# Write your MySQL query statement below

Select max(num) as num
from 
(Select num from MyNumbers
Group By num
Having count(num)=1
)as n
