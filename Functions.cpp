#include  "Header.h"

void del_vector_obj(vector<CLO>& clo_list, const CLO& clo) {
    string target_id = clo.getCloId();
    auto it = find_if(clo_list.begin(), clo_list.end(), [&target_id](const CLO& obj) {
        return obj.getCloId() == target_id;
    });
    if (it != clo_list.end()) {
        clo_list.erase(it); 
    }
}

void del_vector_ptr(vector<Evaluation*>& evaluations_list, const Evaluation& evaluation) {
    string id = evaluation.get_ID();
    auto it = find_if(evaluations_list.begin(), evaluations_list.end(), [&id](const Evaluation* evalPtr) {
        return evalPtr->get_ID() == id;
    });
    if (it != evaluations_list.end()) {
        *(*it) = evaluation;
    }
}
