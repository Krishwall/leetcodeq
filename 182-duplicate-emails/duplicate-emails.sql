# Write your MySQL query statement below

Select email from Person
GROUP BY email
Having count(email) >1;