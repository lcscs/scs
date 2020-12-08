#include <lcscs/chain/webassembly/scs-vm-oc.hpp>
#include <lcscs/chain/wasm_lcscs_constraints.hpp>
#include <lcscs/chain/wasm_lcscs_injection.hpp>
#include <lcscs/chain/apply_context.hpp>
#include <lcscs/chain/exceptions.hpp>

#include <vector>
#include <iterator>

namespace lcscs { namespace chain { namespace webassembly { namespace scsvmoc {

class scsvmoc_instantiated_module : public wasm_instantiated_module_interface {
   public:
      scsvmoc_instantiated_module(const digest_type& code_hash, const uint8_t& vm_version, scsvmoc_runtime& wr) :
         _code_hash(code_hash),
         _vm_version(vm_version),
         _scsvmoc_runtime(wr)
      {

      }

      ~scsvmoc_instantiated_module() {
         _scsvmoc_runtime.cc.free_code(_code_hash, _vm_version);
      }

      void apply(apply_context& context) override {
         const code_descriptor* const cd = _scsvmoc_runtime.cc.get_descriptor_for_code_sync(_code_hash, _vm_version);
         scs_ASSERT(cd, wasm_execution_error, "scs VM OC instantiation failed");

         _scsvmoc_runtime.exec.execute(*cd, _scsvmoc_runtime.mem, context);
      }

      const digest_type              _code_hash;
      const uint8_t                  _vm_version;
      scsvmoc_runtime&               _scsvmoc_runtime;
};

scsvmoc_runtime::scsvmoc_runtime(const boost::filesystem::path data_dir, const scsvmoc::config& scsvmoc_config, const chainbase::database& db)
   : cc(data_dir, scsvmoc_config, db), exec(cc) {
}

scsvmoc_runtime::~scsvmoc_runtime() {
}

std::unique_ptr<wasm_instantiated_module_interface> scsvmoc_runtime::instantiate_module(const char* code_bytes, size_t code_size, std::vector<uint8_t> initial_memory,
                                                                                     const digest_type& code_hash, const uint8_t& vm_type, const uint8_t& vm_version) {

   return std::make_unique<scsvmoc_instantiated_module>(code_hash, vm_type, *this);
}

//never called. scs VM OC overrides lcscs_exit to its own implementation
void scsvmoc_runtime::immediately_exit_currently_running_module() {}

}}}}
