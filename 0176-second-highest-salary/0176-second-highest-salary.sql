-- # Write your MySQL query statement below


-- SELECT  MAX(SALARY) AS SecondHighestSalary 
-- FROM EMPLOYEE
--  WHERE
--   SALARY <(SELECT MAX(SALARY) FROM EMPLOYEE);
select(select distinct salary  
FROM EMPLOYEE
order by salary desc
limit 1 offset 1) as SecondHighestSalary;