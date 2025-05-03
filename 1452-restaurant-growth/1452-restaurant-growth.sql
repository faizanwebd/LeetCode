SELECT 
    b.visited_on,
    SUM(d.amount) AS amount,
    ROUND(SUM(d.amount) / 7, 2) AS average_amount
FROM (
    SELECT visited_on, SUM(amount) AS amount
    FROM Customer
    GROUP BY visited_on
) d
JOIN (
    SELECT DISTINCT visited_on
    FROM Customer
) b
ON d.visited_on BETWEEN DATE_SUB(b.visited_on, INTERVAL 6 DAY) AND b.visited_on
GROUP BY b.visited_on
HAVING COUNT(*) = 7
ORDER BY b.visited_on;
