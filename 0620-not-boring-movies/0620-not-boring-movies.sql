# Write your MySQL query statement below
SELECT 
    * 
FROM 
    Cinema
WHERE 
    id % 2 = 1  -- Odd-numbered IDs
    AND description != 'boring'
ORDER BY 
    rating DESC;
