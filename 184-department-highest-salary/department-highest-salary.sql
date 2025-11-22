# Write your MySQL query statement below

Select d.name as Department,e.name as Employee,e.salary as Salary from Employee e 
JOIN 
    Department d
    ON e.departmentId=d.id
    AND (e.departmentId,salary) IN(Select departmentId,Max(salary) FROM Employee GROUP BY 
    departmentId)
    