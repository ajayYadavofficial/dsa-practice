# Write your MySQL query statement below
SELECT u.name,
SUM(CASE WHEN u.id = r.user_id THEN r.distance ELSE 0 END) AS travelled_distance
FROM Users u
LEFT JOIN Rides r
ON u.id = r.user_id
GROUP BY u.id
ORDER BY SUM(r.distance) DESC, name;