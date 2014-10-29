
#include <iostream>
#include "Ea3dPlatform.hpp"

#define BOOST_LOG_DYN_LINK 1
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>

void initLogging() {
    boost::log::core::get()->set_filter(boost::log::trivial::severity >= boost::log::trivial::debug);
}

int main(int argc, const char **argv) {
    initLogging();
    Ea3dPlatform myPlatform(640, 480);
    myPlatform.initPlatform();
    myPlatform.render();
    exit(EXIT_SUCCESS);
}
