# Write your MySQL query statement below
SELECT class from Courses
GROUP BY class
HAVING COUNT(class) >= 5;