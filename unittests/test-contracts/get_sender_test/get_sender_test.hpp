#pragma once

#include <lcscs/lcscs.hpp>

namespace lcscs {
   namespace internal_use_do_not_use {
      extern "C" {
         __attribute__((lcscs_wasm_import))
         uint64_t get_sender();
      }
   }
}

namespace lcscs {
   name get_sender() {
      return name( internal_use_do_not_use::get_sender() );
   }
}

class [[lcscs::contract]] get_sender_test : public lcscs::contract {
public:
   using lcscs::contract::contract;

   [[lcscs::action]]
   void assertsender( lcscs::name expected_sender );
   using assertsender_action = lcscs::action_wrapper<"assertsender"_n, &get_sender_test::assertsender>;

   [[lcscs::action]]
   void sendinline( lcscs::name to, lcscs::name expected_sender );

   [[lcscs::action]]
   void notify( lcscs::name to, lcscs::name expected_sender, bool send_inline );

   // lcscs.cdt 1.6.1 has a problem with "*::notify" so hardcode to tester1 for now.
   // TODO: Change it back to "*::notify" when the bug is fixed in lcscs.cdt.
   [[lcscs::on_notify("tester1::notify")]]
   void on_notify( lcscs::name to, lcscs::name expected_sender, bool send_inline );

};
