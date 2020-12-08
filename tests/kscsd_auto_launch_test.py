#!/usr/bin/env python3

# This script tests that clscs launches kscsd automatically when kscsd is not
# running yet.

import subprocess


def run_clscs_wallet_command(command: str, no_auto_kscsd: bool):
    """Run the given clscs command and return subprocess.CompletedProcess."""
    args = ['./programs/clscs/clscs']

    if no_auto_kscsd:
        args.append('--no-auto-kscsd')

    args += 'wallet', command

    return subprocess.run(args,
                          check=False,
                          stdout=subprocess.DEVNULL,
                          stderr=subprocess.PIPE)


def stop_kscsd():
    """Stop the default kscsd instance."""
    run_clscs_wallet_command('stop', no_auto_kscsd=True)


def check_clscs_stderr(stderr: bytes, expected_match: bytes):
    if expected_match not in stderr:
        raise RuntimeError("'{}' not found in {}'".format(
            expected_match.decode(), stderr.decode()))


def kscsd_auto_launch_test():
    """Test that kscs auto-launching works but can be optionally inhibited."""
    stop_kscsd()

    # Make sure that when '--no-auto-kscsd' is given, kscsd is not started by
    # clscs.
    completed_process = run_clscs_wallet_command('list', no_auto_kscsd=True)
    assert completed_process.returncode != 0
    check_clscs_stderr(completed_process.stderr, b'Failed to connect to kscsd')

    # Verify that kscsd auto-launching works.
    completed_process = run_clscs_wallet_command('list', no_auto_kscsd=False)
    if completed_process.returncode != 0:
        raise RuntimeError("Expected that kscsd would be started, "
                           "but got an error instead: {}".format(
                               completed_process.stderr.decode()))
    check_clscs_stderr(completed_process.stderr, b'launched')


try:
    kscsd_auto_launch_test()
finally:
    stop_kscsd()
