/**
 * AUTHORS: or yitshak
 *
 * Date: 2022-03
 */

#include "doctest.h"
#include "sources/OrgChart.hpp"
#include "sources/Node.hpp"

using namespace ariel;

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


TEST_CASE("Good input")
{
    OrgChart og;
    og.add_root("CEO")
        .add_sub("CEO", "CTO")         // Now the CTO is subordinate to the CEO
        .add_sub("CEO", "CFO")         // Now the CFO is subordinate to the CEO
        .add_sub("CEO", "COO")         // Now the COO is subordinate to the CEO
        .add_sub("CTO", "VP_SW") // Now the VP Software is subordinate to the CTO
        .add_sub("COO", "VP_BI");      // Now the VP_BI is subordinate to the COO
    // cout<<og._root._name;
    // cout << *(og._root);
    CHECK_EQ(og.getRoot() == "CEO",true);
    CHECK_EQ(og.getChildren("CEO").size() == 3 ,true);
    CHECK_EQ(og.getChildren("CTO").size() == 1 ,true);
    CHECK_EQ(og.getChildren("CFO").size() == 0 ,true);
    CHECK_EQ(og.getChildren("COO").size() == 1 ,true);
    CHECK_EQ(og.getChildren("VP_SW").size() == 0 ,true);
    CHECK_EQ(og.getChildren("VP_BI").size() == 0 ,true);

    CHECK_NOTHROW(og.getChildren("CEO").at(0));
    CHECK_NOTHROW(og.getChildren("CEO").at(1));
    CHECK_NOTHROW(og.getChildren("CEO").at(2));
    CHECK_NOTHROW(og.getChildren("CTO").at(0));
    CHECK_NOTHROW(og.getChildren("COO").at(0));
    


    CHECK_EQ(og.getChildren("CEO").at(0) == "CTO" ,true);
    CHECK_EQ(og.getChildren("CEO").at(1) == "CFO" ,true);
    CHECK_EQ(og.getChildren("CEO").at(2) == "COO" ,true);
    CHECK_EQ(og.getChildren("CTO").at(0) == "VP_SW" ,true);
    CHECK_EQ(og.getChildren("COO").at(0) == "VP_BI" ,true);
    
}

TEST_CASE("bad input")
{
    OrgChart og;
    og.add_root("CEO")
        .add_sub("CEO", "CTO")         // Now the CTO is subordinate to the CEO
        .add_sub("CEO", "CFO")         // Now the CFO is subordinate to the CEO
        .add_sub("CEO", "COO")         // Now the COO is subordinate to the CEO
        .add_sub("CTO", "VP_SW") // Now the VP Software is subordinate to the CTO
        .add_sub("COO", "VP_BI");
    // CHECK_THROWS(og.add_root(2));
    // CHECK_THROWS(og.add_sub("CEO", 5));
    CHECK_THROWS(og.add_sub("shmuel","COO"));
    CHECK_THROWS(og.add_sub("CEO","CEO"));
    CHECK_THROWS(og.add_sub("CTO","CEO"));
    CHECK_THROWS(og.add_sub("shmuel","COO"));
    CHECK_THROWS(og.add_sub("CTO", "VP_SW"));
   


}