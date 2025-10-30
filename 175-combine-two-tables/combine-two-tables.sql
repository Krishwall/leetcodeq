# Write your MySQL query statement below

Select firstName,lastName,city,state FROM Person left join Address ON Person.personId =
 Address.personId;