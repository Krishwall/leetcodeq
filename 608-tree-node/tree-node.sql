# Write your MySQL query statement below

SELECT id,  
CASE
WHEN p_id is null then 'Root'
WHEN id in (Select DISTINCT p_id FROM Tree) then 'Inner'
else 'Leaf'
end as type
FROM Tree