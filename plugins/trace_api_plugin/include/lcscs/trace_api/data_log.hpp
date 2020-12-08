#pragma once
#include <fc/variant.hpp>
#include <lcscs/trace_api/trace.hpp>
#include <lcscs/chain/abi_def.hpp>
#include <lcscs/chain/protocol_feature_activation.hpp>

namespace lcscs { namespace trace_api {

   using data_log_entry = fc::static_variant<
      block_trace_v0,
      block_trace_v1
   >;

}}
