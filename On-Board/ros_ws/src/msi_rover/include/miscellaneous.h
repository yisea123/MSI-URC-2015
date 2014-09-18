#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <msi_rover.h>
#include <string>

namespace Misc
{
  inline bool file_exists (const std::string& name)
  {
    if (FILE *file = fopen(name.c_str(), "r"))
    {
      fclose(file);
      return true;
    }
    else
    {
      return false;
    }
  }

  void LoadXMLConfig(const std::string &filename, boost::property_tree::ptree& _config_tree)
  {
    boost::property_tree::read_xml( PACKAGE_PATH + filename, _config_tree );
  }
};
