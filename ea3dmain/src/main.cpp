
#include <iostream>
#include "Ea3dPlatform.hpp"

#define BOOST_LOG_DYN_LINK 1
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks.hpp>

void initLogging() {

    typedef boost::log::sinks::synchronous_sink<boost::log::sinks::text_ostream_backend> text_sink;
    //    boost::shared_ptr< text_sink > sink = boost::make_shared< text_sink >();
    std::shared_ptr<text_sink> sink = std::make_shared<text_sink>();
    //    boost::log::core::get()->set_filter(boost::log::trivial::severity >=
    //    boost::log::trivial::debug);
}
// boost::log::core::get()->set_filter(boost::log::trivial::severity >= boost::log::trivial::debug);
int main(int argc, const char **argv) {
    initLogging();
    Ea3dPlatform myPlatform(640, 480);
    myPlatform.initPlatform();
    myPlatform.render();
    exit(EXIT_SUCCESS);
}
