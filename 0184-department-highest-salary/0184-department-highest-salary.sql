SELECT 
    d.name AS Department,
    e.name AS Employee,
    e.salary AS Salary
FROM 
    department AS d
JOIN 
    employee AS e
ON 
    d.id = e.departmentId
WHERE 
    (e.departmentId, e.salary) IN (
        SELECT 
            departmentId, 
            MAX(salary)
        FROM 
            employee
        GROUP BY 
            departmentId
    );
