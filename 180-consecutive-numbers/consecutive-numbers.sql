/* Write your PL/SQL query statement below */

SELECT DISTINCT num as ConsecutiveNums from
(
    Select
    num,
    @count:= if(@prev = (@prev:=num),@count+1,1) as freq

    from Logs,(select @count:=0,@prev:=(select num from logs limit 1))as c

)  as n
where 
freq>2;