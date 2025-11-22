--Most visited Floor
with cte as grouped_ids(
    Select name , sum(floor) as total_floors_visted, max(count(floors)) as most_visited_floor,
    `distict(resources) from employees group by name 
)[]