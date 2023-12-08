#ifndef UtilityAIBTRunNQSQuery_H_INCLUDED
#define UtilityAIBTRunNQSQuery_H_INCLUDED 

#include "UtilityAIBTTaskNodes.h"
#include <godot_cpp/classes/node.hpp>
#include "../NodeQuerySystem/SearchSpaces/UtilityAINQSSearchSpaces.h"

#define QS_IDLE         0
#define QS_RUNNING      1
#define QS_COMPLETED    2

namespace godot {

class UtilityAIBTRunNQSQuery : public UtilityAIBTTaskNodes {
    GDCLASS(UtilityAIBTRunNQSQuery, UtilityAIBTTaskNodes)

private:
    NodePath _nqs_search_space_node_path;
    UtilityAINQSSearchSpaces* _nqs_search_space_node;
    int _time_budget_usec;
    int _top_n_to_find;

    int _query_state;
protected:
    static void _bind_methods();

public:
    UtilityAIBTRunNQSQuery();
    ~UtilityAIBTRunNQSQuery();
    
    
    // Getters and setters for attributes.
        
    void set_nqs_search_space_node_path( NodePath nqs_search_space_node_path );
    NodePath get_nqs_search_space_node_path() const;

    void set_time_budget_usec( int time_budget_usec );
    int  get_time_budget_usec() const;

    void set_top_n_to_find( int top_n_to_find );
    int  get_top_n_to_find() const;


    // Handling functions.
    virtual void reset_bt_node() override;
    virtual int tick(Variant user_data, double delta) override;

    // Godot virtuals.

    void _ready();
    void _physics_process(float delta );
    //void _exit_tree();
};

}


#endif 
