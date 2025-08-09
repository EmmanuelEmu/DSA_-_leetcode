WITH actor_director_collab AS (
    SELECT actor_id, director_id, COUNT(`timestamp`) AS cnt
    FROM ActorDirector
    GROUP BY actor_id, director_id
)

SELECT actor_id, director_id
FROM actor_director_collab
WHERE cnt >= 3;