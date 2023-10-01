#ifndef UtilityAISensors_H_INCLUDED
#define UtilityAISensors_H_INCLUDED 

#include "UtilityAI.h"
#include <godot_cpp/classes/node.hpp>



namespace godot {

class UtilityAISensors : public UtilityAI {
    GDCLASS(UtilityAISensors, UtilityAI)

private:
    
    double _sensor_value;
    
protected:
    static void _bind_methods();

public:
    UtilityAISensors();
    ~UtilityAISensors();
    
    
    // Getters and setters for attributes.
    
    
    void set_sensor_value( double sensor_value );
    double get_sensor_value() const;

    virtual double evaluate_sensor_value();
 
    /**
    
    // Godot virtuals.
    void _ready();
    void _process(double delta);
    void _physics_process(double delta);

    void _notification(int p_what);

    // Handling functions.

    bool _change_to_state( String target_state_name );

    void _update_current_state(double delta);
    */
};

}


#endif 