SELECT e_a.Name AS Employee
FROM Employee AS e_a JOIN Employee AS e_b ON e_a.ManagerId = e_b.Id
WHERE e_a.Salary > e_b.Salary
