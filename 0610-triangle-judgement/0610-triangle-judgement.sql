# Write your MySQL query statement below
SELECT * , if(x+y > z AND y+z > x AND z+x > y,"Yes","No" ) as triangle 
FROM Triangle;