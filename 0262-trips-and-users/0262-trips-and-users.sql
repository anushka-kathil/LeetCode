SELECT 
    Request_at AS Day,
    ROUND(
        SUM(CASE WHEN Status != 'completed' THEN 1 ELSE 0 END) * 1.0 /
        COUNT(*), 2
    ) AS "Cancellation Rate"
FROM Trips
JOIN Users AS c ON Trips.Client_Id = c.Users_Id AND c.Banned = 'No' AND c.Role = 'client'
JOIN Users AS d ON Trips.Driver_Id = d.Users_Id AND d.Banned = 'No' AND d.Role = 'driver'
WHERE Request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY Request_at;
