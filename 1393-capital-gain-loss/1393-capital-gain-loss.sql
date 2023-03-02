# Write your MySQL query statement below
select stock_name,SUM(CASE WHEN operation = 'Sell' then price ELSE -price END) as capital_gain_loss from Stocks group by stock_name;