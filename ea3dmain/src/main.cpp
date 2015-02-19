#include <iostream>
#include "Ea3dPlatform.hpp"

#define BOOST_LOG_DYN_LINK 1
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/keywords/format.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <string.h>
#include <boost/log/support/date_time.hpp>
#define FILE (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
void initLogging() {
	namespace logging = boost::log;
	namespace keywords = boost::log::keywords;
	namespace expr = boost::log::expressions;
	boost::log::register_simple_formatter_factory<
			boost::log::trivial::severity_level, char>("Severity");

	// set log level
	logging::core::get()->set_filter(
			logging::trivial::severity >= logging::trivial::debug);

	// set formatter v2
	logging::add_console_log(std::cout,
			keywords::format = (expr::stream
					<< expr::format_date_time<boost::posix_time::ptime>(
							"TimeStamp", "%Y-%m-%d %H:%M:%S") << ": <"
					<< logging::trivial::severity << "> " << expr::smessage));
	logging::add_common_attributes();
}

int main(int argc, const char **argv) {
	initLogging();
	Ea3dPlatform myPlatform(640, 480);
	myPlatform.initPlatform();
	myPlatform.render();
	exit(EXIT_SUCCESS);
}
