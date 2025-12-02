# Write your MySQL query statement below


Select class from   Courses 
Group By class
having COUNT(student) >4;