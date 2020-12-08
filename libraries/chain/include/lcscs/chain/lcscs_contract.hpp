#pragma once

#include <lcscs/chain/types.hpp>
#include <lcscs/chain/contract_types.hpp>

namespace lcscs { namespace chain {

   class apply_context;

   /**
    * @defgroup native_action_handlers Native Action Handlers
    */
   ///@{
   void apply_lcscs_newaccount(apply_context&);
   void apply_lcscs_updateauth(apply_context&);
   void apply_lcscs_deleteauth(apply_context&);
   void apply_lcscs_linkauth(apply_context&);
   void apply_lcscs_unlinkauth(apply_context&);

   /*
   void apply_lcscs_postrecovery(apply_context&);
   void apply_lcscs_passrecovery(apply_context&);
   void apply_lcscs_vetorecovery(apply_context&);
   */

   void apply_lcscs_setcode(apply_context&);
   void apply_lcscs_setabi(apply_context&);

   void apply_lcscs_canceldelay(apply_context&);
   ///@}  end action handlers

} } /// namespace lcscs::chain
