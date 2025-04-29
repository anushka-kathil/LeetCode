# Write your MySQL query statement below
Select name as Customers
from customers 
WHERE id NOT IN(
select customerId from orders
);