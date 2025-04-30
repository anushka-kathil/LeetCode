# Write your MySQL query statement below
SELECT 
s1.score,
(SELECT count(*) FROM (SELECT DISTINCT Score s FROM Scores) tmp
WHERE s >= s1.Score) AS `Rank`
FROM Scores s1
ORDER BY s1.Score DESC;
