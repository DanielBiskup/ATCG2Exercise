//
// Created by alex on 19.11.20.
//

#include "bcg_hierarchy_system.h"
#include "bcg_viewer_state.h"
#include "bcg_entity_hierarchy.h"

namespace bcg {

hierarchy_system::hierarchy_system(viewer_state *state) : system("hierarchy_system", state) {
    state->dispatcher.sink<event::hierarchy::set_parent>().connect<&hierarchy_system::on_set_parent>(this);
    state->dispatcher.sink<event::hierarchy::add_child>().connect<&hierarchy_system::on_add_child>(this);
    state->dispatcher.sink<event::hierarchy::remove_child>().connect<&hierarchy_system::on_remove_child>(this);
}

void hierarchy_system::on_set_parent(const event::hierarchy::set_parent &event) {
    if(!state->scene.valid(event.id)) return;
    if(!state->scene.has<entity_hierarchy>(event.id)){
        state->scene.emplace<entity_hierarchy>(event.id);
    }
    auto &hierarchy = state->scene.get<entity_hierarchy>(event.id);
    hierarchy.parent = event.parent_id;

    auto &model = state->scene.get<Transform>(event.id);
    auto &parent_hierarchy = state->scene.get<entity_hierarchy>(hierarchy.parent);
    hierarchy.accumulated_model = parent_hierarchy.accumulated_model * model;
}

void hierarchy_system::on_add_child(const event::hierarchy::add_child &event) {
    if(!state->scene.valid(event.id)) return;
    if(!state->scene.has<entity_hierarchy>(event.id)){
        state->scene.emplace<entity_hierarchy>(event.id);
    }
    auto &hierarchy = state->scene.get<entity_hierarchy>(event.id);
    hierarchy.children[event.child_id] = event.child_id;
}

void hierarchy_system::on_remove_child(const event::hierarchy::remove_child &event) {
    if(!state->scene.valid(event.id)) return;
    if(!state->scene.has<entity_hierarchy>(event.id)){
        state->scene.emplace<entity_hierarchy>(event.id);
    }
    auto &hierarchy = state->scene.get<entity_hierarchy>(event.id);
    auto iter = hierarchy.children.find(event.child_id);
    if(iter != hierarchy.children.end()){
        auto &child_hierarchy = state->scene.get<entity_hierarchy>(event.child_id);
        if(child_hierarchy.parent == event.id){
            state->dispatcher.trigger<event::hierarchy::set_parent>(event.child_id, entt::null);
        }
        hierarchy.children.erase(iter);
    }
}

void hierarchy_system::update_accumulated_model(entt::entity id){
    auto &hierarchy = state->scene.get<entity_hierarchy>(id);
    auto &model = state->scene.get<Transform>(id);
    hierarchy.accumulated_model = model;
    if(hierarchy.parent == entt::null){
        hierarchy.accumulated_model = model;
    }else{
        auto &parent_hierarchy = state->scene.get<entity_hierarchy>(hierarchy.parent);
        hierarchy.accumulated_model = parent_hierarchy.accumulated_model * model;
    }
    for(const auto item : hierarchy.children){
        update_accumulated_model(item.second);
    }
}

void hierarchy_system::on_update(const event::internal::update &event){
    auto view = state->scene.view<entity_hierarchy, Transform>();
    for(const auto id : view){
        auto &hierarchy = state->scene.get<entity_hierarchy>(id);
        if(hierarchy.parent == entt::null){
            update_accumulated_model(id);
        }
    }
}

}