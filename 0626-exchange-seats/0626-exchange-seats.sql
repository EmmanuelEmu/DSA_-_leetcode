SELECT id,
    CASE 
        WHEN MOD(id,2)=0 THEN LAG(student,1) OVER()
        ELSE COALESCE(LEAD(student,1) OVER(), student)
    END as student
FROM Seat