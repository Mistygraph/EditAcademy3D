
#include <iostream>
#include "Ea3dPlatform.hpp"

#define BOOST_LOG_DYN_LINK 1
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/keywords/format.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

#include <string.h>

#define FILE (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
void initLogging() {
    namespace logging = boost::log;
    namespace keywords = boost::log::keywords;
    namespace src = boost::log::sources;
    namespace sinks = boost::log::sinks;
    
    boost::log::register_simple_formatter_factory< boost::log::trivial::severity_level, char >("Severity");

    // set log level
    logging::core::get()->set_filter(logging::trivial::severity >= logging::trivial::debug);
    
    
    // set formatter
    logging::add_console_log(std::cout, keywords::format = "[%TimeStamp%](%Severity%): %Message%");
    
    logging::add_common_attributes();
    using namespace logging::trivial;
    src::severity_logger< severity_level > lg;
    BOOST_LOG_SEV(lg, debug) << FILE;
    BOOST_LOG_SEV(lg, debug) << __LINE__;
    BOOST_LOG_SEV(lg, info) << "An informational severity message";
    BOOST_LOG_SEV(lg, warning) << "A warning severity message";
    BOOST_LOG_SEV(lg, error) << "An error severity message";
    BOOST_LOG_SEV(lg, fatal) << "A fatal severity message";
}

int main(int argc, const char **argv) {
    initLogging();
    Ea3dPlatform myPlatform(640, 480);
    myPlatform.initPlatform();
    myPlatform.render();
    exit(EXIT_SUCCESS);
}
