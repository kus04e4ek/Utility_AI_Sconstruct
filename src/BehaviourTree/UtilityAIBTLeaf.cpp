#include "UtilityAIBTLeaf.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>


using namespace godot;

// Method binds.

void UtilityAIBTLeaf::_bind_methods() {
    
    ClassDB::bind_method(D_METHOD("set_tick_result", "tick_result"), &UtilityAIBTLeaf::set_tick_result);
    ClassDB::bind_method(D_METHOD("get_tick_result"), &UtilityAIBTLeaf::get_tick_result);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "tick_result", PROPERTY_HINT_ENUM, "Running:0,Success:1,Failure:-1" ), "set_tick_result","get_tick_result");

}


// Constructor and destructor.

UtilityAIBTLeaf::UtilityAIBTLeaf() {
    _tick_result = 1;
}


UtilityAIBTLeaf::~UtilityAIBTLeaf() {
}


// Getters and Setters.

void UtilityAIBTLeaf::set_tick_result( int tick_result ) {
    _tick_result = tick_result;
}


int  UtilityAIBTLeaf::get_tick_result() const {
    return _tick_result;
}

// Handling methods.

int UtilityAIBTLeaf::tick(Variant user_data, double delta) { 
    if( has_method("tick")) {
        call("tick", user_data, delta);
    }
    return _tick_result;
}


