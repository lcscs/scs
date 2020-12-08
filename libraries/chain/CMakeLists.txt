configure_file(${CMAKE_CURRENT_SOURCE_DIR}/include/lcscs/chain/core_symbol.hpp.in ${CMAKE_CURRENT_BINARY_DIR}/include/lcscs/chain/core_symbol.hpp)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/genesis_state_root_key.cpp.in ${CMAKE_CURRENT_BINARY_DIR}/genesis_state_root_key.cpp)

file(GLOB HEADERS "include/lcscs/chain/*.hpp"
                  "include/lcscs/chain/webassembly/*.hpp"
                  "${CMAKE_CURRENT_BINARY_DIR}/include/lcscs/chain/core_symbol.hpp" )

if(APPLE AND UNIX)
   set(PLATFORM_TIMER_IMPL platform_timer_macos.cpp)
else()
   try_run(POSIX_TIMER_TEST_RUN_RESULT POSIX_TIMER_TEST_COMPILE_RESULT ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/platform_timer_posix_test.c)
   if(POSIX_TIMER_TEST_RUN_RESULT EQUAL 0)
      set(PLATFORM_TIMER_IMPL platform_timer_posix.cpp)
      set(CHAIN_RT_LINKAGE rt)
   else()
      set(PLATFORM_TIMER_IMPL platform_timer_asio_fallback.cpp)
   endif()
endif()

if("scs-vm-oc" IN_LIST lcscs_WASM_RUNTIMES)
   set(CHAIN_scsVMOC_SOURCES webassembly/scs-vm-oc/code_cache.cpp
                             webassembly/scs-vm-oc/executor.cpp
                             webassembly/scs-vm-oc/memory.cpp
                             webassembly/scs-vm-oc/intrinsic.cpp
                             webassembly/scs-vm-oc/LLVMJIT.cpp
                             webassembly/scs-vm-oc/LLVMEmitIR.cpp
                             webassembly/scs-vm-oc/compile_monitor.cpp
                             webassembly/scs-vm-oc/compile_trampoline.cpp
                             webassembly/scs-vm-oc/ipc_helpers.cpp
                             webassembly/scs-vm-oc/gs_seg_helpers.c
                             webassembly/scs-vm-oc.cpp)

   if(LLVM_VERSION VERSION_LESS 7.1 AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
      enable_language(ASM-LLVMWAR)
      list(APPEND CHAIN_scsVMOC_SOURCES webassembly/scs-vm-oc/llvmWARshim.llvmwar)
   else()
      list(APPEND CHAIN_scsVMOC_SOURCES webassembly/scs-vm-oc/llvmWARshim.cpp)
   endif()

   llvm_map_components_to_libnames(LLVM_LIBS support core passes mcjit native orcjit)
   include_directories(${LLVM_INCLUDE_DIRS})
   add_definitions(${LLVM_DEFINITIONS})

   option(scsVMOC_ENABLE_DEVELOPER_OPTIONS "enable developer options for scs VM OC" OFF)
endif()

if("scs-vm" IN_LIST lcscs_WASM_RUNTIMES OR "scs-vm-jit" IN_LIST lcscs_WASM_RUNTIMES)
   set(CHAIN_scsVM_SOURCES "webassembly/scs-vm.cpp")
   set(CHAIN_scsVM_LIBRARIES scs-vm)
endif()

## SORT .cpp by most likely to change / break compile
add_library( lcscs_chain
             merkle.cpp
             name.cpp
             transaction.cpp
             block.cpp
             block_header.cpp
             block_header_state.cpp
             block_state.cpp
             fork_database.cpp
             controller.cpp
             authorization_manager.cpp
             resource_limits.cpp
             block_log.cpp
             transaction_context.cpp
             lcscs_contract.cpp
             lcscs_contract_abi.cpp
             lcscs_contract_abi_bin.cpp
             chain_config.cpp
             chain_id_type.cpp
             genesis_state.cpp
             ${CMAKE_CURRENT_BINARY_DIR}/genesis_state_root_key.cpp

#             chain_config.cpp
#             block_trace.cpp
              wast_to_wasm.cpp
              wasm_interface.cpp
              wasm_lcscs_validation.cpp
              wasm_lcscs_injection.cpp
              apply_context.cpp
              abi_serializer.cpp
              asset.cpp
              snapshot.cpp

             webassembly/wabt.cpp
             ${CHAIN_scsVMOC_SOURCES}
             ${CHAIN_scsVM_SOURCES}

#             get_config.cpp
#
#             contracts/chain_initializer.cpp

             trace.cpp
             transaction_metadata.cpp
             protocol_state_object.cpp
             protocol_feature_activation.cpp
             protocol_feature_manager.cpp
             producer_schedule.cpp
             genesis_intrinsics.cpp
             whitelisted_intrinsics.cpp
             thread_utils.cpp
             platform_timer_accuracy.cpp
             ${PLATFORM_TIMER_IMPL}
             ${HEADERS}
             )

target_link_libraries( lcscs_chain fc chainbase Logging IR WAST WASM Runtime
                       softfloat builtins wabt ${CHAIN_scsVM_LIBRARIES} ${LLVM_LIBS} ${CHAIN_RT_LINKAGE}
                     )
target_include_directories( lcscs_chain
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" "${CMAKE_CURRENT_BINARY_DIR}/include"
                                   "${CMAKE_CURRENT_SOURCE_DIR}/../wasm-jit/Include"
                                   "${CMAKE_CURRENT_SOURCE_DIR}/libraries/scs-vm/include"
                                   "${CMAKE_SOURCE_DIR}/libraries/wabt"
                                   "${CMAKE_BINARY_DIR}/libraries/wabt"
                            )

if("scs-vm-oc" IN_LIST lcscs_WASM_RUNTIMES)
   target_link_libraries(lcscs_chain "-Wl,-wrap=main")
endif()

foreach(RUNTIME ${lcscs_WASM_RUNTIMES})
   string(TOUPPER "${RUNTIME}" RUNTIMEUC)
   string(REPLACE "-" "_" RUNTIMEUC ${RUNTIMEUC})
   target_compile_definitions(lcscs_chain PUBLIC "lcscs_${RUNTIMEUC}_RUNTIME_ENABLED")
endforeach()

if(scsVMOC_ENABLE_DEVELOPER_OPTIONS)
   message(WARNING "scs VM OC Developer Options are enabled; these are NOT supported")
   target_compile_definitions(lcscs_chain PUBLIC lcscs_scs_VM_OC_DEVELOPER)
endif()

install( TARGETS lcscs_chain
   RUNTIME DESTINATION ${CMAKE_INSTALL_FULL_BINDIR}
   LIBRARY DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
   ARCHIVE DESTINATION ${CMAKE_INSTALL_FULL_LIBDIR}
)
install( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/lcscs/chain/
      DESTINATION ${CMAKE_INSTALL_FULL_INCLUDEDIR}/lcscs/chain
      FILES_MATCHING PATTERN "*.hpp" PATTERN "*.h" EXCLUDE
)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/include/lcscs/chain/core_symbol.hpp DESTINATION ${CMAKE_INSTALL_FULL_INCLUDEDIR}/lcscs/chain)
#if(MSVC)
#  set_source_files_properties( db_init.cpp db_block.cpp database.cpp block_log.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
#endif(MSVC)
