#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
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

  std::vector<std::string> getenv_vector(const std::string &env_variable)
  {
    std::string env_str = getenv(env_variable.c_str());
    std::vector<std::string> env_vect;

    size_t previous = 0;
    size_t index = env_str.find(":");
    while( index != std::string::npos )
    {
        env_vect.push_back( env_str.substr(previous, index-previous) );
        previous = index + 1;
        index    = env_str.find(":", previous);
    }
    env_vect.push_back( env_str.substr(previous) );
    return env_vect;
  }

  void LoadXMLConfig(const std::string &filename, boost::property_tree::ptree& _config_tree)
  {
    std::vector<std::string> _env_vector = getenv_vector("ROS_PACKAGE_PATH");
    std::string _config_file;
    for(std::vector<std::string>::iterator it = _env_vector.begin(); it != _env_vector.end(); ++it)
    {
      if ( file_exists ( *it + filename ) )
      {
        _config_file = *it + filename;
        break;
      }
    }
    boost::property_tree::read_xml(_config_file, _config_tree);
  }
};
