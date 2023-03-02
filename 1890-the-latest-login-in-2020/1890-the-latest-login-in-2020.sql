# Write your MySQL query statement below
select user_id, max(time_stamp) as last_stamp from Logins where year(time_Stamp)=2020 group by user_id ;