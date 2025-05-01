SELECT c.category, 
       COUNT(a.category) AS accounts_count
FROM (
    SELECT 'Low Salary' AS category
    UNION ALL
    SELECT 'Average Salary'
    UNION ALL
    SELECT 'High Salary'
) AS c
LEFT JOIN (
    SELECT CASE
             WHEN income < 20000 THEN 'Low Salary'
             WHEN income BETWEEN 20000 AND 50000 THEN 'Average Salary'
             ELSE 'High Salary'
           END AS category
    FROM Accounts
) AS a
ON c.category = a.category
GROUP BY c.category;
