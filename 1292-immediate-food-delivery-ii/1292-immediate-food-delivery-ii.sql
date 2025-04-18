# Write your MySQL query statement below
WITH FirstOrders AS (
    SELECT customer_id, MIN(order_date) AS first_order_date
    FROM Delivery
    GROUP BY customer_id
)
SELECT 
    ROUND(
        (COUNT(DISTINCT CASE WHEN d.order_date = d.customer_pref_delivery_date THEN d.customer_id END) * 100.0) / 
        COUNT(DISTINCT fo.customer_id), 
        2
    ) AS immediate_percentage
FROM Delivery d
JOIN FirstOrders fo ON d.customer_id = fo.customer_id
WHERE d.order_date = fo.first_order_date
