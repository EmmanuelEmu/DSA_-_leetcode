WITH modified AS (
	SELECT *, SUBSTRING_INDEX(mail, '@', 1) AS prefix
	FROM Users
	WHERE SUBSTRING(mail, 1, 1) BETWEEN 'a' AND 'z'
	AND mail LIKE BINARY '%@leetcode.com'
    AND (LENGTH(mail) - LENGTH(REPLACE(mail, '@', ''))) = 1
)
SELECT md.user_id, md.name, md.mail
FROM modified AS md
WHERE md.prefix REGEXP '^[a-zA-Z][a-zA-Z0-9._\\-]*$';
