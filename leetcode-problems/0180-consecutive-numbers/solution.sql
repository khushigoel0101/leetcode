# Write your MySQL query statement below
-- Step 1: Compute window values inside the CTE
WITH NamedLogs AS (
    SELECT 
        num,
        LEAD(num, 1) OVER (ORDER BY id) AS next_1,
        LEAD(num, 2) OVER (ORDER BY id) AS next_2
    FROM Logs
)
-- Step 2: Query the CTE like a normal table
SELECT DISTINCT num AS ConsecutiveNums
FROM NamedLogs
WHERE num = next_1 AND next_1 = next_2;
