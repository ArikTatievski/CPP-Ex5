#include "doctest.h"
#include "sources/OrgChart.hpp"
using namespace ariel;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

TEST_CASE("add root & sub"){
    OrgChart organization;
    CHECK_NOTHROW(organization.add_root("Chen"));
    CHECK_THROWS(organization.add_sub("Random", "Arik")); // "Random" doesn't exist in the OrgChart
    CHECK_NOTHROW(organization.add_root("Arik")); // replace the root from "Chen" to "Aik"
    CHECK_NOTHROW(organization.add_sub("Arik","Edi"));
    CHECK_NOTHROW(organization.add_sub("Chen","CEO"));

}
//TEST_CASE("Iterators"){
//    OrgChart organization;
//    organization.add_root("CEO")
//            .add_sub("CEO", "CTO")         // Now the CTO is subordinate to the CEO
//            .add_sub("CEO", "CFO")         // Now the CFO is subordinate to the CEO
//            .add_sub("CEO", "COO")         // Now the COO is subordinate to the CEO
//            .add_sub("CTO", "VP_SW") // Now the VP Software is subordinate to the CTO
//            .add_sub("COO", "VP_BI");      // Now the VP_BI is subordinate to the COO
//
//
//    auto it = organization.begin_level_order();
//            CHECK((*it) == "CEO");
//    it++;
//            CHECK((*it) == "CTO");
////    it++;
//            CHECK((*it) == "CFO");
////    it++;
//            CHECK((*it) == "COO");
////    it++;
//            CHECK((*it) == "VP_SW");
////    it++;
//            CHECK((*it) == "VP_BI");
////    it++;
////    CHECK((*it) == nullptr);
//
//    auto rev_it = organization.begin_reverse_order();
//            CHECK((*rev_it) == "VP_SW");
////    rev_it++;
//            CHECK((*rev_it) == "VP_BI");
////    rev_it++;
//            CHECK((*rev_it) == "CTO");
////    rev_it++;
//            CHECK((*rev_it) == "CFO");
////    rev_it++;
//            CHECK((*rev_it) == "COO");
////    rev_it++;
//            CHECK((*rev_it) == "CEO");
////    rev_it++;
////    CHECK((*rev_it) == nullptr);
//
//    auto pre_it = organization.begin_preorder();
//            CHECK((*pre_it) == "CEO");
////    pre_it++;
//            CHECK((*pre_it) == "CTO");
////    pre_it++;
//            CHECK((*pre_it) == "VP_SW");
////    pre_it++;
//            CHECK((*pre_it) == "CFO");
////    pre_it++;
//            CHECK((*pre_it) == "COO");
////    pre_it++;
//            CHECK((*pre_it) == "VP_BI");
////    pre_it++;
////    CHECK((*pre_it) == nullptr);

