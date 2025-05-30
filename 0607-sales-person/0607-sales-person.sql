# Write your MySQL query statement below
SELECT name 
FROM SalesPerson
WHERE name NOT IN
(SELECT s.name 
FROM SalesPerson as s
JOIN Orders as o
JOIN Company as c
ON s.sales_id = o. sales_id 
AND c.com_id = o.com_id 
WHERE c.name = "RED"
);