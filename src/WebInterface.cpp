#include "WebInterface.h"

#include "Logger.h"

std::string IsapiWebRequest::name() const
{
   return "ISAPI";
}

void IsapiWebRequest::load(const std::string &xml)
{
   LOG_CONSOLE("Loading isapiweb: %s", xml.c_str());
}

std::string CrowWebRequest::name() const
{
   return "Crow";
}

void CrowWebRequest::load(const std::string &xml)
{
   LOG_CONSOLE("Loading crow: %s", xml.c_str());
}
