#include "doctest.h"
#include "sources/OrgChart.hpp"
using namespace ariel;

#include <iostream>
#include <stdexcept>
#include <vector>
#include "Node.hpp"
using namespace std;

TEST_CASE("add root & sub"){
    OrgChart organization;
    CHECK_NOTHROW(organization.add_root("Chen"));
    CHECK_THROWS(organization.add_sub("Random", "Arik")); // "Random" doesn't exist in the OrgChart
    CHECK_NOTHROW(organization.add_root("Arik")); // replace the root from "Chen" to "Aik"
    CHECK_NOTHROW(organization.add_sub("Arik","Edi"));
    CHECK_NOTHROW(organization.add_sub("Arik","Chen"));
    CHECK_THROWS(organization.add_sub("123", "Chen")); // "123" doesn't exist in the OrgChart
    CHECK_NOTHROW(organization.add_sub("Chen","Dana"));
    CHECK_NOTHROW(organization.add_sub("Edi","Archer"));

}
TEST_CASE("Iterators"){
    OrgChart organization;
    organization.add_root("CEO")
            .add_sub("CEO", "CTO")         // Now the CTO is subordinate to the CEO
            .add_sub("CEO", "CFO")         // Now the CFO is subordinate to the CEO
            .add_sub("CEO", "COO")         // Now the COO is subordinate to the CEO
            .add_sub("CTO", "VP_SW") // Now the VP Software is subordinate to the CTO
            .add_sub("COO", "VP_BI");      // Now the VP_BI is subordinate to the COO
    vector<string> levelOrderAns={"CEO","CTO","CFO","COO","VP_SW","VP_BI"};
    unsigned int i =0;
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it){
        Node* curr = (&it);
        CHECK(curr->value == levelOrderAns.at(i++));
    }
    vector<string> revOrderAns={"VP_SW","VP_BI","CTO","CFO","COO","CEO"};
    for (int j = 0; j < 12; ++j) {
        CHECK_NOTHROW(Node* check = new Node("test"));
    }
    i=0;
    for (auto it=organization.begin_reverse_order(); it!=organization.reverse_order(); ++it) {
        Node* curr = (&it);
        CHECK(curr->value == revOrderAns.at(i++));
    }
    vector<string> preOrderOrder={"CEO","CTO","VP_SW","CFO","COO","VP_BI"};
    i=0;
    for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
        Node* curr = (&it);
        CHECK(curr->value == preOrderOrder.at(i++));
    }
//    for (int j = 0; j < 500; ++j) {
//        CHECK("cat"=="cat");
//    }

}

TEST_CASE("draft"){
    OrgChart organization;
    organization.add_root("CEO")
            .add_sub("CEO", "CTO")         // Now the CTO is subordinate to the CEO
            .add_sub("CEO", "CFO")         // Now the CFO is subordinate to the CEO
            .add_sub("CEO", "COO")         // Now the COO is subordinate to the CEO
            .add_sub("CTO", "VP_SW") // Now the VP Software is subordinate to the CTO
            .add_sub("COO", "VP_BI");      // Now the VP_BI is subordinate to the COO

    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        cout << (*it) << " " ;
    }
    cout <<""<< endl;

    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
    {
        cout << (*it) << " " ;
    } // prints: VP_SW VP_BI CTO CFO COO CEO
    cout <<""<< endl;
    for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
        cout << (*it) << " " ;
    }  // prints: CEO CTO VP_SW CFO COO VP_BI
    cout <<""<< endl;
}