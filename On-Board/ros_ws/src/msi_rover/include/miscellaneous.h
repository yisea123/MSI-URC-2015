#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <path.h>
#include <string>
#include <vector>

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
    boost::property_tree::read_xml( PATH + filename, _config_tree );
  }
};
