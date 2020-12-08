---
content_title: Nodscs Configuration
---

The plugin-specific options can be configured using either CLI options or a configuration file, `config.ini`. Nodscs-specific options can only be configured from the command line. All CLI options and `config.ini` options can be found by running `nodscs --help` as shown above.

Each `config.ini` option has a corresponding CLI option. However, not all CLI options are available in `config.ini`. For instance, most plugin-specific options that perform actions are not available in `config.ini`, such as `--delete-state-history` from `state_history_plugin`.

For example, the CLI option `--plugin lcscs::chain_api_plugin` can also be set by adding `plugin = lcscs::chain_api_plugin` in `config.ini`.

## `config.ini` location

The default `config.ini` can be found in the following folders:
- Mac OS: `~/Library/Application Support/lcscs/nodscs/config`
- Linux: `~/.local/share/lcscs/nodscs/config`

A custom `config.ini` file can be set by passing the `nodscs` option `--config path/to/config.ini`.

## Nodscs Example

The example below shows a typical usage of `nodscs` when starting a block producing node:

```sh
nodscs --replay-blockchain \
  -e -p lcscs \
  --plugin lcscs::producer_plugin  \
  --plugin lcscs::chain_api_plugin \
  --plugin lcscs::http_plugin      \
  >> nodscs.log 2>&1 &
```

```sh
nodscs \
  -e -p lcscs \
  --data-dir /users/mydir/lcscs/data     \
  --config-dir /users/mydir/lcscs/config \
  --plugin lcscs::producer_plugin      \
  --plugin lcscs::chain_plugin         \
  --plugin lcscs::http_plugin          \
  --plugin lcscs::state_history_plugin \
  --contracts-console   \
  --disable-replay-opts \
  --access-control-allow-origin='*' \
  --http-validate-host=false        \
  --verbose-http-errors             \
  --state-history-dir /shpdata \
  --trace-history              \
  --chain-state-history        \
  >> nodscs.log 2>&1 &
```

The above `nodscs` command starts a producing node by:

* enabling block production (`-e`)
* identifying itself as block producer "lcscs" (`-p`)
* setting the blockchain data directory (`--data-dir`)
* setting the `config.ini` directory (`--config-dir`)
* loading plugins `producer_plugin`, `chain_plugin`, `http_plugin`, `state_history_plugin` (`--plugin`)
* passing `chain_plugin` options (`--contracts-console`, `--disable-replay-opts`)
* passing `http-plugin` options (`--access-control-allow-origin`, `--http-validate-host`, `--verbose-http-errors`)
* passing `state_history` options (`--state-history-dir`, `--trace-history`, `--chain-state-history`)
* redirecting both `stdout` and `stderr` to the `nodscs.log` file
* returning to the shell by running in the background (&)
