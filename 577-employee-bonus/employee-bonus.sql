# Write your MySQL query statement 

SELECT e.name, b.bonus from Employee e  LEFT OUTER JOIN Bonus b
    ON e.empId=b.empId
    where ((b.bonus is NULL) OR (b.bonus <1000));
   