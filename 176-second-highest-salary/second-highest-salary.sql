# Write your MySQL query statement below
SELECT IFNULL((
    SELECT salary from Employee
    WHERE salary < (SELECT max(salary) from Employee)
    ORDER BY salary Desc
    LIMIT 1
), null) AS SecondHighestSalary;
