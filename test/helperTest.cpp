//
//  helperTest.cpp
//  libscratchpad
//
//  Created by Alex Seifert on 26.03.18.
//  Copyright © 2018 Alex Seifert. All rights reserved.
//

#define BOOST_TEST_MODULE Helper

#include <boost/test/unit_test.hpp>

#include "../src/Helper.h"

BOOST_AUTO_TEST_SUITE(helperSuite);

BOOST_AUTO_TEST_CASE(copyFolder)
{
    BOOST_CHECK(Helper::copyFolder("test", "test") == 1);
}

BOOST_AUTO_TEST_SUITE_END();
