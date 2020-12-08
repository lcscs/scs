#include "version_impl.hpp"

namespace lcscs { namespace version {

   const std::string& version_client() {
      static const std::string version{_version_client()};
      return version;
   }

   const std::string& version_full() {
      static const std::string version{_version_full()};
      return version;
   }

} }
