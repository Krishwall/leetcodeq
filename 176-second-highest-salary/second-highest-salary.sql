# Write your MySQL query statement below

SELECT max(salary) as SecondHighestSalary 
FROM Employee
where Salary <> (Select max(Salary) From Employee );