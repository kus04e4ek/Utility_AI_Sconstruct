#ifndef UtilityAINQSSearchSpaces_H_INCLUDED
#define UtilityAINQSSearchSpaces_H_INCLUDED 

//#include "UtilityAINodeQuerySystem.h"
#include "../UtilityAI.h"
#include <godot_cpp/classes/node.hpp>
#include "../SearchCriteria/UtilityAINQSSearchCriteria.h"



namespace godot {

class UtilityAINQSSearchSpaces : public UtilityAI { //NodeQuerySystem {
    GDCLASS(UtilityAINQSSearchSpaces, UtilityAI) //NodeQuerySystem)

private:
    int                 _top_n_to_find;
    unsigned int        _current_criterion_index;
    unsigned int        _current_node_index;
    bool                _is_query_still_running;
    TypedArray<Node>    _query_results;
    PackedFloat64Array  _query_result_scores;
    //double              _query_time_budget_per_frame_sec;
    //uint64_t            _query_time_budget_per_frame_usec;
    uint64_t            _total_query_runtime_usec;
    unsigned int        _total_query_node_visits;
    //double              _total_query_runtime_sec;
    TypedArray<Node>    _search_space;
    PackedFloat64Array  _scores;
    unsigned int        _num_search_space_nodes;
    TypedArray<Node>    _work_in_progress_search_space;
    PackedFloat64Array  _work_in_progress_scores;
    unsigned int        _work_in_progress_num_added_nodes;

    TypedArray<Node>*   _ptr_current_search_space;
    TypedArray<Node>*   _ptr_current_work_in_progress_search_space;
    PackedFloat64Array* _ptr_current_scores;
    PackedFloat64Array* _ptr_current_work_in_progress_scores;

    TypedArray<UtilityAINQSSearchCriteria> _filtering_criteria;
protected:
    static void _bind_methods();
    virtual void _initialize_search_space(){}

    void apply_criterion(   UtilityAINQSSearchCriteria* criterion, 
                            TypedArray<Node> search_space, 
                            PackedFloat64Array scores, 
                            TypedArray<Node>& result_space, 
                            PackedFloat64Array& result_scores );
    bool apply_criterion_with_time_budget( UtilityAINQSSearchCriteria* criterion,
                            uint64_t start_time_usec, 
                            uint64_t time_budget_usec );

    void place_to_query_results_based_on_score( Node* node, double score );
public:
    UtilityAINQSSearchSpaces();
    ~UtilityAINQSSearchSpaces();
    
    
    // Getters and setters.

    virtual TypedArray<Node> get_searchspace_nodes() const;
    
    void set_query_results(TypedArray<Node> query_results);
    TypedArray<Node> get_query_results() const;

    void set_query_result_scores(PackedFloat64Array query_result_scores);
    PackedFloat64Array get_query_result_scores() const;

    
    void set_top_n_to_find( int top_n_to_find );
    int  get_top_n_to_find() const;

    void set_total_query_runtime_usec( int total_query_runtime_usec );
    int  get_total_query_runtime_usec() const;

    void set_total_query_node_visits( int total_query_node_visits );
    int  get_total_query_node_visits() const;

    // Handling methods.

    void initialize_search_space();

    virtual bool execute_query(uint64_t time_budget_usec = 0 );

    //void apply_criterion( UtilityAISearchCriteria* criteria, TypedArray<Node> search_space, TypedArray<double> current_scores, TypedArray<Node>& result_space, TypedArray<double>& result_scores );
    
    // Godot virtuals.
    void _ready();
};

}


#endif 
