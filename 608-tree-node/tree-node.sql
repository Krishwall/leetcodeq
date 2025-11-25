# Write your MySQL query statement below

SELECT id,  
case 
when p_id is null then 'Root'
when id in (Select DISTINCT p_id FROM Tree) then 'Inner'
else 'Leaf'
end as type
from Tree