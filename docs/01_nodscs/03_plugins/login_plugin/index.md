## Description

The `login_plugin` supports the concept of applications authenticating with the lcscs blockchain. The `login_plugin` API allows an application to verify whether an account is allowed to sign in order to satisfy a specified authority.

## Usage

```console
# config.ini
plugin = lcscs::login_plugin
[options]
```
```sh
# command-line
nodscs ... --plugin lcscs::login_plugin [options]
```

## Options

These can be specified from both the `nodscs` command-line or the `config.ini` file:

```console
Config Options for lcscs::login_plugin:
  --max-login-requests arg (=1000000)   The maximum number of pending login 
                                        requests
  --max-login-timeout arg (=60)         The maximum timeout for pending login 
                                        requests (in seconds)
```

## Dependencies

* [`chain_plugin`](../chain_plugin/index.md)
* [`http_plugin`](../http_plugin/index.md)

### Load Dependency Examples

```console
# config.ini
plugin = lcscs::chain_plugin
[options]
plugin = lcscs::http_plugin 
[options]
```
```sh
# command-line
nodscs ... --plugin lcscs::chain_plugin [options]  \
           --plugin lcscs::http_plugin [options]
```
