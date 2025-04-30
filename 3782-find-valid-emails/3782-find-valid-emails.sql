# Write your MySQL query statement below
select  user_id, email   
from Users 
where REGEXP_LIKE(email, '^[A-Za-z0-9_]+@[A-Za-z_]+\.com$');
