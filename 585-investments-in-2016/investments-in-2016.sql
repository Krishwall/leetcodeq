SELECT 
    ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM (
    SELECT 
        tiv_2016,
        COUNT(*) OVER (PARTITION BY lat, lon)    AS loc_cnt,
        COUNT(*) OVER (PARTITION BY tiv_2015)    AS tiv2015_cnt
    FROM Insurance
) AS t
WHERE 
    loc_cnt = 1
    AND tiv2015_cnt > 1;
