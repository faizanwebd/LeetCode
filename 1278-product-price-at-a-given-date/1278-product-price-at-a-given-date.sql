WITH latest_prices AS (
  SELECT
    product_id,
    new_price,
    ROW_NUMBER() OVER (PARTITION BY product_id ORDER BY change_date DESC) AS rn
  FROM Products
  WHERE change_date <= '2019-08-16'
)

SELECT
  p.product_id,
  COALESCE(lp.new_price, 10) AS price
FROM
  (SELECT DISTINCT product_id FROM Products) p
LEFT JOIN latest_prices lp
  ON p.product_id = lp.product_id AND lp.rn = 1;
