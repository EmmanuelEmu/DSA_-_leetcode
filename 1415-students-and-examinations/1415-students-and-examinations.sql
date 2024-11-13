SELECT 
    students.student_id AS student_id, 
    students.student_name, 
    subjects.subject_name, 
    COUNT(examinations.subject_name) AS attended_exams
FROM 
    (SELECT s.student_id, s.student_name 
     FROM Students AS s) AS students
CROSS JOIN 
    Subjects AS subjects
LEFT JOIN 
    Examinations AS examinations 
    ON students.student_id = examinations.student_id 
    AND subjects.subject_name = examinations.subject_name
GROUP BY 
    students.student_id, 
    students.student_name, 
    subjects.subject_name
ORDER BY 
    students.student_id, 
    students.student_name;
