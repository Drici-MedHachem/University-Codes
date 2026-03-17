USE ECOMMERCEG5A;


SELECT  COUNT(total_amount) AS total_amount , SUM(total_amount) AS total_sales 
FROM order_table
WHERE total_amount > 100;   