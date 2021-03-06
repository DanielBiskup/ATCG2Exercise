//
// Created by alex on 17.11.20.
//

#include "bcg_gui_viewer_picker.h"
#include "bcg_viewer_state.h"

namespace bcg{

void gui_viewer_picker(viewer_state *state){
    if (ImGui::CollapsingHeader("Picker")) {
        draw_label(&state->window, "entity_id", std::to_string((unsigned int) state->picker.entity_id));
        draw_label(&state->window, "vertex_id", std::to_string(state->picker.vertex_id.idx));
        draw_label(&state->window, "edge_id", std::to_string(state->picker.edge_id.idx));
        draw_label(&state->window, "face_id", std::to_string(state->picker.face_id.idx));
        ImGui::Separator();
        std::stringstream ss;
        ss << state->picker.model_space_point.transpose();
        draw_label(&state->window, "model_space_point", ss.str());
        ss.str("");
        ss << state->picker.world_space_point.transpose();
        draw_label(&state->window, "world_space_point", ss.str());
        ss.str("");
        ss << state->picker.view_space_point.transpose();
        draw_label(&state->window, "view_space_point", ss.str());
        ImGui::Separator();
    }
}

}