# Write your MySQL query statement below

Select e2.name as Employee 
From employee e1
 Join employee e2 on e1.id = e2.managerID
WHERE
e1.salary < e2.salary;