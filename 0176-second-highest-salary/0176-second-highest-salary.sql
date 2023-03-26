# Write your MySQL query statement below
SELECT MAX(salary) AS SecondHighestSalary FROM 
(
    SELECT * FROM Employee
    WHERE salary < (SELECT MAX(salary) FROM Employee AS e)
) AS Emp;