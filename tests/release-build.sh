#!/bin/bash
# test name and purpose
echo ''
echo '                         ##### Release Build Test #####'
echo ''
echo '    The purpose of this test is to ensure that nodscs was built with compiler'
echo 'optimizations enabled. While there is no way to programmatically determine that'
echo 'given one binary, we do set a debug flag in nodscs when it is built with'
echo 'asserts. This test checks that debug flag. Anyone intending to build and install'
echo 'nodscs from source should perform a "release build" which excludes asserts and'
echo 'debugging symbols, and performs compiler optimizations.'
echo ''
# check for jq
if ! $(jq --version 1>/dev/null); then
    echo 'ERROR: Test requires jq, but jq was not found in your PATH!'
    echo ''
    exit 1
fi
# find nodscs
[[ $(git --version) ]] && cd "$(git rev-parse --show-toplevel)/build/programs/nodscs" || cd "$(dirname "${BASH_SOURCE[0]}")/../programs/nodscs"
if [[ ! -f nodscs ]]; then
    echo 'ERROR: nodscs binary not found!'
    echo ''
    echo 'I looked here...'
    echo "$ ls -la \"$(pwd)/programs/nodscs\""
    ls -la "$(pwd)/programs/nodscs"
    echo '...which I derived from one of these paths:'
    echo '$ echo "$(git rev-parse --show-toplevel)/build"'
    echo "$(git rev-parse --show-toplevel)/build"
    echo '$ echo "$(dirname "${BASH_SOURCE[0]}")/.."'
    echo "$(dirname "${BASH_SOURCE[0]}")/.."
    echo 'Release build test not run.'
    exit 1
fi
# run nodscs to generate state files
./nodscs --extract-build-info build-info.json 1>/dev/null 2>/dev/null
if [[ ! -f build-info.json ]]; then
    echo 'ERROR: Build info JSON file not found!'
    echo ''
    echo 'Looked in the following places:'
    echo "$ ls -la \"$(pwd)\""
    ls -la "$(pwd)"
    echo 'Release build test not run.'
    exit 2
fi
# test state files for debug flag
if [[ "$(cat build-info.json | jq .debug)" == 'false' ]]; then
    echo 'PASS: Debug flag is not set.'
    echo ''
    rm build-info.json
    exit 0
fi
echo 'FAIL: Debug flag is set!'
echo ''
echo '$ cat build-info.json | jq .'
cat build-info.json | jq .
rm build-info.json
exit 3