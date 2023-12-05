#include "UtilityAIBTRepeater.h"
#include "UtilityAIBehaviourTreeNodes.h"
#include "../UtilityAISensors.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/time.hpp>


using namespace godot;

// Method binds.

void UtilityAIBTRepeater::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_repeat_times", "repeat_times"), &UtilityAIBTRepeater::set_repeat_times);
    ClassDB::bind_method(D_METHOD("get_repeat_times"), &UtilityAIBTRepeater::get_repeat_times);
    ADD_PROPERTY(PropertyInfo(Variant::INT, "repeat_times", PROPERTY_HINT_RANGE, "-1,100,or_greater"), "set_repeat_times","get_repeat_times");

//    ClassDB::bind_method(D_METHOD("set_tick_result", "tick_result"), &UtilityAIBTRepeater::set_tick_result);
//    ClassDB::bind_method(D_METHOD("get_tick_result"), &UtilityAIBTRepeater::get_tick_result);
//    ADD_PROPERTY(PropertyInfo(Variant::INT, "tick_result", PROPERTY_HINT_ENUM, "Running:0,Success:1,Failure:-1" ), "set_tick_result","get_tick_result");

}


// Constructor and destructor.

UtilityAIBTRepeater::UtilityAIBTRepeater() {
    _repeat_times = 3;
    _current_repeat_times = -1;
}


UtilityAIBTRepeater::~UtilityAIBTRepeater() {
}


// Getters and Setters.


void UtilityAIBTRepeater::set_repeat_times( int repeat_times ) {
    _repeat_times = repeat_times;
}

int UtilityAIBTRepeater::get_repeat_times() const {
    return _repeat_times;
}


/**
void UtilityAIBTRepeater::set_tick_result( int tick_result ) {
    _tick_result = tick_result;
    if( _tick_result > 1 ) {
        _tick_result = 1;
    } else if (_tick_result < -1 ) {
        _tick_result = -1;
    }
}


int  UtilityAIBTRepeater::get_tick_result() const {
    return _tick_result;
}
/**/


// Handling functions.


int UtilityAIBTRepeater::tick(Variant user_data, double delta) { 
    if( !get_is_active() ) return BT_FAILURE;
    if( Engine::get_singleton()->is_editor_hint() ) return BT_FAILURE;
    if( _repeat_times == 0 ){
        set_internal_status(BT_INTERNAL_STATUS_COMPLETED);
        set_tick_result(BT_SUCCESS);
        return BT_SUCCESS;
    }
    if( get_internal_status() == BT_INTERNAL_STATUS_COMPLETED ) {
        set_tick_result(BT_SUCCESS);
        return BT_SUCCESS;
    } 

    if( get_internal_status() == BT_INTERNAL_STATUS_UNTICKED ) {
        _current_repeat_times = _repeat_times;
    }
    set_internal_status(BT_INTERNAL_STATUS_TICKED);

    for( int i = 0; i < get_child_count(); ++i ) {
        if( UtilityAIBehaviourTreeNodes* btnode = godot::Object::cast_to<UtilityAIBehaviourTreeNodes>(get_child(i)) ) {
            if( !btnode->get_is_active() ) {
                continue;
            } 
            --_current_repeat_times;
            btnode->tick(user_data, delta);
            if( _current_repeat_times < 0 ) {
                btnode->reset();
            }
            break;
        }
    }
    if( _current_repeat_times > 0 || _current_repeat_times < 0 ) {
        set_tick_result(BT_RUNNING);
        return BT_RUNNING;
    } else if (_current_repeat_times == 0 ) {
        set_internal_status(BT_INTERNAL_STATUS_COMPLETED);
        set_tick_result(BT_SUCCESS);
        return BT_SUCCESS;
    }
    set_internal_status(BT_INTERNAL_STATUS_COMPLETED);
    set_tick_result(BT_FAILURE);
    return BT_FAILURE;
}


