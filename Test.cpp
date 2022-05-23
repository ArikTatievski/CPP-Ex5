#include "doctest.h"
#include "OrgChart.hpp"
using namespace ariel;
TEST_CASE("add root & sub"){
    OrgChart organization;
    CHECK_NOTHROW(organization.add_root("Chen"));
    CHECK_THROWS(organization.add_sub("Random", "Arik")); // "Random" doesn't exist in the OrgChart
    CHECK_NOTHROW(organization.add_root("Arik")); // replace the root from "Chen" to "Aik"
    CHECK_NOTHROW(organization.add_sub("Arik","Edi"));
    CHECK_NOTHROW(organization.add_sub("Arik","Chen"));
    CHECK_THROWS(organization.add_sub("123", "Chen")); // "123" doesn't exist in the OrgChart
    CHECK_NOTHROW(organization.add_sub("Chen","Dana"));
    CHECK_NOTHROW(organization.add_sub("Chen","Adi"));
    CHECK_NOTHROW(organization.add_sub("Edi","Archer"));
    CHECK_NOTHROW(organization.add_sub("Edi","Shaf"));
}
TEST_CASE("Operator Check"){
    OrgChart org;
    CHECK_THROWS_MESSAGE(org.add_sub("tal", "renana"), "can't add sub before root");
    CHECK_NOTHROW(org.add_root("dana"));
    CHECK_NOTHROW(org.add_root("shir"));
    CHECK_NOTHROW(org.add_sub("shir", "tal"));
    CHECK_THROWS_MESSAGE(org.add_sub("adi", "sapir"), "employer doesn't exist");
    CHECK_NOTHROW(org.add_sub("shir", "sapir"));
    CHECK_NOTHROW(org.add_sub("sapir", "dan"));
    CHECK_NOTHROW(org.add_sub("dan", "ziv"));
    CHECK_NOTHROW(org.add_sub("tal", "avi"));
    CHECK_NOTHROW(org.add_sub("tal", "yossi"));
    CHECK_NOTHROW(org.add_sub("shir", "ido"));
    CHECK_NOTHROW(org.add_sub("ziv", "shaked"));
    CHECK_NOTHROW(org.add_sub("ziv", "ofer"));
    std::vector<std::string> v = {"shir", "tal", "sapir", "ido", "avi", "yossi", "dan", "ziv", "shaked", "ofer"};
    size_t i = 0;
    for(auto it = org.begin_level_order(); it != org.end_level_order(); ++it){
                CHECK_EQ(*it, v.at(i++));
    }
    std::vector<std::string> v2 = {"shaked", "ofer", "ziv", "avi", "yossi", "dan", "tal", "sapir", "ido", "shir"};
    i = 0;
    for(auto it = org.begin_reverse_order(); it != org.reverse_order(); ++it){
                CHECK_EQ(*it, v2.at(i++));
    }
    std::vector<std::string> v3 = {"shir", "tal", "avi", "yossi", "sapir", "dan", "ziv", "shaked", "ofer", "ido"};
    i = 0;
    for(auto it = org.begin_preorder(); it != org.end_preorder(); ++it){
                CHECK_EQ(*it, v3.at(i++));
    }
}
