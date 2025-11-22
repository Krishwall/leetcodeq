CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
        Select salary 
        from (Select distinct salary, 
            DENSE_RANK() OVER (ORDER BY salary DESC ) as rnk
            from employee
            )t
            where rnk=N
  );
END