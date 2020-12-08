## Goal

Connect to a specific `nodscs` or `kscsd` host to send COMMAND

`clscs` and `kscsd` can connect to a specific node by using the `--url` or `--wallet-url` optional arguments, respectively, followed by the http address and port number these services are listening to.

[[info | Default address:port]]
| If no optional arguments are used (i.e. `--url` or `--wallet-url`), `clscs` attempts to connect to a local `nodscs` or `kscsd` running at localhost `127.0.0.1` and default port `8888`.

## Before you begin

* Install the currently supported version of `clscs`

## Steps
### Connecting to Nodscs

```sh
clscs -url http://nodscs-host:8888 COMMAND
```

### Connecting to Kscsd

```sh
clscs --wallet-url http://kscsd-host:8888 COMMAND
```
