#ifndef FLECS_DBG_H
#define FLECS_DBG_H

#ifdef __cplusplus
extern "C" {
#endif

/* Unstable API */

typedef struct ecs_dbg_entity_t {
    ecs_entity_t entity;
    ecs_table_t *table;
    ecs_type_t type;
    int32_t row;
    bool is_watched;
} ecs_dbg_entity_t;

typedef struct ecs_dbg_table_t {
    ecs_table_t *table;
    ecs_type_t type;
    ecs_type_t shared;
    ecs_type_t container;
    ecs_type_t parent_entities;
    ecs_type_t base_entities;     
    ecs_vector_t *systems_matched;
    ecs_entity_t *entities;
    int32_t entities_count;
} ecs_dbg_table_t;

typedef struct ecs_dbg_col_system_t {
    ecs_entity_t system;   
    int32_t entities_matched_count;
    int32_t active_table_count;
    int32_t inactive_table_count;
    bool enabled;
    void *system_data;
} ecs_dbg_col_system_t;

FLECS_EXPORT
void ecs_dbg_entity(
    ecs_world_t *world, 
    ecs_entity_t entity, 
    ecs_dbg_entity_t *dbg_out);

FLECS_EXPORT
ecs_table_t *ecs_dbg_find_table(
    ecs_world_t *world,
    ecs_type_t type);

FLECS_EXPORT
ecs_table_t *ecs_dbg_get_table(
    ecs_world_t *world,
    int32_t index);

FLECS_EXPORT
bool ecs_dbg_filter_table(
    ecs_world_t *world,
    ecs_table_t *table,
    ecs_filter_t *filter);

FLECS_EXPORT
void ecs_dbg_table(
    ecs_world_t *world, 
    ecs_table_t *table, 
    ecs_dbg_table_t *dbg_out);

FLECS_EXPORT
int ecs_dbg_col_system(
    ecs_world_t *world,
    ecs_entity_t system,
    ecs_dbg_col_system_t *dbg_out);

FLECS_EXPORT
ecs_table_t* ecs_dbg_get_active_table(
    ecs_world_t *world,
    ecs_dbg_col_system_t *dbg,
    int32_t index);

FLECS_EXPORT
ecs_table_t* ecs_dbg_get_inactive_table(
    ecs_world_t *world,
    ecs_dbg_col_system_t *dbg,
    int32_t index);

FLECS_EXPORT
ecs_type_t ecs_dbg_get_column_type(
    ecs_world_t *world,
    ecs_entity_t system,
    int32_t column_index);

FLECS_EXPORT
bool ecs_dbg_match_entity(
    ecs_world_t *world,
    ecs_entity_t entity,
    ecs_entity_t system,
    ecs_match_failure_t *failure_info_out);

#ifdef __cplusplus
}
#endif

#endif
