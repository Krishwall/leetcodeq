# Write your MySQL query statement below
with temp AS
    (
        SELECT 
            d.name AS Department,
            salary AS Salary,
            e.name AS Employee,
            DENSE_RANK() Over(PARTITION BY d.id ORDER BY salary DESC) AS rnk

        FROM Department d
        JOIN Employee e
        ON d.id=e.departmentId
    )
SELECT Department,Employee,Salary
FROM temp
WHERE rnk<=3