#pragma once

#include <lcscs/chain/webassembly/scs-vm-oc/config.hpp>

#include <boost/asio/local/datagram_protocol.hpp>
#include <lcscs/chain/webassembly/scs-vm-oc/ipc_helpers.hpp>

namespace lcscs { namespace chain { namespace scsvmoc {

wrapped_fd get_connection_to_compile_monitor(int cache_fd);

}}}