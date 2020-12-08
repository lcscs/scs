---
content_title: Kscsd Troubleshooting
---

## How to solve the error "Failed to lock access to wallet directory; is another `kscsd` running"?

Since `clscs` may auto-launch an instance of `kscsd`, it is possible to end up with multiple instances of `kscsd` running. That can cause unexpected behavior or the error message above.

To fix this issue, you can terminate all running `kscsd` instances and restart `kscsd`. The following command will find and terminate all instances of `kscsd` running on the system:

```sh
pkill kscsd
```
