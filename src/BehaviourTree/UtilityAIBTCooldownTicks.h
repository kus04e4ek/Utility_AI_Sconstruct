#ifndef UtilityAIBTCooldownTicks_H_INCLUDED
#define UtilityAIBTCooldownTicks_H_INCLUDED 

#include "UtilityAIBehaviourTreeNodes.h"
#include <godot_cpp/classes/node.hpp>



namespace godot {

class UtilityAIBTCooldownTicks : public UtilityAIBehaviourTreeNodes {
    GDCLASS(UtilityAIBTCooldownTicks, UtilityAIBehaviourTreeNodes)

private:
    
    int _cooldown_ticks;
    int _current_cooldown_ticks;

    int _cooldown_return_value;
    
protected:
    static void _bind_methods();

public:
    UtilityAIBTCooldownTicks();
    ~UtilityAIBTCooldownTicks();
    
    
    // Getters and setters for attributes.
        
    void set_cooldown_ticks( int cooldown_ticks );
    int  get_cooldown_ticks() const;

    void set_current_cooldown_ticks( int cooldown_ticks );
    int  get_current_cooldown_ticks() const;

    void set_cooldown_return_value( int cooldown_return_value );
    int  get_cooldown_return_value() const;

    // Handling functions.

    virtual int tick(Variant user_data, double delta) override;
};

}


#endif 