
#include "Configure.hpp"

void configurationSpecification(Configuration &config)
{
    config.ASSIGN(TranslateInclude::YES);

    DSC<CppSourceTarget> &lib = config.GetCppStaticDSC("lib");
    lib.getSourceTarget().assignStandardIncludesToPublicHUDirectories();

    config.GetCppExeDSC("app").PRIVATE_LIBRARIES(&lib).getSourceTarget().MODULE_FILES("std.ixx");
}

void buildSpecification()
{
    Configuration &exception = GetConfiguration("exception");
    exception.ASSIGN(ExceptionHandling::ON);

    Configuration &noException = GetConfiguration("no-exception");
    noException.ASSIGN(ExceptionHandling::OFF);

    configurationSpecification(exception);
    configurationSpecification(noException);
}

MAIN_FUNCTION