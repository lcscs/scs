## Description
Retrieve accounts which are servants of a given account 

## Info

**Command**

```sh
clscs get servants
```
**Output**

```console
Usage: clscs get servants account

Positionals:
  account TEXT                The name of the controlling account
```

## Command

```sh
clscs get servants inita
```

## Output

```json
{
  "controlled_accounts": [
    "tester"
  ]
}
```
