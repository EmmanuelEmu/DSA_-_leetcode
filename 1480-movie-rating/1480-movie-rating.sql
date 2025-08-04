# Write your MySQL query statement below
SELECT results FROM (
    SELECT name AS results, 1 as query_order
    FROM Users AS usr
    JOIN (
        SELECT user_id, COUNT(user_id) as rating_count
        FROM MovieRating
        GROUP BY user_id
        ORDER BY COUNT(user_id) DESC, user_id ASC
    ) AS highestUser ON highestUser.user_id = usr.user_id
    ORDER BY highestUser.rating_count DESC, name ASC
    LIMIT 1
) AS user_result

UNION ALL

SELECT results FROM (
    SELECT mv.title AS results, 2 as query_order
    FROM Movies AS mv
    JOIN (
        SELECT movie_id, AVG(rating) AS avgRating
        FROM MovieRating
        WHERE created_at LIKE '2020-02%'
        GROUP BY movie_id
    ) AS ratedMovies ON mv.movie_id = ratedMovies.movie_id
    ORDER BY ratedMovies.avgRating DESC, mv.title ASC
    LIMIT 1
) AS movie_result;
